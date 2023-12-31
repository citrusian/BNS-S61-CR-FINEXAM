import os
from abc import ABC, abstractmethod
# https://docs.python.org/3.10/library/abc.html - Abstract class
# https://docs.python.org/3.10/reference/datamodel.html?highlight=__init__#object.__new__ - Instance

class Beverage(ABC):
  def __init__(self, size):
    self.size = size

  @abstractmethod
  def calculate_price(self):
    pass

class Drink(Beverage):
  def __init__(self, size):
    super().__init__(size)

  def calculate_price(self):
    sizes = {"Kecil": 10000,
             "Sedang": 20000,
             "Besar": 30000}
    return sizes.get(self.size, 0)

class Topping(Beverage):
  def __init__(self, name, quantity):
    super().__init__(quantity)
    self.name = name
    self.quantity = quantity

  def calculate_price(self):
    return self.quantity * 2000

def OrderDrink():
  size = ValidateSizeInput()
  drink = Drink(size)

  toppings = {
    "Bubble": Topping("Bubble", ValidateToppingInput("Jumlah Topping Bubble: ")),
    "Keju": Topping("Keju", ValidateToppingInput("Jumlah Topping Keju: ")),
    "Agar-Agar": Topping("Agar-Agar", ValidateToppingInput("Jumlah Topping Agar-Agar: ")),
  }
  CalculateandPrintOrder(drink, toppings)

def ValidateSizeInput():
  while True:
    size = input("Ukuran Minuman (Kecil/Sedang/Besar): ").capitalize()
    if size in ["Kecil", "Sedang", "Besar"]:
      return size
    else:
      print("Input salah, masukan Kecil/Sedang/Besar.")

def ValidateToppingInput(prompt):
  while True:
    value = input(prompt)
    if value.isdigit():
      return int(value)
    else:
      print("Input salah, harus berupa angka. \nsilahkan masukan kembali")

def CalculateandPrintOrder(drink, toppings):
  drink_price = drink.calculate_price()
  topping_price = sum(topping.calculate_price() for topping in toppings.values())
  total_price = drink_price + topping_price

  clear()
  print("Ukuran Minuman:", drink.size.capitalize())

  for topping in toppings.values():
    print("Topping ",topping.name.capitalize(), " : ", topping.quantity, " pcs")
  print(f"Total harga: Rp {total_price}")

def clear():
  print("\n" * 10)

def main():
  print("Sistem POS Minuman \n")

  while True:
    print("1. Order Drink")
    print("0. Exit")
    choice = input("Select an option: ")
    clear()

    if choice == "0":
      print("Exit!")
      break

    elif choice == "1":
      OrderDrink()
      break

    else:
      print("Input Salah.")


main()
