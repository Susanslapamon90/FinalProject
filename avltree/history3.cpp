#include "history3.h"

bool cmp(STI *a, STI *b){
	assert(a != NULL);
	assert(b != NULL);
	return (a->priority < b->priority);
}

void mymerge(vector<STI *>& a, vector<STI *>& b, vector<STI *>& vtmp){
	vector<STI *>::iterator i = a.begin(); 
	vector<STI *>::iterator j = b.begin();
	while(i != a.end() && j != b.end()){
		if((*i)->priority <= (*j)->priority){
			vtmp.push_back((*i));
			i++;
		}
		else{
			vtmp.push_back((*j));
			j++;
		}
	}
	while(i != a.end()){
		vtmp.push_back((*i));
		i++;
	}
	while(j != b.end()){
		vtmp.push_back((*j));
		j++;
	}
	return;
}