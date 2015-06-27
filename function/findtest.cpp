#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>
#include <stdio.h>
using namespace std;

const string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(){
	int i, n;
	cin >> n;
	for(i = 0; i < n; i++){
		string s;
		int kind = rand() % 3;
		switch(kind){
			case 0:
				s += table[rand() % 62];
				break;
			case 1:
				s += "*";
				break;
			case 2:
				s += "?";
				break;
		}
		while(s.size() <= 5){
			if(s[s.size()-1] == '*')
				s += table[rand() % 62];
			else if(s[s.size()-1] == '?'){
				if(rand() % 2 == 0)
					s += table[rand() % 62];
				else
					s += '?';
			}else{
				if(rand() % 3 == 0)
					s += table[rand() % 62];
				else if(rand() % 2 == 0)
					s += '?';
				else
					s += '*';
			}
			if(rand() % 3 == 0) break;
		}
		cout << s << endl;
		s.clear();
	}
	return 0;
}