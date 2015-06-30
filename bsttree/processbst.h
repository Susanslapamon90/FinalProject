#include "customer.h"
#include "history3.h"
extern "C"{
	#include "bst.h"
}
using namespace std;

typedef Customer<THistory> customer;

void processLogin(struct bst_table *bst,customer** user_now);
void processCreate(struct bst_table *bst);
void processDelete(struct bst_table *bst);
void processMerge(struct bst_table *bst);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, struct bst_table *bst);
void processFind(customer* user_now, struct bst_table *bst);
void processSearch(customer* user_now);

