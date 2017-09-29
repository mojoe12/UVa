#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		if (!n) break;
		
		// can you reserve for sets?
		vector<int> s;
		s.reserve(n);
		for (int i = 0; i < n; i++) {
			int snum;
			cin >> snum;
			s.push_back(snum);
		}
		sort(s.begin(), s.end());
		
		int maxd = 0;
		bool iffound = false;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					int d = s[i] + s[j] + s[k];
					bool distinct = d != s[i] && d != s[j] && d != s[k];
					bool contains = binary_search(s.begin(), s.end(), d);
					if (distinct && contains) {
						if (iffound) maxd = max(maxd, d);
						else {
							iffound = true;
							maxd = d;
						}
					}
				}
			}
		}
		
		if (iffound) cout << maxd << endl;
		else cout << "no solution\n";
		
	}




}


