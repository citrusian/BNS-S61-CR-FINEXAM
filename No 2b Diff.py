# Combine Functions into Class using PaymentData
class PaymentData:
  def __init__(self, payment_type, amount, client, client_email, transaction_id, address, transaction_date, item_name):
    self.payment_type = payment_type
    self.amount = amount
    self.client = client
    self.client_email = client_email
    self.transaction_id = transaction_id
    self.address = address
    self.transaction_date = transaction_date
    self.item_name = item_name

  def ouput_Payment_Data(self):
    print("Payment Type ", self.payment_type)
    print("Amount {:.3f}".format(self.amount))
    print("Client Name ", self.client)
    print("Client Mail ", self.client_email)
    print("Transaction ID ", self.transaction_id)
    print("Address ", self.address)
    print("Transaction Date ", self.transaction_date)
    print("Product Description ", self.item_name)
    print("\n")

# Introduce Parameter Object
def process_payment(payment_data):
  payment_data.ouput_Payment_Data()

# Input
payment1 = PaymentData("credit_card", 100.000, "John Doe", "john@test.com", "CCXXXX",
                            "Test Address 1", "2023-xx-xx", "Item 1")
payment2 = PaymentData("electronic_wallet", 101.000, "Jane Doe", "jane@test.com", "EWXXXX",
                            "Test Address 2", "2023-xx-xx", "Item 2")
payment3 = PaymentData("bank_transfer", 102.000, "John Jane", "test@test.com", "TRXXXX",
                            "Test Address 3", "2023-xx-xx", "Item 3")

# Process data using objects
process_payment(payment1)
# process_payment(payment2)
# process_payment(payment3)
