#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long sum (long long x, vector<int>& coes, long long i) {
	if (i < 0) return 0;
	long long n = coes.size();
	return (n - i - 1) * coes[i] + x * sum(x, coes, i-1);
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
		
		int x = tonum(s);
		getline(cin, s);
		vector<int> coes;
		parse(s, coes, ' ');
		
		cout << sum(x, coes, coes.size()-2) << endl;
		
	}
}


