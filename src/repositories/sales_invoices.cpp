#include "repository/sales_invoice.h"
#include <odb/transaction.hxx>

void SalesInvoiceRepository::save(std::shared_ptr<SalesInvoice> &sales_invoice)
{
  odb::core::transaction t(db_.begin());
  db_.persist(sales_invoice);
  t.commit();
}

std::vector<std::shared_ptr<SalesInvoice>> SalesInvoiceRepository::get_all()
{
  odb::core::transaction t(db_.begin());
  odb::result<SalesInvoice> r(db_.query<SalesInvoice>());

  std::vector<std::shared_ptr<SalesInvoice>> sales_invoices;
  for (const auto &sales_invoice : r)
  {
    sales_invoices.push_back(std::make_shared<SalesInvoice>(sales_invoice));
  }
  t.commit();
  return sales_invoices;
}
