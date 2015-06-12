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
void processCreate(Set<INDEX> &idset){
	string ID,password;
	cin >> ID >> password;
	if(find(ID) == NULL){
		Customer new_costumer(ID,password);
		INDEX new_index(ID,new_costumer);
		idset.insert(new_index);
	// others require the DS of our ID web
	}
	//gave ten advices.

}
void processDelete(set<INDEX> &idset){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	set<INDEX>::iterator tmp = idset.find(ID); // Leinad's find function
	if(tmp == NULL)
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(!tmp->authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		success = true;
		idset.erase(tmp);
		cout <<"success"<< endl;
	}
	if(success)
		delete *tmp;
	return;
}
void processMerge();
void processDeposit(Customer* user_now);
void processWithdraw(Customer* user_now);
void processTransfer(Customer* user_now,int &TIME_CNT);
void processFind(Customer* user_now);
void processSearch(Customer* user_now);
