#include "repository/customer.h"
#include <odb/transaction.hxx>

void CustomerRepository::save(std::shared_ptr<Customer> &customer)
{
  odb::core::transaction t(db_.begin());
  db_.persist(customer);
  t.commit();
}

std::vector<std::shared_ptr<Customer>> CustomerRepository::get_all()
{
  odb::core::transaction t(db_.begin());
  odb::result<Customer> r(db_.query<Customer>());

  std::vector<std::shared_ptr<Customer>> customers;
  for (const auto &customer : r)
  {
    customers.push_back(std::make_shared<Customer>(customer));
  }
  t.commit();
  return customers;
}
