#include "process.h"
#include "score.h"
using namespace std;
 
//typedef set<INDEX<THistory> > Set;
//typedef Customer<THistory> customer;
const string b = "Hello",c = "fuck";
const customer cus_temp(b,c);

class TL{
public:
	string id;
	int score;
	bool operator<(const TL &a)const{
		if(score != a.score)
			return score < a.score;
		else
			return id < a.id;
	}
	TL(string str, int n){
		id = str;
		score = n;
	}
};


const string strtable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int find_or(vector<INDEX<THistory> > &vtr,const INDEX<THistory> &itm){
	int k = vtr.size();
	if(k == 0)
		return -1;
	for(int i = 0; i < k; i++){
		if(vtr[i] == itm)
			return i;
	}
	return -1;
}

void all_digit_change(int h, vector<int> &NC, set<string> &listset2, string &sample, int pos, const string origin){
	if(h > (int)NC.size()){
		listset2.insert(sample);
		return;
	}
	for(int i = 0; i < 62; i++){
		if(strtable[i] == origin[pos-NC[h-1]])
			continue;
		sample[pos-NC[h-1]] = strtable[i];
		all_digit_change(h+1, NC, listset2, sample, pos, origin);
	}
}

void pick_or_not(int n, int h, vector<int> NC, set<string> &listset2, string sample, int pos){
	if(n < h && n != 0){	
		return;
	}else if(n == 0){
			//cout << "yeah!!!" << endl;
		all_digit_change(1, NC, listset2, sample, pos, sample);
		return;
	}
	pick_or_not(n, h+1, NC, listset2, sample, pos); // not pick
	NC.push_back(h);
	pick_or_not(n-h, h+1, NC, listset2, sample, pos); // pick
	//cout << "fuck yeah!!!" << endl;
}


void extend(int cnt, int n_var, set<string> &listset2, string ID, int pos){
	if(cnt == 0){
		vector<int> needChange; 
		pick_or_not(n_var, 1, needChange, listset2, ID, pos);
		return;
	}
	for(int i = 0; i < 62; i++){
		string ex_string = ID + strtable[i];
		extend(cnt - 1, n_var, listset2, ex_string, pos);
	}
}

void clear_exist_ID(set<string> &listset2,Vec &vec){
	set<string>::iterator ti;
	int i = 0;
	for(ti = listset2.begin(); ti != listset2.end(); ti++){
		int c = 1;
		for(int j = 0; j <(int) vec[int((*ti)[0])].size(); j++){
			if(vec[int((*ti)[0])][j].id == (*ti)){
				listset2.erase(ti);
				c = 0;
				break;
			}
		}
		i += c;
		if(i >= 10)
			break;
	}
}
void violencescore1(set<string> &listset2,const string &ID){
	string tmp (ID,0,((ID.size())-1));
	if(ID.size() > 1)
		listset2.insert(tmp);
	tmp += '@';
	int n = tmp.size() - 1;
	for(int i = 0; i < 62; i ++){
		tmp[n] = strtable[i];
		listset2.insert(tmp);
	}
	tmp = ID; tmp += '@';
	n = tmp.size() - 1;
	for(int i = 0; i < 62; i ++){
		tmp[n] = strtable[i];
		listset2.insert(tmp);
	}
		listset2.erase(ID);
}



void listing10(bool exist, string ID,Vec &vec){
	int i;
	set<TL> listset;
	vector<TL> listvec;
	vector<TL>::iterator vi, minpos;
	set<TL>::iterator ti;
	if(exist){
		for(int j = 0; j < 128;j++){
			for(int k = 0; k < (int)vec[j].size(); k ++)
			listvec.push_back(TL(vec[j][k].id, score(ID, vec[j][k].id)));
		}
		for(i = 0; i < 10 && i < (int)listvec.size(); i++){
			for(vi = listvec.begin()+i, minpos = vi; vi != listvec.end(); vi++){
				if(*vi < *minpos)
					minpos = vi;
			}
			swap(listvec[i], *minpos);
		}
		for(i = 0; i < 10 && i < (int)listvec.size(); i++){
			if(i == 0)
				cout << listvec[i].id;
			else
				cout << ',' << listvec[i].id;
		}
		cout << endl;
									
	}else{
		set<string> listset2;
		set<string>::iterator tt;
		vector<int> needChange;
		int num_in_set = listset2.size(), lv, n_len, n_var, cnt;
		violencescore1(listset2,ID);
		clear_exist_ID(listset2,vec);
		num_in_set = listset2.size();
		if(num_in_set >= 10){
			int i;
			for(i = 0, tt = listset2.begin(); i < 9; tt++){
				cout << *tt <<","/*<< ti->score << endl*/;
				i++;
			}
			cout << *tt <<endl;
			return;
		}
			cout << "2 "<<endl;
		for(lv = 2; num_in_set < 10; lv++){
			/* shorten length */
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				if((int)ID.size() > cnt){
					string cut_string(ID, 0, ID.size()-cnt);
					pick_or_not(n_var, 1, needChange, listset2, cut_string, cut_string.size());
				}else
					break;
			}
			/* same length */
				pick_or_not(lv, 1, needChange, listset2, ID, ID.size());
			/* extend length */
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				extend(cnt, n_var, listset2, ID, ID.size());
			}
			clear_exist_ID(listset2, vec);
			for(tt = listset2.begin(); tt != listset2.end(); tt++){
				listset.insert(TL(*tt, lv));
			}
			needChange.clear();
			num_in_set = listset.size();
			if(num_in_set >= 10){
				for(i = 0, ti = listset.begin(); i < 10; ti++){
					if(ti->id != ID){
						if(i == 9)
							cout << ti->id << endl;
						else
							cout << ti->id <<","/*<< ti->score << endl*/;
						i++;
					}
				}
				break;
			}
		}
	}
}

#define MAX 100
enum prcsmode {CHR, QMK, STAR};

/*void FIND(string user, string test, Set& idset){
	int mode = -1;
//	bool found = false;
	bool firstprint = true;
	Set::iterator si;
	if(test.find("*") == string::npos && test.find("?") == string::npos){
		for(si = idset.begin(); si != idset.end(); si++){
			if(test == si->id){
				if(firstprint){
					cout << si->id;
					firstprint = false;
				}else
					cout<<',' << si->id;
//				found = true;
			}
		}
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
	for(int i = 0; i <(int) test.size(); i++){ 
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
	
//	for(fi = fragment.begin(), count = 0; fi != fragment.end(); fi++, count++){
//		cout << (*fi) << ", " << D[count] << ", " << endl;
//	}
	if(all_qmk){
		for(si = idset.begin(); si != idset.end(); si++){
			if((int)(si->id).size() == D[0]){
				if(firstprint){
					cout << si -> id;
					firstprint = false;
				}else
					cout <<','<< si -> id;

//				found = true;
			}
		}			
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
					if(top_exist && (int)current < D[0]){
						start = current+1;
						continue;
					}else if(top_exist && (int)current > D[0]){
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
					if((int)(current-last) < D[count]){
						start = current+1;
						continue;
					}else if((int)(current-last) > D[count]){
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
			// print out the according word 
			if(firstprint){
				cout << si -> id;
				firstprint = false;
			}else
				cout << ',' << si -> id;
//			found = true;
		}
	}
}
*/
void processLogin(Vec& vec,customer** user_now){
	bool success = false;
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_tmp(ID,cus_temp);
	int num = int(ID[0]);
	int tmp = find_or(vec[num], id_tmp);
	if(tmp < 0)
		 <<"ID "<< ID <<" not found"<< endl;
	else if(! vec[num][tmp].cu_ptr -> authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
		success = true;
		cout <<"success"<< endl;
	}
	if(success)
		*user_now = (vec[num][tmp].cu_ptr);
}

void processCreate(Vec &vec){
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_tmp(ID,cus_temp);
	int num = int(ID[0]);
	int tmp = find_or(vec[num],id_tmp);
	if(tmp < 0){
		INDEX<THistory> new_index(ID,PW);
		vec[num].push_back(new_index);
		cout <<"success"<< endl;
	}else{
		cout <<"ID "<< ID <<" exists, ";
		listing10(false, ID, vec);
	}
}

void processDelete(Vec &vec){
	string ID, PW;
	cin >> ID >> PW;
	INDEX<THistory> id_temp(ID,cus_temp);
	int num = int(ID[0]);
	int tmp = find_or(vec[num],id_temp);
	if(tmp < 0)
		cout <<"ID "<< ID <<" not found"<< endl;
	else if(!vec[num][tmp].cu_ptr -> authenticated(PW))
		cout <<"wrong password"<< endl;
	else {
//		(*tmp).cu_ptr->deletehistory();
		delete vec[num][tmp].cu_ptr;
		swap(vec[num][tmp], vec[num][vec[num].size() - 1] ) ;
		vec[num].pop_back();
		cout <<"success"<< endl;
	}
	return;
}
void processMerge(Vec &vec){
	unsigned long long X = 0;
	string ID1, ID2, PW1, PW2;
	cin >> ID1 >> PW1 >> ID2 >> PW2;
	int num1 = int (ID1[0]), num2 = int(ID2[0]);
	INDEX<THistory> id_tmp1(ID1,cus_temp),id_tmp2(ID2,cus_temp);
	int tmp1 = find_or(vec[num1],id_tmp1);
	int tmp2 = find_or(vec[num2],id_tmp2);
	if(tmp1 < 0)
		cout <<"ID "<< ID1 <<" not found"<< endl;
	else if(tmp2 < 0)
		cout <<"ID "<< ID2 <<" not found"<< endl;
	else if(!vec[num1][tmp1].cu_ptr -> authenticated(PW1))
		cout <<"wrong password1"<< endl;
	else if(!vec[num2][tmp2].cu_ptr -> authenticated(PW2))
		cout <<"wrong password2"<< endl;
	else {
		vec[num1][tmp1].cu_ptr->mergehistory(*(vec[num2][tmp2].cu_ptr));
		X = vec[num1][tmp1].cu_ptr->dollars();
		cout <<"success, "<< ID1 <<" has "<< X <<" dollars"<< endl;
		delete vec[num2][tmp2].cu_ptr;
		swap(vec[num2][tmp2], vec[num2][vec[num2].size() - 1] ) ;
		vec[num2].pop_back();
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
		cout << "success, "<< X <<" dollars left in current account"<< endl;
	}
}

void processTransfer(customer* user_now, int& TIME_CNT, Vec &vec){
	unsigned long long num = 0, X = user_now->dollars();
	string ID;
	cin >>  ID >> num;
	INDEX<THistory> id_tmp(ID,cus_temp);
	int Num = int(ID[0]);
	int tmp = find_or(vec[Num],id_tmp);
	if(tmp < 0){
		cout <<"ID "<< ID <<" not found, ";
//		listing10(true, ID, vec);
	}else if(num > user_now->dollars()){
		cout <<"fail, "<< X <<" dollars only in current account"<< endl;
	}else{
		user_now->transfer(vec[Num][tmp].cu_ptr, num, TIME_CNT);
		X = user_now->dollars();
		cout << "success, "<< X <<" dollars left in current account"<< endl;
		TIME_CNT++;
	}
}
void processFind(customer* user_now, Vec &vec){
	string wild_card_ID;
	cin >> wild_card_ID;
//	FIND(user_now->ID, wild_card_ID, vec);
	cout << endl;
}

void processSearch(customer* user_now, Vec &vec){
	string ID;
	cin >> ID;
	user_now->search(ID);
}
