#include "customer-odb.hxx"

class CustomerRepository
{
public:
  CustomerRepository(odb::core::database &db) : db_(db) {}

  void save(std::shared_ptr<Customer> &customer);
  std::vector<std::shared_ptr<Customer>> get_all();

private:
  odb::core::database &db_;
};
