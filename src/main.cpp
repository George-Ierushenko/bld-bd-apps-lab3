#include <iostream>
#include <memory>
#include "customer.h"
#include "element.h"
#include "sales_invoice.h"
#include "customer_repository.h"
#include "sales_invoice_repository.h"
#include <odb/mssql/database.hxx>
#include <odb/transaction.hxx>

int main()
{
  std::unique_ptr<odb::core::database> db(new odb::mssql::database("Driver={ODBC Driver 17 for SQL Server};Server=localhost;Database=WAB;Uid=sa;Pwd=pass!s@3d;"));

  CustomerRepository customer_repo(*db);
  SalesInvoiceRepository sales_invoice_repo(*db);

  auto customers = customer_repo.get_all();
  for (const auto &c : customers)
  {
    std::cout << "Customer: " << c->get_name() << ", Country: " << c->get_country() << ", Tax ID: " << c->get_tax_identification_number() << std::endl;
  }

  auto sales_invoices = sales_invoice_repo.get_all();
  for (const auto &si : sales_invoices)
  {
    std::cout << "Sales Invoice: " << si->get_document_number() << ", Date: " << si->get_created_date() << std::endl;
    std::cout << "Customer: " << si->get_customer()->get_name() << std::endl;
    std::cout << "Elements: " << std::endl;
    for (const auto &e : si->get_elements())
    {
      std::cout << "  - " << e->get_name() << ", Quantity: " << e->get_quantity() << ", Price: " << e->get_price() << ", VAT: " << e->get_vat_rate() << std::endl;
    }
  }

  return 0;
}
