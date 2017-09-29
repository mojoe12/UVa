#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>


using namespace std;



int main() {
	
	int n, k;
	while (true) {
		int n, k;
		cin >> n >> k;
		if (n == -1 && k == -1) break;
		
		vector<int> coes (n+1);
		for (int i = 0; i <= n; i++) cin >> coes[n-i];
		// first is an, then an-1, ..., a0
		
		int cdeg = 0; 
		while (cdeg + k <= n) 
		{
			coes[cdeg + k] -= coes[cdeg];
			coes[cdeg] = 0;
			cdeg++;
		}
		
		bool notzero = false;
		stack<int> printout;
		for (int i = 0; i < coes.size(); i++) {
			if (!notzero && coes[i]) {
				notzero = true;
				printout.push(coes[i]);
			}
			else if (notzero) printout.push(coes[i]);
		}
		
		if (!printout.size()) cout << 0 << endl;
		else {
			while (printout.size() > 1) {
				cout << printout.top() << ' ';
				printout.pop();
			}
			cout << printout.top() << endl;
		}
	}




}


