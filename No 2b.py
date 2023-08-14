def getPaymentData(payment_type, amount, client, client_email, transaction_id, address, transaction_date, item_name):
  print("Payment Type ", payment_type)
  print("Amount {:.3f}".format(amount))
  print("Client Name ", client)
  print("Client Mail ", client_email)
  print("Transaction ID ", transaction_id)
  print("Address ", address)
  print("transaction Date ", transaction_date)
  print("Product Description ", item_name)
  print("\n")


# Long Parameter
def process_payment(payment_type, amount, client, client_email, transaction_id, address, transaction_date, item_name):
  getPaymentData(payment_type, amount, client, client_email, transaction_id, address, transaction_date, item_name)


# Input & Process Output
process_payment("credit_card", 100.000, "John Doe", "john@test.com", "CCXXXX",
                "Test Addrrs 1", "2023-xx-xx", "Item 1")
process_payment("electronic_wallet", 101.000, "Jane Doe", "jane@test.com", "EWXXXX",
                "Test Addrrs 2", "2023-xx-xx", "Item 2")
process_payment("bank_transfer", 102.000, "John Jane", "test@test.com", "TRXXXX",
                "Test Addrrs 3", "2023-xx-xx", "Item 3")
