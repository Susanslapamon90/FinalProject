#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*               ΔL    L-1                           */
/* score(u, v) = Σ(i) + Σ((u[i] != v[i])? (L-i) : 0) */
/*              i=1    i=0                           */
/* L = min(u.length(), v.length()) */
/* ΔL = |u.length() - v.length()| */

int score(string u, string v){
	int sum1 = 0, sum2 = 0; /* sum1:length's dif, sum2:character's dif */
	int dL = abs((int)(u.size() - v.size())); /* mentioned above */
	int L = (u.size() < v.size())? u.size() : v.size();
	
	for(int i = 1; i <= dL; i++)
		sum1 += i;

	for(int i = 0; i <= L-1; i++)
		sum2 += (u[i] != v[i])? (L-i) : 0;

	return (sum1 + sum2);
}
