#include "customer.h"
#include "history2.h"

using namespace std;

typedef set<INDEX<THistory> > Set;
typedef map<string, Customer<THistory>* > Map;
typedef Customer<THistory> customer;

void processLogin(Map &idmap,customer** user_now);
void processCreate(Map &idmap);
void processDelete(Map &idmap);
void processMerge(Map &idmap);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, Map &idmap);
void processFind(customer* user_now, Map &idmap);
void processSearch(customer* user_now);