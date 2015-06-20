#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
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
	INDEX(string st, Customer ptr){
		id = st;
		cu_ptr = &ptr;};
	~INDEX(){
		id.clear();
		delete cu_ptr;
	}
	// other function
};

void listing10(bool exist, string ID, set<INDEX> &idset){
	int i, n;
	set<TL> listset;
	set<INDEX>::iterator si;
	set<TL>::iterator ti;
	if(exist){
		for(si = idset.begin(); si != idset.end(); si++){
			if((n = score(ID, si->id)) != 0)
				listset.insert(TL(si->id, n));
		}
		for(i = 0, ti = listset.begin(); i < 10 && ti != listset.end(); i++, ti++){
			cout << ti->id <<", "<< ti->score << endl;
		}
	}
}

int main(int argc, char** argv){
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
		cout << " $The following is the top 10 ID recommended" << endl;
		listing10(true, *tmp, idset);
		cout << "================================" << endl;
		cout << "$Type something to search : ";
	}
	return 0;
}