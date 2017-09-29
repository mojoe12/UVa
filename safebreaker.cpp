#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

string tostring (int n) {
	string s = "0000";
	for (int i = 0; i < 4; i++) {
		s[3-i] += n % 10;
		n /= 10;
	}
	return s;
}


int main() {
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		
		vector<bool> codes (10000, true);
		 
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int code;
			cin >> code;
			int ncorrect, nclose;
			char x;
			cin >> ncorrect >> x >> nclose;
			
			string corr = tostring(code);
			
			for (int j = 0; j < 10000; j++) {
				if (!codes[j]) continue;
				
				string guess = tostring(j);
				
				int strong = 0, weak = 0;
				
				vector<int> guesscounts (10, 0);
				vector<int> corrcounts (10, 0);
				for (int k = 0; k < 4; k++) {
					if (guess[k] == corr[k]) strong++;
					else {
						guesscounts[guess[k] - '0']++;
						corrcounts[corr[k] - '0']++;
					}
				}
				
				for (int k = 0; k < 10; k++) {
					if (guesscounts[k] && corrcounts[k]) weak += min(guesscounts[k], corrcounts[k]);
				}
				
				codes[j] = ncorrect == strong && nclose == weak;
				
			}
		}
		
		vector<bool>::iterator it = find(codes.begin(), codes.end(), true);
		if (it == codes.end()) cout << "impossible\n";
		else {
			vector<bool>::iterator it2 = find(it+1, codes.end(), true);
			int num = it - codes.begin();
			string s = tostring(num);
			if (it2 == codes.end()) cout << s << endl;
			else cout << "indeterminate\n";
		}
		
	}




}


