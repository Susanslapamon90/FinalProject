#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include "score.h"
using namespace std;
#define MAX 100

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

class Customer{
public:
	int a;
};

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
	INDEX(string st){
		id = st;
		cu_ptr = NULL;
	}
	INDEX(string st, Customer ptr){
		id = st;
		cu_ptr = &ptr;
	}
	~INDEX(){
		id.clear();
		delete cu_ptr;
	}
	// other function
};

/*int ctable[20] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 
	66, 78, 91, 105, 120, 136, 153, 171, 190, 210}*/ /* table of valid n_len */

const string strtable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void all_digit_change(int h, vector<int> &NC, set<string> &listset2, string &sample,int pos, const string origin){
	if(h > NC.size()){
		listset2.insert(sample);
		return;
	}
	for(int i = 0; i < 62; i++){
//		cout<< pos <<", "<< origin <<", "<< origin[pos-NC[h-1]]<<endl;
		if(strtable[i] == origin[pos - NC[h-1]]){
//			cout <<strtable[i] << "~~~~~~~~~~~~flag~~~~~~~~~~~~~~~ " << endl;
			continue;
		}
		sample[pos-NC[h-1]] = strtable[i];
		all_digit_change(h+1, NC, listset2, sample,pos,origin);
	}
}

void pick_or_not(int n, int h, vector<int> NC, set<string> &listset2, string sample, int pos){
	if(n < h && n != 0){
			//cout << "fuck!!!" << endl;
		return;
	}else if(n == 0){
			//cout << "yeah!!!" << endl;
		all_digit_change(1, NC, listset2, sample,pos,sample);
		return;
	}
	pick_or_not(n, h+1, NC, listset2, sample,pos); // not pick
	NC.push_back(h); 
	pick_or_not(n-h, h+1, NC, listset2, sample,pos); // pick
	//cout << "fuck yeah!!!" << endl;
}

void extend(int cnt, int n_var, set<string> &listset2, string ID,int pos){
	if(cnt == 0){
		vector<int> needChange; 
		pick_or_not(n_var, 1, needChange, listset2, ID,pos);
		return;
	}
	for(int i = 0; i < 62; i++){
		string ex_string = ID + strtable[i];
		extend(cnt - 1, n_var, listset2, ex_string,pos);
	}
}

void listing10(string ID,int score){
	int i;
	set<INDEX>::iterator si;
	set<TL> listset;
	set<TL>::iterator ti;
		set<string> listset2;
		set<string>::iterator tt;
		vector<int> needChange;
		int num_in_set = listset2.size(), lv, n_len, n_var, cnt;
		for(lv = score; lv <= score; lv++){
			/* shorten length */
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				if(ID.size() > n_len){
					string cut_string(ID, 0, ID.size()-n_len);
					pick_or_not(n_var, 1, needChange, listset2, cut_string, cut_string.size());
				}else
					break;
			}

			for(tt = listset2.begin(); tt != listset2.end() ; tt++){
						cout << *tt <<endl;
						i++;
				}
			listset2.clear();
			/* same length */
				pick_or_not(lv, 1, needChange, listset2, ID, ID.size());
			/* extend length */
				for(tt = listset2.begin(); tt != listset2.end() ; tt++){
						cout << *tt <<endl;
						i++;
				}
			listset2.clear();
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				extend(cnt, n_var, listset2, ID, ID.size());
			}
			for(tt = listset2.begin(); tt != listset2.end(); tt++){
				listset.insert(TL(*tt, lv));
			}
			needChange.clear();
				for(tt = listset2.begin(); tt != listset2.end() ; tt++){
						cout << *tt <<endl;
						i++;
				}
			listset2.clear();
		}
		
}

int main(int argc, char** argv){
	char cstr[100];
	while(scanf("%s", cstr) != EOF){
		int score;
		cin  >> score;
		bool can_process = true;
		string *tmp = new string(cstr);
		if(tmp->size() == 0){
			continue;			
		}
		if((*tmp) == "@"){
			return 0;
		}
		listing10(*tmp,score);
		cout << "end" << endl;
	}
	return 0;
}
