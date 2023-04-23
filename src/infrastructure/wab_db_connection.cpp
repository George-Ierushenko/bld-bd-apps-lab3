#include "./infrastructure/wab_db_connection.hpp"

void WabDatabaseConnection::init_connection() {
  m_connection.Connect(
    "WAB",
    std::getenv("DB_USER"),
    std::getenv("DB_PASS"),
    SA_SQLServer_Client
  );
}

SAConnection* WabDatabaseConnection::get_connection() {
  if (!m_connection.isConnected()) {
    init_connection();
  }

  return &m_connection;
}