#include "customer.h"
#include "history2.h"
#include "trie.h"

using namespace std;

typedef trie<INDEX<THistory> > Trie;
typedef Customer<THistory> customer;

void processLogin(Trie &idtrie,customer** user_now);
void processCreate(Trie &idtrie);
void processDelete(Trie &idtrie);
void processMerge(Trie &idtrie);
void processDeposit(customer* user_now);
void processWithdraw(customer* user_now);
void processTransfer(customer* user_now, int &TIME_CNT, Trie &id);
void processFind(customer* user_now, Trie &idtrie);
void processSearch(customer* user_now, Trie &idtrie);

