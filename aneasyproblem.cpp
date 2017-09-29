#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int todig (char c) {
	if (c <= '9') return c - '0';
	if (c <= 'Z') return c - 'A' + 10;
	return c - 'a' + 36;
}


bool possible (string s, int b) {
	int n = s.size();
	int sum = 0;
	for (int i = (s[0] == '-' || s[0] == '+'); i < n; i++) {
		int digit = todig(s[i]);
		if (digit >= b) return false;
		sum += digit;
	}
	return sum % (b-1) == 0;
}


int main() {
	
	string s;
	while (cin >> s) {
		int i = 2;
		while (i < 63 && !possible(s, i)) i++;
		if (i == 63) cout << "such number is impossible!\n";
		else cout << i << endl;
	}




}


