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

template <class H>
class Costumer{
private:
	string encoded_password;
	int deposit;
	H history;

public:
	string ID;
	Costumer(string idendity,string raw_password){//constructor;
		ID  = idendity;
		encoded_password = encode(raw_password); //encode is ALO's encoding function;
		deposit = 0;
	};
	~Costumer(){
		delete ID;
		delete encoded_password;
		delete history;
	}
	bool authenticated(string raw_password){//authentication;
		return (encode(raw_password) == encoded_password);
	};
	void Deposit(int money){
		deposit += money;
		return;
	}
	void withdraw(int money){
		if(money > deposit)
			cout << "fail, " <<'[' << deposit << ']' <<" dollors only in current account";
		else{
			deposit -= money;
			cout << "sucess, " <<'[' << deposit << ']' <<" dollors left in current account";
		}
		
	}
	
}
