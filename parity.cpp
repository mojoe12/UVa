#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


string tobase (int n, int b) {
	string s = "";
	while (n) {
		string news = "";
		news += '0' + n % b;
		s = news + s;
		n /= b;
	}
	return s;
}

int num1s (string s) {
	int p = 0;
	for (int i = 0; i < s.length(); i++) {
		p += s[i] - '0';
	}
	return p;
}


int main() {
	
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		string binary = tobase(n, 2);
		cout << "The parity of " << binary;
		cout << " is " << num1s(binary) << " (mod 2).\n";
	}



}


