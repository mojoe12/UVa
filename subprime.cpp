#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int nbanks, ndebts;
		cin >> nbanks >> ndebts;
		if (nbanks == 0 && ndebts == 0) break;
		vector<int> balances (nbanks);
		for (int i = 0; i < nbanks; i++) cin >> balances[i];
		for (int d = 0; d < ndebts; d++) {
			int b2give, b2get, amount;
			cin >> b2give >> b2get >> amount;
			balances[b2give-1] -= amount;
			balances[b2get-1] += amount; 
		}
		bool ifpossible = true;
		for (int i = 0; i < nbanks && ifpossible; i++) {
			if (balances[i] < 0) ifpossible = false;
		}
		if (ifpossible) cout << "S" << endl;
		else cout << "N" << endl;
	}
}