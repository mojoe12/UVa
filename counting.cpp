#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		if (s.length() == 5) cout << 3;
		else if (s[0] == 't' || s[0] == 'w') cout << 2;
		else cout << 1;
		cout << endl;
	}
}