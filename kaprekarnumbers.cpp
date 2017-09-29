#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long tonum (string s);
string tostr (long long n);
bool ifkap (long long n);

int main() {
	
	vector<int> allkaps;
	for (int i = 2; i <= 40000; i++) {
		if (ifkap(i)) allkaps.push_back(i);
	}
	
	int k;
	cin >> k;
	
	for (int c = 1; c <= k; c++) {
		if (c > 1) cout << endl;
		int start, end;
		cin >> start >> end;
		cout << "case #" << c << endl;
		bool ifany = false;
		for (int i = 0; i < allkaps.size(); i++) {
			if (allkaps[i] >= start && allkaps[i] <= end) {
				cout << allkaps[i] << endl;
				ifany = true;
			}
		}
		if (!ifany) cout << "no kaprekar numbers\n";
	}
}

bool ifkap (long long n) {
	long long sqr = n * n;
	string s = tostr(sqr);
	for (int i = 1; i <= s.size(); i++) {
		string l = s.substr(0, i), r = s.substr(i, s.size()-i);
		long long lnum = tonum(l), rnum = tonum(r);
		if (lnum && rnum && lnum + rnum == n) return true;
	}
	return false;
}

string tostr (long long n) {
	string s = "", blank = "";
	while (n) {
		blank += ('0' + (n % 10));
		s = blank + s;
		blank = "";
		n /= 10;
	}
	return s;
}

long long tonum (string s) {
	long long num = 0;
	for (int i = 0; i < s.size(); i++) {
		num = 10 * num + (s[i] - '0');
	}
	return num;
}
