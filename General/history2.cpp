#include "history2.h"

bool cmp(STI *a, STI *b){
	assert(a != NULL);
	assert(b != NULL);
	return (a->priority < b->priority);
}
