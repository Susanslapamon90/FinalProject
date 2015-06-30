#include "processavl.h"
using namespace std;

int avlcmp(const void *pa, const void *pb, void *param){
	INDEX<THistory> *a = (INDEX<THistory> *)pa; INDEX<THistory> *b = (INDEX<THistory> *)pb;
	if(a->id < b->id)
		return 1;
	else if(a->id > b->id)
		return -1;
	else
		return 0;
}

int main(int argc, char **argv){
	Customer<THistory>* USER_NOW = NULL;
	int TIME_CNT = 0; /* for history */
	char command[10];
	struct avl_table *avl;
	avl = avl_create(avlcmp, NULL, NULL);
	
	while(scanf("%s", command) != EOF){	
		switch(command[0]){
            		case 'l':
            			processLogin(avl,&USER_NOW);
                		break;
            		case 'c':
            			processCreate(avl);
                		break;
            		case 'd':
            			if(command[2] == 'l')
                			processDelete(avl);
                		else
                			processDeposit(USER_NOW);
                		break;
            		case 'm':
						processMerge(avl);
                		break;
					case 'w':
            			processWithdraw(USER_NOW);
                		break;
            		case 't':
            			processTransfer(USER_NOW,TIME_CNT, avl);
                		break;
            		case 'f':
            			processFind(USER_NOW, avl);
                		break;
            		case 's':
            			processSearch(USER_NOW);
                		break;
			default:
				break;
        	}
	}
	return 0;
}

