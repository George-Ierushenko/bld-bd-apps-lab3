#include "sales_invoice-odb.hxx"

class SalesInvoiceRepository {
public:
  SalesInvoiceRepository(odb::core::database &db) : db_(db) {}

  void save(std::shared_ptr<SalesInvoice> &sales_invoice);
  std::vector<std::shared_ptr<SalesInvoice>> get_all();

private:
  odb::core::database &db_;
};
