#include <iostream>
#include <string>

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
		history.add(2,money);
		return;
	}
	void merge(Costumer id2){
		deposit += id2.deposit;
		history.merge(id2.history);
		delete id2;
		return;
	}
};
