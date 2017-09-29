#include <iostream>

using namespace std;

int main() {
	
	// setup input
	
	int k, q, nq;
	while (cin >> k >> q >> nq) {
		bool statelegal = (k != q);
		bool movelegal = (q/8 == nq/8 || q%8 == nq%8) && nq != k && nq != q;
		if (q/8 == nq/8 && k/8 == nq/8 && ((k > nq && q > k) || (k < nq && q < k))) movelegal = false;
		if (q%8 == nq%8 && k%8 == nq%8 && ((k > nq && q > k) || (k < nq && q < k))) movelegal = false;

		bool moveallowed = (nq != k+1 || k % 8 == 7) && (nq != k-1 || k % 8 == 0) && nq != k+8 && nq != k-8;
		bool locked = (k == 0 && nq == 9) || (k == 7 && nq == 14) || (k == 56 && nq == 49) || (k == 63 && nq == 54);
		
		if (!statelegal) cout << "Illegal state\n";
		else if (!movelegal) cout << "Illegal move\n";
		else if (!moveallowed) cout << "Move not allowed\n";
		else if (locked) cout << "Stop\n";
		else cout << "Continue\n";
	}
}