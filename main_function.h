#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
/*---------------*/
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <set>
#define TO 0
#define FROM 1
using namespace std;

struct transferhistory{
	string id;
	int priority;
	bool tofrom;
	int money;
	struct transferhistory *bro;
}; 
typedef struct transferhistory THistory;

bool mergecmp(THistory *a, THistory *b){
	return(a->priority <= b->priority);
}

class INDEX{
	public:
	string id;
	Customer *cu_ptr;
	bool operator < (const INDEX &a){return id > a.id;};
	bool operator == (const INDEX &a){return id == a.id;}
	bool operator == (const string &a){return a == id;}
	/*constructor & destructor*/
	INDEX(string st, Customer ptr){
		id = st;
		cu_ptr = &ptr;};
	~INDEX(){
		id.clear();
	}
	//yet completed
};
 
template <class H>
class Customer{
private:
	string encoded_password;
	int deposit;
	H history;

public:
	string ID;
	Customer(string idendity,string raw_password){//constructor;
		ID  = idendity;
		encoded_password = encode(raw_password); //encode is ALO's encoding function;
		deposit = 0;
	};
	~Customer(){
		delete ID;
		delete encoded_password;
		delete history;
	}
	bool authenticated(string raw_password){//authentication;
		return (encode(raw_password) == encoded_password);
	};
	void Deposit(int money){
		deposit += money;
		history.add(1,money);//not sure
		return;
	}
	void withdraw(int money){
		if(money > deposit)
			cout << "fail, " <<'[' << deposit << ']' <<" dollors only in current account";
		else{
			deposit -= money;
			cout << "sucess, " <<'[' << deposit << ']' <<" dollors left in current account";
		}
		history.add(2,money);//not sure
		return;
	}
	void mergehistory(Customer id2){
		deposit += id2.deposit;
		vector<THistory *> vtmp;
		merge(history, id2.history, vtmp, mergecmp);
		history = vtmp;
			
		vector<THistory *>::iterator i;
		for(i = id2.history.begin(); i != id2.history.end(); i++){
			(*i)->bro->id = ID;
			(*i)->bro->bro = this;
			delete (*i);
		}
		//history.merge(id2.history);/*I want to use stl merge*/
		delete id2; 
		return;
	}
	void transfer(Customer *target, int tsf_money, int p){ // require Alo's transfer function
		if(tsf_money > deposit)
			printf("fail, [%d] dollars only in current account\n", deposit);
		else{
			deposit -= tsf_money;
			target->deposit += tsf_money;
			
			THistory *tmp, *tmp2;
			tmp = new THistory;
			tmp2 = new THistory;
			
			tmp->money = tmp2->money = tsf_money;
			tmp->priority = tmp2->priority = p;
			tmp->id = target->ID;
			tmp->tofrom = TO;
			tmp->bro = tmp2;
			history.push_back(tmp);
			
			tmp2->id = ID;
			tmp2->tofrom = FROM;
			tmp2->bro = tmp1;
			target->history.push_back(tmp2);
			printf("success, [%d] dollars left in current account\n", deposit);
		}
		return;
	}
};
