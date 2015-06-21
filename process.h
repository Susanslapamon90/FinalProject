#include "customer.h"
#include "history.h"

using namespace std;

typedef set<INDEX<THistory> > Set;
typedef Customer<THistory> customer;

void processLogin(Set &idset,customer* user_now);
void processCreate(Set &idset);
void processDelete(Set &idset);
void processMerge(Set &idset);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, Set &idset);
void processFind(customer* user_now, Set &idset);
void processSearch(customer* user_now, Set &idset);

