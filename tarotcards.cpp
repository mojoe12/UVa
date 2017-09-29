#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool ifOudler(string s);
int point(string s);
bool equal(string a, string b);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	
	string s;
	getline(cin, s);
	for (int c = 1; c <= k; c++) {
		
		int n;
		cin >> n;
		getline(cin, s);
		
		int numo = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			if (ifOudler(s)) numo++;
			sum += point(s);
		}
		sum /= 2;
		
		if (c > 1) cout << endl;
		cout << "Hand #" << c << endl;
		
		int needed = 56;
		if (numo == 1) needed = 51;
		else if (numo == 2) needed = 41;
		else if (numo == 3) needed = 36;
		
		int diff = sum - needed;
		if (diff >= 0) cout << "Game won by ";
		else cout << "Game lost by ";
		cout << abs(diff) << " point(s).\n";
	}
}

bool ifOudler(string s) {
	return (s == "fool") || (s == "one of trumps") || (s == "twenty-one of trumps");
}

int point(string s) {
	if (ifOudler(s)) return 9;
	if (equal(s, "king")) return 9;
	if (equal(s, "queen")) return 7;
	if (equal(s, "knight")) return 5;
	if (equal(s, "jack")) return 3;
	return 1;
}

bool equal(string a, string b) {
	int l = min(a.length(), b.length());
	for (int i = 0; i < l; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}