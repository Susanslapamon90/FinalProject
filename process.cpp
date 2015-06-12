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
void processCreate(){
	string ID,password;
	cin >> ID >> password;
	if(find(ID) == NULL){
		Customer *now = new Customer(ID,password);
	// others require the DS of our ID web;	
	}

}
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
void processDeposit(Customer* user_now)
void processWithdraw(Customer* user_now)
void processTransfer(Customer* user_now)
void processFind(Customer* user_now);
void processSearch(Customer* user_now);
