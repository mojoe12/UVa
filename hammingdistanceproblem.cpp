#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void problem (string, int, int);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		int n, h;
		cin >> n >> h;
		string s = "";
		problem(s, n, h);
	}
}


void problem (string s, int n, int h) {
	
	int c = count(s.begin(), s.end(), '1');
	if (c == h && s.length() == n) {
		cout << s << endl;
		return;
	}
	
	else if (s.length() < n) {
		s += '0';
		problem(s, n, h);
		s = s.substr(0, s.length()-1);
		if (c < h) {
			s += '1';
			problem(s, n, h);
			s = s.substr(0, s.length()-1);
		}
	}
	
}
