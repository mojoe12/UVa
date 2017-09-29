#include <iostream>
#include <algorithm>

using namespace std;


string changeBase (string num, int base0, int basef);
int myPow (int n, int e);
string reverse (string s);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string num;
		cin >> num;
		string as = changeBase(num, 10, 2);
		string bs = changeBase(num, 16, 2);
		int a = count(as.begin(), as.end(), '1');
		int b = count(bs.begin(), bs.end(), '1');
		cout << a << ' ' << b << endl;
	}
}

int myPow (int n, int e) {
	return (e == 0) ? 1 : n * myPow(n,e-1);
}

string reverse (string s) {
	string news;
	for (int i = s.length()-1; i > -1; i--) {
		news += s[i];
	}
	return news;
}

string changeBase (string num, int base0, int basef) {
	int base10 = 0;
	for (int i = 0; i < num.length(); i++) {
		char c = num[i];
		int digit = c - '0';
		if (digit > 9) digit -= 8;
		base10 += digit * myPow (base0, num.length() - i - 1);
	}
	int div = base10;
	string retval = "";
	while (div > 0) {
		char c = '0';
		c += div % basef;
		if (c > '9') c += 8;
		retval += c;
		div /= basef;
	}
	return reverse(retval);
}