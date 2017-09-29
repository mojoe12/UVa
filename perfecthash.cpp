#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {
	
	string s;
	while (getline(cin, s)) {
		
		vector<int> w;
		w.reserve(count(s.begin(), s.end(), ' '));
		
		int currw = 0;
		for (int i = 0; i <= s.length(); i++) {
			if (i == s.length() || s[i] == ' ') {
				if (currw) w.push_back(currw);
				currw = 0;
			}
			else {
				currw = 32 * currw + (s[i] - 'a' + 1);
			}
		}
		
		int n = w.size();
		int c = 1;
		
		while (true) {
			int maxnewc = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i+1; j < n; j++) {
					int fi = c / w[i], fj = c / w[j];
					
					if (fi % n == fj % n) {
						int newc = min(w[i] * (1 + fi), w[j] * (1 + fj));
						maxnewc = max(maxnewc, newc);
					}
				}
			}
			if (!maxnewc) break;
			else c = maxnewc;
		}
		
		cout << s << endl << c << endl << endl;
		
	}




}


