#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <vector>
#include <ctime>
using namespace std;
#define MAX 100

enum prcsmode {CHR, QMK, STAR};

void processFind(string test, set<string>& idset){
	int mode = -1;
	bool found = false;
	set<string>::iterator si;
	if(test.find("*") == string::npos && test.find("?") == string::npos){
		for(si = idset.begin(); si != idset.end(); si++){
			if(test == *si){
				cout << *si << endl;
				found = true;
			}
		}
		if(!found)
			cout /*<< " #Not Found" */<< endl;
		return;
	}
	vector<string> fragment;
	string current;
	size_t bottom; // top, bottom not always exist
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
	
	for(fi = fragment.begin(), count = 0; fi != fragment.end(); fi++, count++){
		cout << (*fi) << ", " << D[count] << ", " << endl;
	}
	if(all_qmk){
		for(si = idset.begin(); si != idset.end(); si++){
			if((*si).size() == D[0]){
				cout << (*si) << endl;
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
				if((current = (*si).find(*fi, start)) == string::npos){
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
						if(current+(*fi).size()+bottom_dis < (*si).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (*si).size())
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
						if(current+(*fi).size()+bottom_dis < (*si).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (*si).size())
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
						if(current+(*fi).size()+bottom_dis < (*si).size()){
							start = current+1;
							continue;
						}else if(current+(*fi).size()+bottom_dis > (*si).size())
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
		if(can_print){
			/* print out the according word */
			cout << (*si) << endl;
			found = true;
		}
	}
	if(!found)
		cout /*<< " #Not Found" */<< endl;
}

int main(int argc, char** argv){
	time_t t1, t2;
	set<string> ID;
	ifstream fp(argv[1]);
	string *tmp = new string;
	while(getline(fp, *tmp))
		ID.insert(*tmp);
	delete tmp;
	fp.close();

	/*cout << " #Read in finished" << endl;
	cout << " $From now on, input words to search" << endl;
	cout << " // word's length Domain : 1 ~ 100" << endl;
	cout << " // each charater can only be in {0~9, A~Z, a~z, ?, *}" << endl;
	cout << " // ? : one charater that can be any of {0~9, A~Z, a~z}" << endl;
	cout << " // * : any number(in Domain or 0) of charaters that can be any of {0~9, A~Z, a~z}" << endl;
	cout << " // it is invalid to type such as **, *?, ?* " << endl;

	cout << endl << " $Type something to search : ";*/
	char cstr[100];
	while(scanf("%s", cstr) != EOF){
		bool can_process = true;
		string *tmp = new string(cstr);
		/*if(tmp->size() == 0){
			cout << " #please type something" << endl;
			continue;			
		}
		if((*tmp) == "@"){
			cout << " #See you next time! Bye!" << endl;
			return 0;
		}
		for(int i = 0; i < tmp->size(); i++){
			if((*tmp)[i] < '0' || ((*tmp)[i] > '9' && (*tmp)[i] < 'A') 
				|| ((*tmp)[i] > 'Z' && (*tmp)[i] < 'a') || (*tmp)[i] > 'z'){
				if((*tmp)[i] != '*' && (*tmp)[i] != '?'){
					cout << " #there's invalid charater : " << (*tmp)[i] << endl;
					can_process = false;
				}
			}
			if((*tmp)[i] == '*' && i > 0){
				if((*tmp)[i-1] == '*' || (*tmp)[i-1] == '?'){
					cout << " #there's invalid combination : " << (*tmp)[i-1] << (*tmp)[i] << endl;
					can_process = false;
				}
			}
			if((*tmp)[i] == '?' && i > 0 && (*tmp)[i-1] == '*'){
				cout << " #there's invalid combination : " << (*tmp)[i-1] << (*tmp)[i] << endl;
				can_process = false;
			}
		}*/

		//t1 = time(NULL);
		if(can_process)
			processFind(*tmp, ID);
		t2 = time(NULL);
		//printf("The reading time is %0ld:%0ld (min:sec)\n", (t2-t1)/60, (t2-t1)%60);
		//cout << "$Type something to search : ";
	}
	return 0;
}
