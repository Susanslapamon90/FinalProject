#include "customer.h"
using namespace std;

void processLogin(set<INDEX>& idset,Customer* user_now);
void processCreate(set<INDEX> &idset);
void processDelete(set<INDEX> &idset);
void processMerge(set<INDEX> &idset);
void processDeposit(Customer* user_now);
void processWithdraw(Customer* user_now);
void processTransfer(Customer* user_now, int &TIME_CNT, set<INDEX> &idset);
void processFind(Customer* user_now, set<INDEX> &idset);
void processSearch(Customer* user_now, set<INDEX> &idset);