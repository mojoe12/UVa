#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool powerof2 (int x) {
	while (x > 1) {
		if (x & 1) return false;
		x = x >> 1;
	}
	return x == 1;
}

int power (int b, int e) {
	return round(pow(b, e));
}
int root (int b, int e) {
	return round(pow(b, 1.0/e));
}

int main() {
	int hinit, nworkers;
	while (cin >> hinit >> nworkers) {
		if (!hinit && !nworkers) break;
		
		int nl = 1;
		int n = 0;
		while (true) {
			if (power(root(hinit, nl), nl) == hinit
			 && power(root(nworkers, nl), nl) == nworkers
			 && (root(hinit, nl) == root(nworkers, nl) + 1 || nworkers == 1)
			) {
				n = root(nworkers, nl);
				break;
			}
			
			nl++;
		}
		
		
		int sumheight = 0, numlazy = 0;
		for (int eachcat = hinit, i = 0; i < nl; i++) {
			int numcatshere = power(n, i);
			numlazy += numcatshere;
			sumheight += eachcat * numcatshere;
			eachcat /= n + 1;
		}
		sumheight += pow(n, nl);
		if (hinit == 1 && nl == 1) {
			numlazy = 0;
			sumheight = 1;
		}
		else if (nl == 1 && powerof2(hinit)) {
			numlazy = round(log(hinit)/log(2));
			sumheight = (1 << (numlazy+1)) - 1;
		}
		cout << numlazy << ' ' << sumheight << endl;
	}




}