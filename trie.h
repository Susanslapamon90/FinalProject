#include <iostream>
#include <string>
#include <set>
using namespace std;

template<class Data>
class trie{
public:
	trie *parent;
	trie *child[128];
	set<int> has_child;
	Data* data;
	trie(){
		data = NULL;
		parent = NULL;
		for(int i = 0; i < 128; i++)
			child[i] = NULL;
	}
	~trie(){
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
				if(i == (int) str.size())
					break;
			}
		}

		if(current != NULL && current -> data != NULL){
			return current;
		}
		return NULL;
	}
	bool insert(const string &str,Data &new_data){
		if(find(str) != NULL) return false;
		trie* current = this;
		trie* ex = NULL;
		for(int i = 0;i <(int) str.size(); i++){
			if(current -> child[int (str[i])] != NULL){
				ex = current;
				current = current -> child[int (str[i])]; 
			}
			else{
				current -> child[int(str[i])] = new trie;
				(current -> has_child).insert(int(str[i]));
				ex = current;
				current = current -> child[int(str[i])];
				current -> parent = ex;
			}
		}
		if(current -> data == NULL){
			current -> data = &new_data;
			return true;
		}
			return false;
	}
	bool erase(const string &str){
		trie* pop = find(str);
		if(pop != NULL){		
			delete pop -> data;
			pop -> data = NULL;
			return true;
		}
		return false;
	}
};
