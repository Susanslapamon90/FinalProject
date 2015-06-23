#include "process.h"
using namespace std;
 
//typedef set<INDEX<THistory> > Set;
//typedef Customer<THistory> customer;
string b = "Hello",c = "fuck";
customer cus_temp(b,c);


void processLogin(Set& idset,customer** user_now){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_tmp(ID,cus_temp);
	Set::iterator tmp = idset.find(id_tmp);
	if(tmp == idset.end())
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(! tmp-> cu_ptr -> authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		success = true;
		cout <<"success"<< endl;
	}
	if(success)
		*user_now = (tmp -> cu_ptr);
}

void processCreate(Set &idset){
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_tmp(ID,cus_temp);
	if(idset.find(id_tmp) == idset.end()){
		INDEX<THistory> *new_index = new INDEX<THistory>(ID,PW);
		idset.insert(*new_index);
	// others require the DS of our ID web
		cout <<"success"<< endl;
	}else{
		cout <<"ID "<< ID <<" exists, ";
//		listing10(false, ID, idset);
	}
}

void processDelete(Set &idset){
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_temp(ID,cus_temp);
	Set::iterator tmp = idset.find(id_temp);
	if(tmp == idset.end())
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(!tmp-> cu_ptr -> authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		(*tmp).cu_ptr->deletehistory();
		idset.erase(tmp);
		cout <<"success"<< endl;
	}
	return;
}
void processMerge(Set &idset){
	unsigned long long X = 0;
	string ID1, ID2, PW1, PW2;
	cin >> ID1 >> PW1 >> ID2 >> PW2;
	INDEX<THistory> id_tmp1(ID1,cus_temp),id_tmp2(ID2,cus_temp);
	Set::iterator tmp1 = idset.find(id_tmp1);
	Set::iterator tmp2 = idset.find(id_tmp2);
	if(tmp1 == idset.end())
		cout <<"ID "<< ID1 <<" not found"<< endl;
	else if(tmp2 == idset.end())
		cout <<"ID "<< ID2 <<" not found"<< endl;
	else if(!tmp1-> cu_ptr -> authenticated(PW1))
		cout <<"wrong password1"<< endl;
	else if(!tmp2->cu_ptr -> authenticated(PW2))
		cout <<"wrong password2"<< endl;
	else {
		tmp1->cu_ptr->mergehistory(*(tmp2->cu_ptr));
		X = tmp1->cu_ptr->dollars();
		cout <<"success, "<< ID1 <<" has "<< X <<" dollars"<< endl;
		idset.erase(id_tmp2);
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

void processTransfer(customer* user_now, int& TIME_CNT, Set &idset){
	unsigned long long num = 0, X = user_now->dollars();
	string ID;
	cin >>  ID >> num;
	INDEX<THistory> id_tmp(ID,cus_temp);
	Set::iterator tmp = idset.find(id_tmp);
	if(tmp == idset.end()){
		cout <<"ID "<< ID <<" not found, ";
//		listing10(true, ID, idset);
	}else if(num > user_now->dollars()){
		cout <<"fail, "<< X <<" dollars only in current account"<< endl;
	}else{
		user_now->transfer(tmp->cu_ptr, num, TIME_CNT);
		X = user_now->dollars();
		cout << "success, "<< X <<" dollars left in current account"<< endl;
		TIME_CNT++;
	}
}
void processFind(customer* user_now, Set &idset){
	string wild_card_ID;
	cin >> wild_card_ID;
//	FIND(user_now, idset, wild_card_ID);
}

void processSearch(customer* user_now, Set &idset){
	string ID;
	cin >> ID;
	INDEX<THistory> id_temp(ID,cus_temp);
	Set::iterator tmp = idset.find(id_temp);
	if(tmp == idset.end())
		cout <<"ID "<< ID <<" not found"<< endl;
	else
		user_now->search(ID);
}
