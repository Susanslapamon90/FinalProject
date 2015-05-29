#include <iostream>
#include <string>

template <class H>
class Costumer{
private:
	string after_transformed_password;;
	int deposit;
	H history;

public:
	string ID;
	Costumer(string idendity,string before_transformed_password){//constructor;
		ID  = idendity;
		after_transformed_password = encode(before_transformed_password); //encode is ALO's encoding function;
		deposit = 0;
	};
	~Costumer(){
		delete ID;
		delete after_transformed_password;
		delete history;
	}
	bool authenticated(string before_transformed_password){//authentication;
		return (encode(before_transformed_password) == after_transformed_password);
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