#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int todig (char c) {
	switch (c) {
		case 'V': return 0;
		case 'U': return 1;
		case 'C': return 2;
		default: return 3;
	}
}

int tonum (string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum = 4 * sum + todig(s[i]);
	}
	return sum;
}


int main() {
	int k;
	cin >> k;
	cout << "COWCULATIONS OUTPUT\n";
	for (int c = 0; c < k; c++) {
		string n1, n2;
		cin >> n1 >> n2;
		int num1 = tonum(n1), num2 = tonum(n2);
		
		for (int i = 0; i < 3; i++) {
			string op;
			cin >> op;
			if (op == "R") num2 /= 4;
			if (op == "L") num2 *= 4;
			if (op == "A") num2 += num1;
		}
		string final;
		cin >> final;
		bool ok = num2 == tonum(final);
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	cout << "END OF OUTPUT\n";
}


