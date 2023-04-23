#pragma db object
class SalesInvoice {
private:
  friend class odb::access;

  #pragma db id auto
  int id_;

  #pragma db column("CreatedDate")
  std::time_t created_date_;

  #pragma db column("DocumentNumber")
  std::string document_number_;

  #pragma db value_not_null inverse(elements_)
  std::vector<std::shared_ptr<Element>> elements_;

  #pragma db not_null
  std::shared_ptr<Customer> customer_;
};
