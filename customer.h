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
#include "history.h"
#define TO 1
#define FROM 0
#define U64 unsigned long long int 
using namespace std;

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
		history.hmerge(id2.history, ID);				
		delete id2; 
		return;
	}
	void transfer(Customer *target, U64 tsf_money, int p){ // require Alo's transfer function
		if(tsf_money > deposit)
			printf("fail, %llu dollars only in current account\n", deposit);
		else{
			deposit -= tsf_money;
			target->deposit += tsf_money;
			history.hadd(target->ID, p, TO, tsf_money);
			target->history.hadd(ID, p, FROM, tsf_money);
			history.hpair(target->history);
			printf("success, %llu dollars left in current account\n", deposit);
		}
		return;
	}
};
