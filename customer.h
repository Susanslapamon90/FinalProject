#include <iostream>
#include <assert.h>
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
#define TO 0
#define FROM 1
#define U64 unsigned long long int 
using namespace std;

struct transferhistory{
	string id;
	int priority;
	bool tofrom;
	U64 money;
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
	bool operator < (const INDEX &a)const{return id < a.id;}
	bool operator > (const INDEX &a)const{return id > a.id;}
	bool operator == (const INDEX &a)const{return id == a.id;}
	bool operator == (const string &a)const{return a == id;}
	/*constructor & destructor*/
	INDEX(){
		id = "";
		cu_ptr = NULL;
	}
	INDEX(string st, Customer ptr){
		id = st;
		cu_ptr = &ptr;};
	~INDEX(){
		id.clear();
		delete cu_ptr;
	}
	// other function
};
 
template <class H>
class Customer{
private:
	string encoded_password;
	U64 deposit;
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
	U64 dollars(){
		return deposit;
	}
	void Deposit(U64 money){
		deposit += money;
		return;
	}
	void withdraw(U64 money){
		assert(money <= deposit);
		deposit -= money;
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
