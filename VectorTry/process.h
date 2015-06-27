#include "customer.h"
#include "history2.h"

using namespace std;

typedef array <vector<INDEX<THistory> >,128>  Vec;
typedef Customer<THistory> customer;

void processLogin(Vec &vec,customer** user_now);
void processCreate(Vec &vec);
void processDelete(Vec &vec);
void processMerge(Vec &vec);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, Vec &vec);
void processFind(customer* user_now, Vec &vec);
void processSearch(customer* user_now, Vec &vec);

