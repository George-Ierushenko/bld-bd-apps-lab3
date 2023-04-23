#pragma db object
class Element {
private:
  friend class odb::access;

  #pragma db id auto
  int id_;

  #pragma db column("Name")
  std::string name_;

  #pragma db column("Quantity")
  int quantity_;

  #pragma db column("Price")
  double price_;

  #pragma db column("VatRate")
  double vat_rate_;
};
