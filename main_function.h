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
}
 
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
	void merge(Customer id2){
		deposit += id2.deposit;
		history.merge(id2.history);
		delete id2; 
		return;
	}
	void transfer(Customer *target, int tsf_money){ // require Alo's transfer function
		if(tsf_money > deposit)
			printf("fail, [%d] dollars only in current account\n", deposit);
		else{
			deposit -= tsf_money;
			target->deposit += tsf_money;
			printf("success, [%d] dollars left in current account\n", deposit);
		}
		return;
	}
};
