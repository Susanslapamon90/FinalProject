#include "process.h"
using namespace std;

int rbcmp(const void *pa, const void *pb, void *param){
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
	struct rb_table *rb;
	rb = rb_create(rbcmp, NULL, NULL);
	
	while(scanf("%s", command) != EOF){	
		switch(command[0]){
            		case 'l':
            			processLogin(rb,&USER_NOW);
                		break;
            		case 'c':
            			processCreate(rb);
                		break;
            		case 'd':
            			if(command[2] == 'l')
                			processDelete(rb);
                		else
                			processDeposit(USER_NOW);
                		break;
            		case 'm':
						processMerge(rb);
                		break;
					case 'w':
            			processWithdraw(USER_NOW);
                		break;
            		case 't':
            			processTransfer(USER_NOW,TIME_CNT, rb);
                		break;
            		case 'f':
            			processFind(USER_NOW, rb);
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

