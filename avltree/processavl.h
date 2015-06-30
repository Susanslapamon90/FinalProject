#include "customer.h"
#include "history3.h"
extern "C"{
	#include "avl.h"
}
using namespace std;

typedef Customer<THistory> customer;

void processLogin(struct avl_table *avl,customer** user_now);
void processCreate(struct avl_table *avl);
void processDelete(struct avl_table *avl);
void processMerge(struct avl_table *avl);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, struct avl_table *avl);
void processFind(customer* user_now, struct avl_table *avl);
void processSearch(customer* user_now);

