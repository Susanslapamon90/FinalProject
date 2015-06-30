#include <vector>
#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;

struct singletransferinfo{
        string id;
        int priority;
        bool tofrom;
        unsigned long long money;
        struct singletransferinfo *bro;
};
typedef struct singletransferinfo STI;

bool cmp(STI *a, STI *b);
void mymerge(vector<STI *>& a, vector<STI *>& b, vector<STI *>& vtmp);

class THistory{
public:
	vector<STI *> stilist;
		
	THistory(){
		stilist.clear();
	}
	THistory(string i, int p, bool t, int m){
		STI *stitmp = new STI; 
		stitmp->id = i;
		stitmp->priority = p;
		stitmp->tofrom = t;
		stitmp->money = m;
		stitmp->bro = NULL;
		stilist.push_back(stitmp);
	}	
	~THistory(){
		stilist.clear();
	}
	void hadd(string i, int p, bool t, int m){	
		STI *stitmp = new STI; 
		stitmp->id = i;
		stitmp->priority = p;
		stitmp->tofrom = t;
		stitmp->money = m;
		stitmp->bro = NULL;
		stilist.push_back(stitmp);
	}
	void hpair(THistory& b){
		(*(stilist.end()-1))->bro = *(b.stilist.end()-1);
		(*(b.stilist.end()-1))->bro = *(stilist.end()-1);			
	}
	void hmerge(THistory& b, string ID){
		vector<STI *>::iterator i;
		for(i = b.stilist.begin(); i != b.stilist.end(); i++)
			if((*i)->bro != NULL)
				(*i)->bro->id = ID;
		vector<STI *> vtmp;
		vtmp.reserve(stilist.size()+b.stilist.size()+1);
		mymerge(stilist, b.stilist, vtmp);
		stilist.clear();
		stilist.reserve(vtmp.size());
		for(i = vtmp.begin(); i != vtmp.end(); i++){
			STI *ptr = (*i);
			stilist.push_back(ptr);
		}
	}
	void hsearch(string ID){
		vector<STI *>::iterator i;
		int flag = 0;
		for(i = stilist.begin(); i != stilist.end(); i++)
			if(ID == (*i)->id){
				if((*i)->tofrom)		
					printf("To ");
				else
					printf("From ");
				cout << (*i)->id;
				printf(" %llu\n", (*i)->money);
				flag = 1;
			}
		if(!flag)
			printf("no record\n");
	}
	void hdelete(){
		vector<STI *>::iterator i;
		for(i = stilist.begin(); i != stilist.end(); i++){
			delete (*i);
			(*i) = NULL;
		}	
	}
};           
