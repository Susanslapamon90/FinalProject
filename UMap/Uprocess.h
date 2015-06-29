#include "customer.h"
#include "history2.h"

using namespace std;

typedef set<INDEX<THistory> > Set;
typedef map<string, Customer<THistory>* > Map;
typedef unordered_map<string, Customer<THistory>* > UMap;
typedef Customer<THistory> customer;

void processLogin(UMap &idumap,customer** user_now);
void processCreate(UMap &idumap);
void processDelete(UMap &idumap);
void processMerge(UMap &idumap);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, UMap &idumap);
void processFind(customer* user_now, UMap &idumap, const int cnt);
void processSearch(customer* user_now);