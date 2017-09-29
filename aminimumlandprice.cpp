#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		vector<int> L;
		int n;
		while (cin >> n) {
			if (!n) break;
			L.push_back(n);
		}
		sort(L.begin(), L.end());
		int size = L.size();
		
		int totalsum = 0;
		for (int i = 0; totalsum <= 2500000 && i < size; i++) {
			int l = L[i], exp = size-i;
			int power = 1;
			for (int j = 0; power <= 2500000 && j < exp; j++) power *= l;
			totalsum += power;
		}
		
		if (totalsum > 2500000) cout << "Too expensive\n";
		else cout << totalsum * 2 << endl;
		
	}
}