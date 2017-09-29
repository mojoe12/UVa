#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool ifhard(string s);
void getseq (int n, int l, string s, int& counter, string& ans);
int main() {
	
	// setup input
	int n, l;
	while (cin >> n >> l) {
		if (!n) break;
		
		string ans = "";
		int c = 0;
		getseq(n, l, "", c, ans);
		
		for (int i = 0; i < ans.length(); i++) {
			cout << ans[i];
			if (i == ans.length()-1) continue;
			else if (i == 63) cout << endl;
			else if (i > 0 && (i+1) % 4 == 0) cout << ' ';
		}
		cout << endl << ans.length() << endl;
	}
}

bool ifhard(string s) {
	for (int siz = 1; siz <= s.length()/2; siz++) {
		for (int i = 0; i <= s.length() - 2 * siz; i++) {
			if (s.substr(i, siz) == s.substr(i+siz, siz)) return false;
		}
	}
	return true;
}
void getseq (int n, int l, string s, int& counter, string& ans) 
{	
	if (ans.length()) return;
	if (counter == n) {
		ans = s;
		return;
	}
	
	for (int i = 0; i < l; i++) {
		char c = 'A' + i;
		s += c;
		if (ifhard(s)) {
			counter++;
			getseq(n, l, s, counter, ans);
		}
		s.pop_back();
	}
} 