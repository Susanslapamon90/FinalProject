#include "2process.h"
using namespace std;

/*enum commandList {LOGIN, CREATE, DELETE, MERGE, 
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
}*/

int main(int argc, char **argv){
	Customer<THistory>* USER_NOW = NULL;
	int TIME_CNT = 0; /* for history */
	char command[10];
	set<INDEX<THistory> > idset;
	
//	for(int i = 0; i < 20614; i++){
//		scanf("%s",command);
	while(scanf("%s", command) != EOF){    
        switch(command[0]){
                    case 'l':
                        processLogin(idset,&USER_NOW);
                        break;
                    case 'c':
                        processCreate(idset);
                        break;
                    case 'd':
                        if(command[2] == 'l')
                            processDelete(idset);
                        else
                            processDeposit(USER_NOW);
                        break;
                    case 'm':
                        processMerge(idset);
                        break;
                     case 'w':
                        processWithdraw(USER_NOW);
                        break;
                    case 't':
                        processTransfer(USER_NOW,TIME_CNT,idset);
                        break;
                    case 'f':
                        processFind(USER_NOW,idset);
                        break;
                    case 's':
                        processSearch(USER_NOW);
                        break;
                     default:
                        cout << "wrong command" << endl;
                        break;
            }
    }
	return 0;
}
