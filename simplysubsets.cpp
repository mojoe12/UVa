#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int tonum (string s) {
	int num = 0, i = 0;
	bool ifneg = (s[0] == '-');
	for (int i = ifneg; i < s.size(); i++) {
		num = 10 * num + (s[i] - '0');
	}
	if (ifneg) num *= -1;
	return num;
}

void parse (string s, vector<int>& nums, set<int>& numset, char delim = ' ') {
	string cnum = "";
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == ' ') {
			if (cnum.size()) {
				nums.push_back(tonum(cnum));
				numset.insert(tonum(cnum));
			}
			cnum = "";
		}
		else {
			cnum.push_back(s[i]);
		}
	}
}


int main() {
	
	string s;
	while (getline(cin, s)) {
		
		vector<int> a;
		set<int> as;
		parse(s, a, as, ' ');
		
		getline(cin, s);
		vector<int> b;
		set<int> bs;
		parse(s, b, bs, ' ');
		
		
		bool asubb = true, bsuba = true;
		bool disjoint = true;
		
		for (int i = 0; i < a.size(); i++) {
			if (bs.count(a[i])) {
				disjoint = false;
			}
			else {
				asubb = false;
			}
		}
		
		for (int i = 0; i < b.size(); i++) {
			if (as.count(b[i])) {
				disjoint = false;
			}
			else {
				bsuba = false;
			}
		}
		
		if (asubb && bsuba) cout << "A equals B\n";
		else if (asubb) cout << "A is a proper subset of B\n";
		else if (bsuba) cout << "B is a proper subset of A\n";
		else if (disjoint) cout << "A and B are disjoint\n";
		else cout << "I'm confused!\n";
	}



}


