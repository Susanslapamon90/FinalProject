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

void all_digit_change(int h, vector<int> &NC, set<string> &listset2, string &sample/*,int pos*/){
	if(h > NC.size()){
		listset2.insert(sample);
		return;
	}
	for(int i = 0; i < 62; i++){
		if(strtable[i] == sample[/*pos*/sample.size()-NC[h-1]])
			continue;
		sample[/*pos*/sample.size()-NC[h-1]] = strtable[i];
		all_digit_change(h+1, NC, listset2, sample/*,pos*/);
	}
}

void pick_or_not(int n, int h, vector<int> NC, set<string> &listset2, string sample/*, int pos*/){
	if(n < h && n != 0){
			//cout << "fuck!!!" << endl;
		return;
	}else if(n == 0){
			//cout << "yeah!!!" << endl;
		all_digit_change(1, NC, listset2, sample/*,pos*/);
		return;
	}
	pick_or_not(n, h+1, NC, listset2, sample/*,pos*/); // not pick
	NC.push_back(h); 
	pick_or_not(n-h, h+1, NC, listset2, sample/*,pos*/); // pick
	//cout << "fuck yeah!!!" << endl;
}

void extend(int n_len, int n_var, set<string> &listset2, string ID/*,int pos*/){
	if(n_len == 0){
		vector<int> needChange; 
		pick_or_not(n_var, 1, needChange, listset2, ID/*,pos*/);
		return;
	}
	for(int i = 0; i < 62; i++){
		string ex_string = ID + strtable[i];
		extend(n_len - 1, n_var, listset2, ex_string/*,pos*/);
	}
}

void clear_exist_ID(set<string> &listset2, set<INDEX> idset){
	set<string>::iterator ti;
	for(ti = listset2.begin(); ti != listset2.end(); ti++){
		if(idset.find(INDEX(*ti)) != idset.end()){
			//cout <<"clear "<< *ti << endl;
			listset2.erase(ti);
		}
	}
}


void listing10(bool exist, string ID, set<INDEX> &idset){
	int i;
	set<INDEX>::iterator si;
	set<TL> listset;
	set<TL>::iterator ti;
	if(exist){
		for(si = idset.begin(); si != idset.end(); si++){
				listset.insert(TL(si->id, score(ID, si->id)));
		}
		for(i = 0, ti = listset.begin(); i < 10 && ti != listset.end(); ti++){
			if(ti->score != 0){
				cout << ti->id <<", "<< ti->score << endl;
				i++;
			}
		}
	}else{
		set<string> listset2;
		set<string>::iterator tt;
		vector<int> needChange;
		int num_in_set = listset2.size(), lv, n_len, n_var, cnt;
		for(lv = 1; num_in_set < 10; lv++){
			/* shorten length */
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				if(ID.size() > n_len){
					string cut_string(ID, 0, ID.size()-n_len);
					pick_or_not(n_var, 1, needChange, listset2, cut_string/*, cut_string.size()*/);
				}else
					break;
			}
			/* same length */
				pick_or_not(lv, 1, needChange, listset2, ID/*, ID.size()*/);
			/* extend length */
			for(n_len = 1, cnt = 1; n_len <= lv; cnt++, n_len+=cnt){
				n_var = lv - n_len;
				extend(n_len, n_var, listset2, ID/*, ID.size()*/);
			}
			clear_exist_ID(listset2, idset);
			for(tt = listset2.begin(); tt != listset2.end(); tt++){
				listset.insert(TL(*tt, lv));
			}
			needChange.clear();
			num_in_set = listset2.size();
			if(num_in_set >= 10){
				for(i = 0, tt = listset2.begin(); i < 10; tt++){
					if(*tt != ID){
						cout << *tt <<", "<< lv << endl;
						i++;
					}
				}
				break;
			}
		}
	}
}

int main(int argc, char** argv){
	time_t t1, t2;
	set<INDEX> idset;
	ifstream fp(argv[1]);
	INDEX *tmp = new INDEX;
	while(getline(fp, tmp->id))
		idset.insert(*tmp);
	delete tmp;
	fp.close();

	cout << " #Read in finished" << endl;
	
	cout << endl << " $Type something to search : ";
	char cstr[100];
	while(scanf("%s", cstr) != EOF){
		bool can_process = true;
		string *tmp = new string(cstr);
		if(tmp->size() == 0){
			cout << " #please type something" << endl;
			continue;			
		}
		if((*tmp) == "@"){
			cout << " #See you next time! Bye!" << endl;
			return 0;
		}
			t1 = time(NULL);
		cout << " $The following is the top 10 ID recommended" << endl;
		listing10(false, *tmp, idset);
			t2 = time(NULL);
			printf("The reading time is %0ld:%0ld (min:sec)\n", (t2-t1)/60, (t2-t1)%60);
		cout << "================================" << endl;
		cout << "$Type something to search : ";
	}
	return 0;
}
