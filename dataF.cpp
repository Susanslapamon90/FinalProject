#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

const string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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
		exit(1);
    return -1;
}

void gen_rand(int n, set<string> &stringset){
	while((int)stringset.size() < n){
		string s;
		s += table[rand() % 62];
		bool stop = false;
		while(!stop && s.size() <= 100){
			s += table[rand() % 62];
			if(rand() % 10 == 0) stop = true;
		}
		stringset.insert(s);
		s.clear();
	}
}

void printCreate(set<string> &stringset){
	int n;
	cin >> n;
	gen_rand(n, stringset);
	set<string>::iterator it;
	for(it = stringset.begin(); it != stringset.end(); it++)
		cout << "create " << *it <<" "<< *it << endl;
}

void printMerge(set<string> &stringset){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		set<string>::iterator it = stringset.begin();
		set<string>::iterator it2 = stringset.begin();
		int cnt = 1;
		while(1){
			it++;	cnt++;
			if(rand() % ((int)stringset.size()) == 0
				|| cnt == (int)stringset.size()) break;
		}
		cnt = 1;
		while(1){
			it2++;	cnt++;
			if(rand() % (int)stringset.size() == 0
				|| cnt == (int)stringset.size()) break;
		}
		cout << "merge " << *it <<" "<< *it <<" "<< *it2 <<" "<< *it2 << endl;
		stringset.erase(it2);
	}
}

void printDeposit(set<string> &stringset){
	int n, i;
	cin >> n;
	set<string>::iterator it;
	for(i = 0, it = stringset.begin(); i < n && it != stringset.end(); i++, it++){
		int money;
		money = rand() % 1000001;
		cout << "login " << *it <<" "<< *it << endl; 
		cout << "deposit " << money << endl;
	}
}

void printTransfer(set<string> &stringset){
	int n, i;
	cin >> n;
	set<string>::iterator it;

	for(int i = 0; i < n; i++){
		int money;
		money = rand() % 10001;
		set<string>::iterator it = stringset.begin();
		set<string>::iterator it2 = stringset.begin();
		int cnt = 1;
		while(1){
			it++;	cnt++;
			if(rand() % ((int)stringset.size()) == 0
				|| cnt == (int)stringset.size()) break;
		}
		cnt = 1;
		while(1){
			it2++;	cnt++;
			if(rand() % ((int)stringset.size()) == 0
				|| cnt == (int)stringset.size()) break;
		}
			cout << "login " << *it <<" "<< *it << endl; 
			cout << "transfer " << *it2 <<" "<< money << endl;
	}
}

void printSearch(set<string> &stringset){
	int n, i;
	cin >> n;
	set<string>::iterator it;
	for(i = 0, it = stringset.begin(); i < n && it != stringset.end(); i++, it++){
		set<string>::iterator it2 = stringset.begin();
		int cnt = 1;
		while(1){
			it2++;	cnt++;
			if(rand() % ((int)stringset.size()) == 0
				|| cnt == (int)stringset.size()) break;
		}
		cout << "login " << *it <<" "<< *it << endl; 
		cout << "search " << *it2 << endl;
	}
}

int main(int argc, char **argv){
	set<string> stringset;
	char command[10];
	srand (time(NULL));
	while(1){
		scanf("%s", command);	
		switch(findCommand(command)){
            /*case LOGIN:
            	printLogin(idset,&USER_NOW);
                break;*/
            case CREATE:
            	printCreate(stringset);
            	break;
            /*case DELETE:
                printDelete(idset);
                break;*/
            case MERGE:
				printMerge(stringset);
            	break;
            case DEPOSIT:
              	printDeposit(stringset);
				break;
			/*case WITHDRAW:
          		printWithdraw(USER_NOW);
            	break;*/
            case TRANSFER:
            	printTransfer(stringset);
                break;
            /*case FIND:
            	printFind(USER_NOW,idset);
                break;*/
            case SEARCH:
            	printSearch(stringset);
                break;
			default:
				cout << "wrong command" << endl;
				break;
        }
	}
	return 0;
}