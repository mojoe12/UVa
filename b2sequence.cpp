#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;



int main() {
	
	int n;
	for (int c = 1; cin >> n; c++) {
		vector<int> bs;
		bs.reserve(n+1);

		bool ifb2seq = true;
		for (int i = 0; i < n; i++) {
			int b;
			cin >> b;
			if (b < 1 || b <= bs[bs.size()-1]) ifb2seq = false;
			bs.push_back(b);
		}
		
		set<int> sums;
		for (int i = 0; i < n && ifb2seq; i++) {
			for (int j = i; j < n && ifb2seq; j++) {
				int sum = bs[i] + bs[j];
				if (sums.count(sum)) ifb2seq = false;
				else sums.insert(sum);
			}
		}
		
		cout << "Case #" << c << ": It is ";
		if (!ifb2seq) cout << "not ";
		cout << "a B2-Sequence.\n\n";
	}



}


