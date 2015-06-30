#include "customer.h"
#include "history2.h"
extern "C"{
	#include "rb.h"
}
using namespace std;

typedef Customer<THistory> customer;

void processLogin(struct rb_table *rb,customer** user_now);
void processCreate(struct rb_table *rb);
void processDelete(struct rb_table *rb);
void processMerge(struct rb_table *rb);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, struct rb_table *rb);
void processFind(customer* user_now, struct rb_table *rb);
void processSearch(customer* user_now);

