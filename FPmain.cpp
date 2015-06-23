#include "process.h"
using namespace std;

enum commandList {LOGIN, CREATE, DELETE, MERGE, 
		  DEPOSIT, WITHDRAW, TRANSFER, FIND, SEARCH};
int findCommand(char *command){
	char commandString[9][10] = {"login", "create", "delete", "merge", 
		"deposit", "withdraw", "transfer", "find", "search"};
	int i;
	for(i = 0; i < 9; i++)
        	if(strcmp(command, commandString[i]) == 0)
            return i;
    return -1;
}

int main(int argc, char **argv){
	Customer<THistory>* USER_NOW = NULL;
	int TIME_CNT = 0; /* for history */
	char command[10];
	set<INDEX<THistory> > idset;
	
	while(1){
		scanf("%s", command);
		
		switch(findCommand(command)){
            		case LOGIN:
            			processLogin(idset,&USER_NOW);
                		break;
            		case CREATE:
            			processCreate(idset);
                		break;
            		case DELETE:
                		processDelete(idset);
                		break;
            		case MERGE:
				processMerge(idset);
                		break;
            		case DEPOSIT:
                		processDeposit(USER_NOW);
				break;
			case WITHDRAW:
            			processWithdraw(USER_NOW);
                		break;
            		case TRANSFER:
            			processTransfer(USER_NOW,TIME_CNT,idset);
                		break;
            		case FIND:
            			processFind(USER_NOW,idset);
                		break;
            		case SEARCH:
            			processSearch(USER_NOW,idset);
                		break;
			default:
				cout << "wrong command" << endl;
				break;
        	}
//		if(USER_NOW == NULL)
//			cout << "null now" <<endl;
	}
	return 0;
}
