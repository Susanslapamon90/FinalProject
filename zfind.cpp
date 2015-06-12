#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000

enum prcsmode {CHR, QMK, STAR}

void processFind(string test, vector<string>& ID){
	int mode = 0;
	vector<string>::iterator vi;
	if(test.find("*") == string::npos && test.find("?") == string::npos){
		for(vi = ID.begin(); vi != ID.end(); vi++){
			if(test == *vi)
				cout << *vi << endl;
		}
	}

	string current;
	/*??? head[];
	??? tail;*/
	/*for(int i = 0; i < test.size(), i++){
		if(test[i] == '*'){
			mode = STAR;
			continue;
		}else if(test[i] == '?')
			mode = QMK;
		else
			current += test[i];
	}*/
}

int main(int argc, char** argv){
	vector<string> ID;
	ifstream fp(argv[1]);
	string *tmp = new string;
	while(getline(fp, *tmp))
		ID.push_back(*tmp);
	delete tmp;
	fp.close();

	cout << " #Read in finished" << endl;
	cout << " $From now on, input words to search" << endl;
	cout << " // word's length Domain : 1 ~ 100" << endl;
	cout << " // each charater can only be in {0~9, A~Z, a~z, ?, *}" << endl;
	cout << " // ? : one charater that can be any of {0~9, A~Z, a~z}" << endl;
	cout << " // * : any number(in Domain or 0) of charaters that can be any of {0~9, A~Z, a~z}" << endl;
	cout << " // it is invalid to type such as **, *?, ?* " << endl;

	cout << " $Type something to search : ";
	char cstr[100];
	while(scanf("%s", cstr) != EOF){
		string *tmp = new string(cstr);
		if(tmp->size() == 0){
			cout << " #please type something" << endl;			
		}
		for(int i = 0; i < tmp->size(); i++){
			if((*tmp)[i] < '0' || ((*tmp)[i] > '9' && (*tmp)[i] < 'A') 
				|| ((*tmp)[i] > 'Z' && (*tmp)[i] < 'a') || (*tmp)[i] > 'z'){
				if((*tmp)[i] != '*' && (*tmp)[i] != '?'){
					cout << " #there's invalid charater : " << (*tmp)[i] << endl;
				}
			}
			if((*tmp)[i] == '*' && i > 0){
				if((*tmp)[i-1] == '*' || (*tmp)[i-1] == '?'){
					cout << " #there's invalid combination : " << (*tmp)[i-1] << (*tmp)[i] << endl;
				}
			}
			if((*tmp)[i] == '?' && i > 0 && (*tmp)[i-1] == '*')
				cout << " #there's invalid combination : " << (*tmp)[i-1] << (*tmp)[i] << endl;
		}
		processFind(*tmp, ID);
		cout << "$Type something to search : ";
	}
	return 0;
}
