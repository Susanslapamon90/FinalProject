#include "process.h"
using namespace std;

enum commandList {LOGIN, CREATE, DELETE, MERGE, 
		  DEPOSIT, WITHDRAW, TRANSFER, FIND, SEARCH};
int findCommand(char *command){
	char commandString[10][10] = {"login", "create", "delete", "merge", 
		"deposit", "withdraw", "transfer", "find", "search","exit"};
	int i;
	for(i = 0; i < 9; i++)
        	if(strcmp(command, commandString[i]) == 0)
            		return i;
	if(strcmp(command,commandString[9]) == 0)
		exit(-1);
    return -1;
}

int main(int argc, char **argv){
	Customer<THistory>* USER_NOW = NULL;
	int TIME_CNT = 0; /* for history */
	char command[10];
	array<set<INDEX<THistory> >, 128> aset;	
	
//	for(int i = 0; i < 20614; i++){
//		scanf("%s",command);
	while(scanf("%s", command) != EOF){	
		switch(findCommand(command)){
            		case LOGIN:
            			processLogin(aset,&USER_NOW);
                		break;
            		case CREATE:
            			processCreate(aset);
                		break;
            		case DELETE:
                		processDelete(aset);
                		break;
            		case MERGE:
				processMerge(aset);
                		break;
            		case DEPOSIT:
                		processDeposit(USER_NOW);
				break;
			case WITHDRAW:
            			processWithdraw(USER_NOW);
                		break;
            		case TRANSFER:
            			processTransfer(USER_NOW,TIME_CNT,aset);
                		break;
            		case FIND:
            			processFind(USER_NOW,aset);
                		break;
            		case SEARCH:
            			processSearch(USER_NOW);
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
