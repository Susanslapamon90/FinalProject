#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

using namespace std;

const string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm";
const string tablenum ="0123456789";
const string tablesmall ="qwertyuiopasdfghjklzxcvbnm";
const string tablebig ="QWERTYUIOPASDFGHJKLZXCVBNM";

void gen_rand(int casenum,int kind){
	set<string> stringset;
	for(int i = 0; (int)stringset.size() < casenum; i++){
		string s;
		switch(kind){
			case 1:
				s += tablenum[rand() % 10];
				break;
			case 2:
				s += tablesmall[rand() % 26];
				break;
			case 3:
				s += tablebig[rand() % 26];
				break;
		}
		bool stop = false;
		while(!stop && s.size() <= 100){
			s += table[rand() % 62];
			if(rand() % 10 == 0) stop = true;
		}
		stringset.insert(s);
		s.clear();
	}
	set<string>:: iterator it;
	for(it = stringset.begin(); it != stringset.end(); it++)
		cout << *it <<endl;
}

int main(){
	int casenum1,casenum2,casenum3;
//	cout << "number start:";
	cin >> casenum1;
//	cout<< "small start:";
	cin >> casenum2;
//	cout << "big start:";
	cin >> casenum3;
//	cout << endl;
	srand (time(NULL));
	gen_rand(casenum1,1);
	gen_rand(casenum2,2);
	gen_rand(casenum3,3);
}

