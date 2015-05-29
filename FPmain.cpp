#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*---------------*/
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>

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

void processLogin();
void processCreate();
void processDelete();
void processMerge();
void processDeposit();
void processWithdraw();
void processTransfer();
void processFind();
void processSearch();

int main(int argc, char **argv){
	

	/* Following is read in */
	while(/*read in function*/){
		/* tmp --DATA-- declaration*/
		/* push in */
	}
	// t2 = time(NULL);
	// printf("The reading time is %0d:%0d (min:sec)\n", (t2-t1)/60, (t2-t1)%60);

	char command[10];

	while(1){
		scanf("%s", command);
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