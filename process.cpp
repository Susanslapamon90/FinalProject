#include "process.h"
using namespace std;
 
//typedef set<INDEX<THistory>> Set;
//typedef Customer<THistory> costumer;


void processLogin(Set& idset,customer* user_now){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	Customer<THistory> a(ID,PW);
//	INDEX<THistory> b(ID,a);
//	Set::iterator tmp = idset.find(a);
//	if(tmp == idser.end())
//		cout <<"ID "<< ID <<" not found"<< endl;
//	else if(!tmp->authenticated(PW))
//		cout <<"wrong password"<< endl;
//	else {
//		success = true;
//		cout <<"success"<< endl;
//	}
//	if(success)
//		user_now = tmp;
	return;
}

/*
void processCreate(Set &idset){
	string ID, PW;
	cin >> ID >> PW;
	if(find(ID) == NULL){
		Customer new_customer(ID,password);
		INDEX new_index(ID,new_costumer);
		idset.insert(new_index);
	// others require the DS of our ID web
		cout <<"success"<< endl;
	}else{
		cout <<"ID "<< ID <<" exists, ";
		listing10(false, ID, idset);
	}
}
void processDelete(Set &idset){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	Set<INDEX>::iterator tmp = idset.find(ID);
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
void processMerge(Set &idset){
	unsigned long long X = 0;
	string ID1, ID2, PW1, PW2;
	cin >> ID1 >> PW1 >> ID2 >> PW2;
	Set::iterator tmp1 = idset.find(ID1);
	Set::iterator tmp2 = idset.find(ID2);
	if(tmp1 == NULL)
		cout <<"ID "<< ID1 <<" not found"<< endl;
	else if(tmp2 == NULL)
		cout <<"ID "<< ID2 <<" not found"<< endl;
	else if(!tmp1->authenticated(PW1))
		cout <<"wrong password1"<< endl;
	else if(!tmp2->authenticated(PW2))
		cout <<"wrong password2"<< endl;
	else {
		tmp1->cu_ptr->merge(*(tmp2->cu_ptr));
		X = tmp1->cu_ptr->dollars();
		cout <<"success, "<< ID1 <<" has "<< X <<" dollars"<< endl;
	}
}
void processDeposit(customer* user_now){
	unsigned long long num = 0, X = 0;
	cin >> num;
	user_now->Deposit(num);
	X = user_now->dollars();
	cout <<"success, "<< X <<" dollars in current account"<< endl;
}
void processWithdraw(customer* user_now){
	unsigned long long num = 0, X = user_now->dollars();
	cin >> num;
	if(num > X)
		cout << "fail, "<< X <<" dollars only in current account"<< endl;
	else{
		user_now->withdraw(num);
		X = user_now->dollars();
		cout << "sucess, "<< X <<" dollars left in current account"<< endl;
	}
}
void processTransfer(customer* user_now, int TIME_CNT, Set &idset){
	unsigned long long num = 0, X = user_now->dollars();
	string ID;
	cin >> num >> ID;
	Set::iterator tmp = idset.find(ID);
	if(tmp == NULL){
		cout <<"ID "<< ID <<" not found, ";
		listing10(true, ID, idset);
	}else if(num > user_now->dollars()){
		cout <<"fail, "<< X <<" dollars only in current account"<< endl;
	}else{
		user_now->transfer(tmp->cu_ptr, num, TIME_CNT);
		X = user_now->dollars();
		cout << "sucess, "<< X <<" dollars left in current account"<< endl;
	}
}
void processFind(customer* user_now, Set &idset){
	string wild_card_ID;
	cin >> wild_card_ID;
	FIND(user_now, idset, wild_card_ID);
}
void processSearch(customer* user_now, Set &idset){
	string ID;
	cin >> ID;
	Set::iterator tmp = idset.find(ID);
	if(tmp == NULL)
		cout <<"ID "<< ID <<" not found"<< endl;
	else
		user_now->search(ID);
}
*/
