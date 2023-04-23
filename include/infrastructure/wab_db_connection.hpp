#include <SQLAPI.h>
#include <cstdlib>

#ifndef WABDBCONENCTION
#define WABDBCONENCTION

class WabDatabaseConnection {
  private:
    static SAConnection m_connection;
    static void init_connection();

  public:
    static SAConnection* get_connection();
};

#endif