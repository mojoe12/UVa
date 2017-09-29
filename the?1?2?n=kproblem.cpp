#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


// multiple input

using namespace std;

bool canwork (int n, int k, int i, int csum) {	
	//cout << i << ' ' << csum << endl;
	
	if (n * (n+1) - i * (i-1) < abs(k) - abs(csum)) return false;
	if (i == n+1) return csum == k;
	
	if (canwork(n, k, i+1, csum + i)) return true;
	else return canwork(n, k, i+1, csum - i);
}


// nah cant use backtracking

// use odd and even for this problem

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		int x;
		cin >> x;
		// theres a min n
		//int start = sqrt(abs(x));
		for (int n = 1; ; n++) {
			vector<bool> ifpos;
			ifpos.reserve(n);
			int csum = 0;
			if (canwork(n, x, 1, 0)) {
				cout << n << endl;
				break;
			}
		}
	}




}


