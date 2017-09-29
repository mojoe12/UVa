#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


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

void parse (string s, vector<int>& nums, char delim = ' ') {
	string cnum = "";
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == ' ') {
			if (cnum.size()) nums.push_back(tonum(cnum));
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
		
		int k = tonum(s);
		getline(cin, s);
		
		vector<int> coes;
		parse(s, coes, ' ');
		int n = coes.size();
		
		int cnum = 0;
		vector<int> q (n);
		for (int i = 0; i < n; i++) {
			cnum = coes[i] + cnum * k;
			q[i] = cnum;
		}
		
		cout << "q(x):";
		for (int i = 0; i < n-1; i++) {
			cout << ' ' << q[i];
		}
		cout << "\nr = " << q[n-1] << endl << endl;
		
	}




}


