#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	
	int n;
	for (int c = 1; cin >> n; c++) {
		vector<int> as;
		as.reserve(n);

		bool ifaseq = true;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a < 1 || a <= as[as.size()-1]) ifaseq = false;
			as.push_back(a);
		}
		
		for (int i = 0; i < n && ifaseq; i++) {
			for (int j = i+1; j < n && ifaseq; j++) {
				int sum = as[i] + as[j];
				for (int k = j+1; k < n; k++) {
					if (as[k] == sum) ifaseq = false;
				}
			}
		}
		
		// it's two or more distinct earlier terms
		
		cout << "Case #" << c << ':';
		for (int i = 0; i < as.size(); i++) cout << ' ' << as[i];
		cout << "\nThis is ";
		if (!ifaseq) cout << "not ";
		cout << "an A-sequence.\n";
	}



}


