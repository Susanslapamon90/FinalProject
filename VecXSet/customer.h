#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include <string>
/*---------------*/
#include <ctime>
#include <vector>
#include <map>
#include <array>
#include <set>
#include <list>
#include <algorithm>
#define TO 1
#define FROM 0
#define U64 unsigned long long int 
using namespace std;
 
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
		H history;
	};
	~Customer(){
	};
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
	void mergehistory(Customer& id2){
		deposit += id2.deposit;
		history.hmerge(id2.history, ID);				
		return;
	}
	void transfer(Customer *target, U64 tsf_money, int p){ // require Alo's transfer function
		deposit -= tsf_money;
		target->deposit += tsf_money;
		history.hadd(target->ID, p, TO, tsf_money);
		target->history.hadd(ID, p, FROM, tsf_money);
		history.hpair(target->history);
		return;
	}
	void search(string ID){
		history.hsearch(ID);
		return;
	}
	void deletehistory(){
		history.hdelete();
	}
};


template<class H>
class INDEX{
	public:
	string id;
	Customer<H> *cu_ptr;
	bool operator < (const INDEX& a)const{return id < a.id; }
	bool operator == (const INDEX &a)const{return id == a.id;}
	bool operator == (const string &a)const{return a == id;}
	bool operator() (const INDEX &a, const INDEX &b){return a.id < b.id;}
	/*constructor & destructor*/
	INDEX(string st,Customer<H> ptr){
		id = st;
		cu_ptr = &ptr;};
	INDEX(string str){
		id = str;
		cu_ptr = NULL;
	}
	INDEX(string ID,string password){
		id = ID;
		cu_ptr = new Customer<H>(ID,password);
	}
	~INDEX(){
	}
	// other function, if needed
};
