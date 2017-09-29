#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	cout << "PERFECTION OUTPUT\n";
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int sumdiv = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) sumdiv += i;
		}
		string num = to_string(n);
		for (int i = 0; i < 5 - num.length(); i++) cout << ' ';
		cout << num << "  ";
		if (sumdiv > n) cout << "ABUNDANT\n";
		else if (sumdiv == n) cout << "PERFECT\n";
		else cout << "DEFICIENT\n";
	}
	cout << "END OF OUTPUT\n";
}