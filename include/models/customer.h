#pragma db object
class Customer {
private:
  friend class odb::access;

  #pragma db id auto
  int id_;

  #pragma db column("Name")
  std::string name_;

  #pragma db column("Country")
  std::string country_;

  #pragma db column("IsCompany")
  bool is_company_;

  #pragma db column("TaxIdentificationNumber")
  std::string tax_identification_number_;
};
