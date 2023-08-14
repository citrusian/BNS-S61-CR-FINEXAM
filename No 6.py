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
  size = input("Ukuran Minuman (Kecil/Sedang/Besar): ")
  drink = Drink(size.capitalize())

  toppings = {
    "Bubble": Topping("Bubble", int(input("Jumlah Topping Bubble: "))),
    "Keju": Topping("Keju", int(input("Jumlah Topping Keju: "))),
    "Agar-Agar": Topping("Agar-Agar", int(input("Jumlah Topping Agar-Agar: ")))
  }

  CalculateandPrintOrder(drink, toppings)

def CalculateandPrintOrder(drink, toppings):
  drink_price = drink.calculate_price()
  topping_price = sum(topping.calculate_price() for topping in toppings.values())
  total_price = drink_price + topping_price

  clear()
  # https://docs.python.org/3.10/library/stdtypes.html?highlight=capitalize#str.capitalize
  # alt toupper
  print("Ukuran Minuman:", drink.size.capitalize())

  # Test Accesing individual item
  bubble_topping = toppings.get("Bubble")
  print("Topping Test", bubble_topping.name.capitalize(), ":", bubble_topping.quantity, "pcs")

  for topping in toppings.values():
    print("Topping ",topping.name.capitalize(), " : ", topping.quantity, " pcs")
  print(f"Total harga: Rp {total_price}")



def clear():
  print("\n" * 10)
# using loop newline because os.system("clear") doesn't work?

# menu conv c++ to python
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

# call main
main()
