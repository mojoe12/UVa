#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long power (long long b, long long e) {
	return round(pow(b, e));
}

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
		vector<int> coes;
		parse(s, coes, ' ');
		int n = coes.size();
		
		getline(cin, s);
		vector<int> xvals;
		parse(s, xvals, ' ');
		
		for (int i = 0; i < xvals.size(); i++) {
			long long ans = 0;
			for (int j = 0; j < n; j++) {
				ans += coes[j] * power(xvals[i], n - j - 1);
			}
			if (i) cout << ' ';
			cout << ans;
		}
		cout << endl;
		
	}




}


