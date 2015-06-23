#include "process.h"
using namespace std;
 
//typedef set<INDEX<THistory> > Set;
//typedef Customer<THistory> customer;
string b = "Hello",c = "fuck";
customer cus_temp(b,c);

#define MAX 100
enum prcsmode {CHR, QMK, STAR};

void FIND(string user, string test, Set& idset){
	int mode = -1;
	bool found = false;
	Set::iterator si;
	if(test.find("*") == string::npos && test.find("?") == string::npos){
		for(si = idset.begin(); si != idset.end(); si++){
			if(test == si->id){
				cout << si->id << endl;
				found = true;
			}
		}
		if(!found)
			cout /*<< " #Not Found" */<< endl;
		return;
	}
	vector<string> fragment;
	string current;
	//size_t bottom; // top, bottom not always exist
	bool top_exist = true, bottom_exist = true, all_qmk = false;// for non-star
	int D[MAX] = {0}, bottom_dis = 0; // for qmk
	// process the search string
	if(test[0] == '*')
		top_exist = false; 
	for(int i = 0; i < test.size(); i++){ 
		if(test[i] == '*'){
			if(mode == -1){
				mode = STAR;
				continue;
			}
			mode = STAR;
			fragment.push_back(current);
			current.clear();
			D[fragment.size()] = 0;
		}else if(test[i] == '?'){
			if(mode == CHR){ 
				fragment.push_back(current);
				current.clear();
				D[fragment.size()] = 2;
				mode = QMK;
			}else if(mode == -1){ // head = ? condition
				D[0]++;
			}else {
				D[fragment.size()]++;
				mode = QMK;
			}
		}else {
			current += test[i];
			mode = CHR;
		}
	}
	if(mode == CHR){ // push the last fragment
		fragment.push_back(current);
		current.clear();
		bottom_dis = 0;
	}else if(mode == QMK){
		bottom_dis = D[fragment.size()]-1;
	}else if(mode == STAR)
		bottom_exist = false; 
	if(fragment.size() == 0 && mode == -1){
		//cout << "all qmk, " << D[0] << endl;
		all_qmk = true;
	}

	
	// go through our idset
	vector<string>::iterator fi;
	int count = 0;
	
	/*for(fi = fragment.begin(), count = 0; fi != fragment.end(); fi++, count++){
		cout << (*fi) << ", " << D[count] << ", " << endl;
	}*/
	if(all_qmk){
		for(si = idset.begin(); si != idset.end(); si++){
			if((si->id).size() == D[0]){
				cout << (si->id) << endl;
				found = true;
			}
		}
		if(!found)
			cout /*<< " #Not Found" */<< endl;
		return;
	}

	for(si = idset.begin(); si != idset.end(); si++){
		size_t last = 0;
		bool can_print = true;
		bool top_accord = true; // assumed it will be ok
		bool bottom_accord = true; // assumed it will be ok
		bool mid_accord = true; // assumed it will be ok
		bool find = true; // assumed it will be ok
		for(fi = fragment.begin(), count = 0; fi != fragment.end(); fi++, count++){
			size_t start = 0, current;
			while(1){
				if((current = (si->id).find(*fi, start)) == string::npos){
					find = false;
					break;
				}
				if(fi == fragment.begin()){ // check top
					if(top_exist && current < D[0]){
						start = current+1;
						continue;
					}else if(top_exist && current > D[0]){
						top_accord = false;
						break;
					}
					if(fi == fragment.end() - 1 && bottom_exist){ // check bottom
						if(current+(*fi).size()+bottom_dis < (si->id).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (si->id).size())
							bottom_accord = false;
					}
					break;
				}
				if(D[count] <= 0){ // check fragment after *
					if(current <= last){
						start = current+1;
						continue;
					}
					if(fi == fragment.end() - 1 && bottom_exist){ // check bottom
						if(current+(*fi).size()+bottom_dis < (si->id).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (si->id).size())
							bottom_accord = false;
					}
					break;
				}else{ // check fragment after ?
					if(current-last < D[count]){
						start = current+1;
						continue;
					}else if(current-last > D[count]){
						mid_accord = false;
						break;
					}
					if(fi == fragment.end() - 1 && bottom_exist){ // check bottom
						if(current+(*fi).size()+bottom_dis < (si->id).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (si->id).size())
							bottom_accord = false;
					}
					break;
				}
			}
			last = current + (*fi).size() - 1;
			if(!find || !top_accord || !mid_accord || !bottom_accord){
				can_print = false;
				break;
			}
		}
		if(can_print && si->id != user){
			/* print out the according word */
			cout << (si->id) << endl;
			found = true;
		}
	}
	if(!found)
		cout /*<< " #Not Found" */<< endl;
}

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
	FIND(user_now->ID, wild_card_ID, idset);
}

void processSearch(customer* user_now, Set &idset){
	string ID;
	cin >> ID;
	INDEX<THistory> id_temp(ID,cus_temp);
	Set::iterator tmp = idset.find(id_temp);
	if(tmp == idset.end())
		printf("no record\n");
	else
		user_now->search(ID);
}
