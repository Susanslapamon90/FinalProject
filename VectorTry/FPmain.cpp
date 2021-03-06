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
	array<vector<INDEX<THistory> >, 128> idvec;		
//	for(int i = 0; i < 20614; i++){
//		scanf("%s",command);
	while(scanf("%s", command) != EOF){
		switch(int (command[3])){
            		case 105:
            			processLogin(idvec,&USER_NOW);
                		break;
            		case 97:
            			processCreate(idvec);
                		break;
            		case 101:
                		processDelete(idvec);
                		break;
            		case 103:
				processMerge(idvec);
                		break;
            		case 111:
                		processDeposit(USER_NOW);
				break;
			case 104:
            			processWithdraw(USER_NOW);
                		break;
            		case 110:
            			processTransfer(USER_NOW,TIME_CNT,idvec);
                		break;
			case 100:
            			processFind(USER_NOW,idvec);
                		break;
            		case 114:
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
