#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <ctime>
#include <algorithm>
using namespace std;

class Index{
public:
	map<int, char*> mp;
};

int main(int argc, char** argv){
	Index sean[101];
	int i, cnt = 0, maxlen = 0;
	//FILE *fp = fopen(argv[1], "r");
	cout << endl;
	cout << "Welcome to this poor find.cpp !!!" << endl;
	cout << "Please key in the data line by line ^o^" << endl;
	cout << "/* end up inputing by key in \"stop\" */" << endl;
	while(1){
		char *tmp = new char[100];
		//fgets(tmp, 100, fp);
		scanf("%s", tmp);
		if(strcmp(tmp, "stop") == 0)
			break;
		maxlen = (strlen(tmp) > maxlen)? strlen(tmp) : maxlen;
		sean[strlen(tmp)].mp[cnt] = tmp;
		cnt++; 
	}
	//fclose(fp);
	cout << "string read in finished !!!" << endl;
	cout << "Maxlen : " << maxlen << endl;
	cout << "Number of data : " << cnt << endl;

	int L, chrCase = 0, found = 0;
	bool haveStar = 0;
	map<int, char*>::iterator mi;

	cout << "======================" <<endl;
	cout << "/* quiting this program by key in \"exit\" */" << endl;
	while(1){
		found = 0;
		cout << "String to search : ";
		char *tmpStr = new char[100];
		scanf("%s", tmpStr);
		if(strcmp(tmpStr, "exit") == 0){
			cout << "Bye bye!!!" << endl;
			return 0;
		} 
		//scanf("%d", &L);
		for(i = 1; i <= maxlen; i++){
			if(sean[i].mp.empty())
				continue;
			for(mi = sean[i].mp.begin(); mi != sean[i].mp.end(); mi++){
				if(strstr(mi->second, tmpStr) != NULL){
					printf("%s\n", mi->second);
					found = 1;
				}
			}
		}
		if(!found)
			cout << "Sorry! string \"" << tmpStr << "\" is not found! >w<" <<endl;
		/*if((tmpStr-'0') < 25 && (tmpStr-'0') > 0){
			chrCase = 1;
		}else if((tmpStr-'A') < 25 && (tmpStr-'A') > 0){
			chrCase = 2;
		}else if((tmpStr-'a') < 25 && (tmpStr-'a') > 0){
			chrCase = 3;
		}*/
		cout << "======================" <<endl;
	}

	return 0;
}
