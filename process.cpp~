#include "process.h"
using namespace std;

void processLogin(Customer* user_now){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	Customer* tmp = find(ID); // Leinad's find function
	if(tmp == NULL)
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(!tmp->authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		success = true;
		cout <<"success"<< endl;
	}
	if(success)
		user_now = tmp;
	return;
}
void processCreate();
void processDelete(/* no argument */){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	Customer* tmp = find(ID); // Leinad's find function
	if(tmp == NULL)
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(!tmp->authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		success = true;
		cout <<"success"<< endl;
	}
	if(success)
		delete *tmp;
	return;
}
void processMerge();
void processDeposit();
void processWithdraw();
void processTransfer();
void processFind();
void processSearch();
