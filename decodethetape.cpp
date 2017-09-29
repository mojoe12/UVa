#include <iostream>

using namespace std;

int getNum (string s) {
	int x = 0;
	for (int i = 2; i < 10; i++) 
	{
		int e = (i < 7) ? 8-i : 9-i;
		if (s[i] == 'o') x += (1 << e);
	}
	return x;
}


int main(int argc, char *argv[]) {

	string s;
	getline(cin, s);
	string ans = "";
	for (getline(cin, s); s[0] != '_'; getline(cin, s)) {
		int n = getNum(s);
		char c = ' ';
		c += n - 32;
		ans += c;
	}
	cout << ans;
}