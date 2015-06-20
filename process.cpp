#include "process.h"
using namespace std;

void processLogin(set<INDEX>& idset,Customer* user_now){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	set<INDEX>::iterator tmp = idset.find(ID);
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
void processCreate(set<INDEX> &idset){
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
void processDelete(set<INDEX> &idset){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	set<INDEX>::iterator tmp = idset.find(ID);
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
void processMerge(set<INDEX> &idset){
	unsigned long long X = 0;
	string ID1, ID2, PW1, PW2;
	cin >> ID1 >> PW1 >> ID2 >> PW2;
	set<INDEX>::iterator tmp1 = idset.find(ID1);
	set<INDEX>::iterator tmp2 = idset.find(ID2);
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
void processDeposit(Customer* user_now){
	unsigned long long num = 0, X = 0;
	cin >> num;
	user_now->Deposit(num);
	X = user_now->dollars();
	cout <<"success, "<< X <<" dollars in current account"<< endl;
}
void processWithdraw(Customer* user_now){
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
void processTransfer(Customer* user_now, int TIME_CNT, set<INDEX> &idset){
	unsigned long long num = 0, X = user_now->dollars();
	string ID;
	cin >> num >> ID;
	set<INDEX>::iterator tmp = idset.find(ID);
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
void processFind(Customer* user_now, set<INDEX> &idset){
	string wild_card_ID;
	cin >> wild_card_ID;
	FIND(user_now, idset, wild_card_ID);
}
void processSearch(Customer* user_now, set<INDEX> &idset){
	string ID;
	cin >> ID;
	set<INDEX>::iterator tmp = idset.find(ID);
	if(tmp == NULL)
		cout <<"ID "<< ID <<" not found"<< endl;
	else
		user_now->search(ID);
}
