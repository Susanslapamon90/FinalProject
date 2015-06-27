#include "customer.h"
#include "history2.h"

using namespace std;

typedef array <set<INDEX<THistory> >,128>  Aset;
typedef Customer<THistory> customer;

void processLogin(Aset &aset,customer** user_now);
void processCreate(Aset &aset);
void processDelete(Aset &aset);
void processMerge(Aset &aset);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, Aset &aset);
void processFind(customer* user_now, Aset &aset);
void processSearch(customer* user_now);

