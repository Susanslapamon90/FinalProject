#include "main_function.h"
#include "process.h"
using namespace std;

enum commandList {LOGIN, CREATE, DELETE, MERGE, 
				DEPOSIT, WITHDRAW, TRANSFER, FIND, SEARCH};
int findCommand(char *command){
	char *commandString[9] = {"login", "create", "delete", "merge", 
							"deposit", "withdraw", "transfer", "find", "search"};
    int i;
    for(i = 0; i < 9; i++)
        if(strcmp(command, commandString[i]) == 0)
            return i;
    exit(-1);
}

int main(int argc, char **argv){
	
	// t2 = time(NULL);
	// printf("The reading time is %0d:%0d (min:sec)\n", (t2-t1)/60, (t2-t1)%60);

	char command[10];

	while(1){
		scanf("%s", command);
		/*if(strcmp(command, "exit") == 0
		 ||strcmp(command, "quit") == 0
		 ||strcmp(command, "bye") == 0
		 ||strcmp(command, "close") == 0){
			cout << "See you next time! Bye~" << endl;
			return 0;
		}*/ /* additional feature */
		switch(findCommand(command)){
            case LOGIN:
            	processLogin();
                break;
            case CREATE:
            	processCreate();
                break;
            case DELETE:
                processDelete();
                break;
            case MERGE:
            	processMerge();
                break;
            case DEPOSIT:
                processDeposit();
				break;
			case WITHDRAW:
            	processWithdraw();
                break;
            case TRANSFER:
            	processTransfer();
                break;
            case FIND:
            	processFind();
                break;
            case SEARCH:
            	processSearch();
                break;
        }
	}

	return 0;
}
