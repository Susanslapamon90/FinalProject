#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
extern "C" {
	#include "avl_ntudsa.h"	
}
using namespace std;

class Game{
public:
	int id;
	int price;
	Game(){
		id = 0;
		price = 0;
	}
	Game(const int a, const int b){
		id = a;
		price = b;
	}
	bool operator<(const Game& gg) const{
		return (this->price < gg.price);
	}
	bool operator==(const Game& gg) const{
		return (this->id == gg.id);
	}
	bool operator()(const int& gg) const{
		return (this->id < gg);
	}
};

class User{
public:
	set<Game> game;
};

void processRob(User* user, int* owner){
	int i, j, size;
	scanf("%d%d", &i, &j);
	int originJ = owner[j];
	set<Game>::iterator it = user[owner[j]].game.begin();

	if(owner[i] != owner[j]){
		for(it = user[owner[j]].game.begin(); it != user[originJ].game.end(); it++){
			user[owner[i]].game.insert(*it);
			owner[it->id] = owner[i];
		}
		user[originJ].game.clear();
	}
}

void processAsk(User* user, int* owner){
	int i, s, tot = 0, cnt = 0;
	scanf("%d%d", &i, &s);
	set<Game>::iterator it;
	for(it = user[owner[i]].game.begin(); it != user[owner[i]].game.end(); it++){
	}
	for(it = user[owner[i]].game.begin(); it != user[owner[i]].game.end(); it++){
		tot += it->price;
		if(s < tot)
			break;
		cnt++;
	}
	printf("%d %d\n", owner[i], cnt);
}

int main(){
	int n, m, command;
	scanf("%d%d", &n, &m);
	//int* prices = new int[n+1];
	int* owner = new int[n+1];
	User* user = new User[n+1]; 

	for(int itr = 1; itr <= n; itr++){
		Game* tmp = new Game();
		scanf("%d", &tmp->price);
		tmp->id = itr;
		user[itr].game.insert(*tmp);
		owner[itr] = itr;
	}

	for (int itr = 0; itr < m; itr++){
		scanf("%d", &command);
		switch(command){
			case 1:
				processRob(user, owner);
				break;
			case 2:
				processAsk(user, owner);
				break;
			default:
				exit(-1);
		}
	}

	return 0;
}