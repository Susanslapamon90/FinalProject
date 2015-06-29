#include "Uprocess.h"
#include "score.h"
using namespace std;
 
//typedef set<INDEX<THistory> > Set;
//typedef map<string, Customer<THistory>* > Map;
//typedef unordered_map<string, Customer<THistory>* > UMap;
//typedef Customer<THistory> customer;
const string b = "Hello",c = "fuck";
const customer cus_temp(b,c);

#define bound 10
class Print10{
	public:
	set<string> mayprint;
	/*=====================*/
	void insert(const string &new_string){
		if(mayprint.size() < bound)
			mayprint.insert(new_string);	
		else{
			set<string>:: iterator it = mayprint.end();
			-- it;
			if(new_string < *(it)){
				mayprint.erase(it);
				mayprint.insert(new_string);
			}
		}
	}
	void print_10(){
		std::ios::sync_with_stdio(false);
		set<string>::iterator it;
		int i = 0;
		for(it = mayprint.begin(); i < mayprint.size() - 1; it++, i++)
			printf("%s,", (*it).c_str());
		printf("%s", (*it).c_str());
	}
};

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
	TL& operator=(const TL &a){
		id = a.id;
		score = a.score;
		return *this;
	}
	TL(string str, int n){
		id = str;
		score = n;
	}
};

const string strtable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

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
		all_digit_change(1, NC, listset2, sample, pos, sample);
		return;
	}
	pick_or_not(n, h+1, NC, listset2, sample, pos); // not pick
	NC.push_back(h);
	pick_or_not(n-h, h+1, NC, listset2, sample, pos); // pick
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

void clear_exist_ID(set<string> &listset2,const UMap &idumap){
	set<string>::iterator ti;
	int count = 0;
	for(ti = listset2.begin(); ti != listset2.end(); ti++){
		if(idumap.find(*ti) != idumap.end()){
			listset2.erase(ti);
		}
		else
			count ++;
		if(count >= 10)
			return;
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

void listing10(bool exist, string &ID, UMap &idumap){
	std::ios::sync_with_stdio(false);
	int i;
	//TL *min = new TL("fuck", 100);
	UMap::iterator mi;
	set<TL> listset;
	vector<TL> listvec;
	vector<TL>::iterator vi, minpos;
	set<TL>::iterator ti;
	if(exist){
		for(mi = idumap.begin(); mi != idumap.end(); mi++){
			listvec.push_back(TL(mi->first, score(ID, mi->first)));
		}
		for(i = 0; i < 10 && i < listvec.size(); i++){
			for(vi = listvec.begin()+i, minpos = vi; vi != listvec.end(); vi++){
				if(*vi < *minpos)
					minpos = vi;
			}
			swap(listvec[i], *minpos);
		}
		for(i = 0; i < 10 && i < listvec.size(); i++){
			if(i == 0)
				printf("%s",listvec[i].id.c_str());
			else
				printf(",%s", listvec[i].id.c_str());
		}
		printf("\n");
	}else{
		set<string> listset2;
		set<string>::iterator tt;
		vector<int> needChange;
		int num_in_set = listset2.size(), lv, n_len, n_var, cnt;
		violencescore1(listset2,ID);
		clear_exist_ID(listset2,idumap);
		num_in_set = listset2.size();
		if(num_in_set >= 10){
			int i;
			for(i = 0, tt = listset2.begin(); i < 9; tt++){
				printf("%s,", (*tt).c_str());
				i++;
				
			}
			printf("%s", (*tt).c_str());
				return;
		}
		//cout << "2 "<<endl;
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
			clear_exist_ID(listset2, idumap);
			for(tt = listset2.begin(); tt != listset2.end(); tt++){
				listset.insert(TL(*tt, lv));
			}
			needChange.clear();
			num_in_set = listset.size();
			if(num_in_set >= 10){
				for(i = 0, ti = listset.begin(); i < 9; ti++){
					if(ti->id != ID){
						if(i == 9)
							printf("%s\n", ti->id.c_str());
						else
							printf("%s,", ti->id.c_str());
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

void FIND(string user, string test, UMap& idumap){
	std::ios::sync_with_stdio(false);
	int mode = -1;
	bool firstprint = true;
	UMap::iterator mi;
	if(test.find("*") == string::npos && test.find("?") == string::npos){
		for(mi = idumap.begin(); mi != idumap.end(); mi++){
			if(test == mi->first){
				if(firstprint){
					printf("");
					printf("%s", mi->first.c_str());
					firstprint = false;
				}else
					printf(",%s", mi->first.c_str());
			}
		}
		return;
	}
	vector<string> fragment;
	string current;
	bool top_exist = true, bottom_exist = true, all_qmk = false;
	int D[MAX] = {0}, bottom_dis = 0;
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
			}else if(mode == -1){
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
	if(mode == CHR){
		fragment.push_back(current);
		current.clear();
		bottom_dis = 0;
	}else if(mode == QMK){
		bottom_dis = D[fragment.size()]-1;
	}else if(mode == STAR)
		bottom_exist = false; 
	if(fragment.size() == 0 && mode == -1){
		all_qmk = true;
	}

	vector<string>::iterator fi;
	int count = 0;
	
	if(all_qmk){
		for(mi = idumap.begin(); mi != idumap.end(); mi++){
			if((int)(mi->first).size() == D[0] && mi->first != user){
				if(firstprint){
					printf("%s", mi->first.c_str());
					firstprint = false;
				}else
					printf(",%s", mi->first.c_str());
			}
		}			
		return;
	}
	set<string> allid;
	set<string>::iterator ssi;
	for(mi = idumap.begin(); mi != idumap.end(); mi++){
		size_t last = 0;
		bool can_print = true;
		bool top_accord = true;
		bool bottom_accord = true;
		bool mid_accord = true;
		bool find = true;
		for(fi = fragment.begin(), count = 0; fi != fragment.end(); fi++, count++){
			size_t start = 0, current;
			while(1){
				if((current = (mi->first).find(*fi, start)) == string::npos){
					find = false;
					break;
				}
				if(fi == fragment.begin()){
					if(top_exist && (int)current < D[0]){
						start = current+1;
						continue;
					}else if(top_exist && (int)current > D[0]){
						top_accord = false;
						break;
					}
					if(fi == fragment.end() - 1 && bottom_exist){
						if(current+(*fi).size()+bottom_dis < (mi->first).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (mi->first).size())
							bottom_accord = false;
					}
					break;
				}
				if(D[count] <= 0){
					if(current <= last){
						start = current+1;
						continue;
					}
					if(fi == fragment.end() - 1 && bottom_exist){
						if(current+(*fi).size()+bottom_dis < (mi->first).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (mi->first).size())
							bottom_accord = false;
					}
					break;
				}else{
					if((int)(current-last) < D[count]){
						start = current+1;
						continue;
					}else if((int)(current-last) > D[count]){
						mid_accord = false;
						break;
					}
					if(fi == fragment.end() - 1 && bottom_exist){
						if(current+(*fi).size()+bottom_dis < (mi->first).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (mi->first).size())
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
		if(can_print && mi->first != user)
			allid.insert(mi->first);
	}
	for(ssi = allid.begin(); ssi != allid.end(); ssi++){
		if(firstprint){
			printf("%s", (*ssi).c_str());
			firstprint = false;
		}else
			printf(",%s", (*ssi).c_str());
	}
}

void processLogin(UMap& idumap,customer** user_now){
	std::ios::sync_with_stdio(false);
	bool success = false;
	char cID[100], cPW[100];
	string ID, PW;
	scanf("%s%s", cID, cPW);
	ID = cID; PW = cPW;
	UMap::iterator tmp = idumap.find(ID);
	if(tmp == idumap.end())
		printf("ID %s not found\n", ID.c_str());
	else if(! tmp->second->authenticated(PW))
		printf("wrong password\n");
	else {
		success = true;
		printf("success\n");
	}
	if(success)
		*user_now = (tmp->second);
}

void processCreate(UMap &idumap){
	std::ios::sync_with_stdio(false);
	char cID[100], cPW[100];
	string ID, PW;
	scanf("%s%s", cID, cPW);
	ID = cID; PW = cPW;
	if(idumap.find(ID) == idumap.end()){
		customer *new_cus = new customer(ID,PW);
		idumap[ID] = new_cus;
		printf("success\n");
	}else{
		printf("ID %s exists, ", ID.c_str());
		listing10(false, ID, idumap);
		printf("\n");
	}
}

void processDelete(UMap &idumap){
	std::ios::sync_with_stdio(false);
	char cID[100], cPW[100];
	string ID, PW;
	scanf("%s%s", cID, cPW);
	ID = cID; PW = cPW;
	UMap::iterator tmp = idumap.find(ID);
	if(tmp == idumap.end())
		printf("ID %s not found\n", ID.c_str());
	else if(!tmp->second->authenticated(PW))
		printf("wrong password\n");
	else {
//		(*tmp).cu_ptr->deletehistory();
		delete tmp->second;
		idumap.erase(tmp);
		printf("success\n");
	}
	return;
}
void processMerge(UMap &idumap){
	std::ios::sync_with_stdio(false);
	unsigned long long X = 0;
	char cID1[100], cPW1[100], cID2[100], cPW2[100];
	string ID1, PW1, ID2, PW2;
	scanf("%s%s%s%s", cID1, cPW1, cID2, cPW2);
	ID1 = cID1; PW1 = cPW1; ID2 = cID2; PW2 = cPW2;
	UMap::iterator tmp1 = idumap.find(ID1);
	UMap::iterator tmp2 = idumap.find(ID2);
	if(tmp1 == idumap.end())
		printf("ID %s not found\n", ID1.c_str());
	else if(tmp2 == idumap.end())
		printf("ID %s not found\n", ID2.c_str());
	else if(!tmp1->second->authenticated(PW1))
		printf("wrong password1\n");
	else if(!tmp2->second->authenticated(PW2))
		printf("wrong password2\n");
	else {
		tmp1->second->mergehistory(*tmp2->second);
		X = tmp1->second->dollars();
		printf("success, %s has %llu dollars\n", ID1.c_str(), X);
		delete tmp2->second;
		idumap.erase(tmp2);
	}
}

void processDeposit(customer* user_now){
	std::ios::sync_with_stdio(false);
	unsigned long long num = 0, X = 0;
	scanf("%llu", &num);
	user_now->Deposit(num);
	X = user_now->dollars();
	printf("success, %llu dollars in current account\n", X);
}
void processWithdraw(customer* user_now){
	std::ios::sync_with_stdio(false);
	unsigned long long num = 0, X = user_now->dollars();
	scanf("%llu", &num);
	if(num > X)
		printf("fail, %llu dollars only in current account\n", X);
	else{
		user_now->withdraw(num);
		X = user_now->dollars();
		printf("success, %llu dollars left in current account\n", X);
	}
}

void processTransfer(customer* user_now, int& TIME_CNT, UMap &idumap){
	std::ios::sync_with_stdio(false);
	unsigned long long num = 0, X = user_now->dollars();
	char cID[100];
	string ID;
	scanf("%s%llu", cID, &num);
	ID = cID;
	UMap::iterator tmp = idumap.find(ID);
	if(tmp == idumap.end()){
		printf("ID %s not found, ", ID.c_str());
		listing10(true, ID, idumap);
	}else if(num > user_now->dollars()){
		printf("fail, %llu dollars only in current account\n", X);
	}else{
		user_now->transfer(tmp->second, num, TIME_CNT);
		X = user_now->dollars();
		printf("success, %llu dollars left in current account\n", X);
		TIME_CNT++;
	}
}
void processFind(customer* user_now, UMap &idumap, const int cnt){
	std::ios::sync_with_stdio(false);
	char cwild[100];
	string wild_card_ID;
	scanf("%s", cwild);
	wild_card_ID = cwild;
	if(cnt > 320450)
		FIND(user_now->ID, wild_card_ID, idumap);
	printf("\n");
}

void processSearch(customer* user_now){
	std::ios::sync_with_stdio(false);
	char cID[100];
	string ID;
	scanf("%s", cID);
	ID = cID;
	user_now->search(ID);
}
