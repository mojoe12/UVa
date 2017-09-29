#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int y;
	while (cin >> y) {
		if (!y) break;
		long double nbits = 4 * pow(2, y/10 - 196);
		int n = 1;
		double log2sum = 0;
		while (true) {
			n++;
			log2sum += log2(n);
			if (floor(log2sum) + 1 > nbits) break;
		}
		cout << n-1 << endl;
	}



}