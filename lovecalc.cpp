#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int getnum(string s);
int main(int argc, char *argv[]) {
	while (true) {
		string a, b;
		getline(cin, a);
		if (a == "") break;
		getline(cin, b);
		int x = getnum(a);
		int y = getnum(b);
		double ratio = 0;
		if (y == 0 && x == 0) ;
		else if (y >= x) ratio = 100 * ((double) x) / y;
		else ratio = 100 * y / ((double) x);
		cout << fixed << setprecision(2) << ratio << " %" << endl;
	}
}

int getnum(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		int a = 1 + s[i] - 'A';
		if (a < 1 || a > 58 || (a > 26 && a <= 32)) continue;
		if (a > 32) a -= 32;
		sum += a;
	}
	while (sum >= 10) {
		int newsum = 0;
		int sumcut = sum;
		while (sumcut > 0) {
			newsum += sumcut % 10;
			sumcut /= 10;
		}
		sum = newsum;
	}
	return sum;
}