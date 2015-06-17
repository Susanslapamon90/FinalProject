#include "customer.h"
using namespace std;

void processLogin(Set<INDEX>& idset,Customer* user_now);
void processCreate(Set<INDEX> &idset);
void processDelete(Set<INDEX> &idset);
void processMerge();
void processDeposit(Customer* user_now);
void processWithdraw(Customer* user_now);
void processTransfer(Customer* user_now,int &TIME_CNT);
void processFind(Customer* user_now);
void processSearch(Customer* user_now);
