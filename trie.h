#include <iostream>
#include <string>
using namespace std;

template<class Data>
class trie{
public:
	trie *parent;
	bool has_data;
	trie *child[128];
	Data* data;
	trie(){
		data = NULL;
		parent = NULL;
		for(int i = 0; i < 128; i++)
			child[i] = NULL;
		has_data = false;
	}
	~trie(){
	}
	bool insert(const string &str,Data &new_data){
		trie* current = this;
		trie* ex = NULL;
		for(int i = 0;i < str.size(); i++){
			if(current -> child[int (str[i])] != NULL){
				ex = current;
				current = current -> child[int (str[i])]; 
			}
			else{
				current -> child[int(str[i])] = new trie;
				ex = current;
				current = current -> child[int(str[i])];
				current -> parent = ex;
			}
		}
		if(current -> data == NULL){
			current -> has_data = true;
			current -> data = &new_data;
			return true;
		 }
			return false;
	}
	trie* find(const string &str){
		int i = 0;
		trie* current = this;
		while(1){
			if(current == NULL){	
				return NULL;
			}
			else{
				current = current ->  child[int(str[i])];
				i ++;
				if(i == str.size())
					break;
			}
		}

		if(current -> data != NULL){
			return current;
		}
		return NULL;
	}
	bool erase(const string &str){
		trie* pop = find(str);
		if(pop != NULL){
			trie *current = pop;
			//trie *ex = current -> parent;
				delete current;
			return true;
		}
		return false;
	}
};
