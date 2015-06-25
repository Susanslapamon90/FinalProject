#include "history.h"

void mymerge(vector<STI>& owner, vector<STI>& belong, vector<STI>& tmp, string& ID){
	vector<STI>::iterator i, j;
	i = owner.begin();
	j = belong.begin();
	while(i != owner.end() && j != belong.end()){
		if((*i).priority <= (*j).priority){
			tmp.push_back((*i));
			if((*i).bro != NULL)
				(*i).bro->bro = &(*(tmp.end()-1));	
			i++;
		}
		else{
			tmp.push_back((*j));
			if((*j).bro != NULL){
				strncpy((*j).bro->id, ID.c_str(), sizeof((*j).bro->id));
				(*j).bro->bro = &(*(tmp.end()-1));	
			}
			j++;
		}
	}
	while(i != owner.end()){
		tmp.push_back((*i));
		if((*i).bro != NULL)
			(*i).bro->bro = &(*(tmp.end()-1));	
		i++;
	}
	while(j != belong.end()){
		tmp.push_back((*j));
		if((*j).bro != NULL){
			strncpy((*j).bro->id, ID.c_str(), sizeof((*j).bro->id));
			(*j).bro->bro = &(*(tmp.end()-1));	
		}
		j++;
	}
}
