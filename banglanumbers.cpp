#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

/* PROBLEMS WITH SPACES*/



using namespace std;

string customret (string s, string name, int n);
string tostr (string s);

int main() {
	string s;
	for (int c = 1; cin >> s; c++) {
		
		cout.width(4);
		cout << right << c << ". ";
		cout << tostr(s) << endl;
	}
}

string customret (string s, string name, int n) {
	string ret = tostr(s.substr(0, s.size() - n));
	if (ret.size()) ret = ret + " " + name;
	string add = tostr(s.substr(s.size()-n, n));
	if (add.size()) return ret + " " + add;
	return ret + " ";
}

string tostr (string s) {
	if (s.size() < 3) {
		if (s[0] > '0') return s;
		else if (s[1] > '0') return s.substr(1, 1);
		else return "";
	}
	if (s.size() < 4) return customret(s, "shata", 2);
	else if (s.size() < 6) return customret(s, "hajar", 3);
	else if (s.size() < 8) return customret(s, "lakh", 5);
	return customret(s, "kuti", 7);
}