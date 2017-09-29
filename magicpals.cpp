#include <iostream>
#include <string>
#include <vector>
using namespace std;
string purify(string s);
int squirt(int x);
bool ifmagic (string s);
bool ifpal (string s);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin,s);
	for (int c = 1; c <= k; c++) {
		getline(cin,s);
		cout << "Case #" << c << ":" << endl;
		s = purify(s);
		int sqrt = squirt(s.length());
		if (sqrt && ifpal(s)) cout << sqrt << endl;
		else cout << "No magic :(" << endl;
	}
}

string purify(string s) {
	string x = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - 'a' > -1 && s[i] - 'a' < 26) x += s[i];
	}
	return x;
}

int squirt (int x) {
	for (int i = 1; i <= 100; i++) {
		if (x == i * i) return i;
	}
	return 0;
}

bool ifmagic(string s) {
	int sqrt = squirt(s.length());
	vector< vector<char> > square (sqrt, vector<char> (sqrt));
	int i = 0, j = 0, c = 0;
	while (c < s.length()) {
		square[i][j] = s[c++];
		if (j == sqrt-1) {
			i++;
			j = 0;
		}
		else j++;
	}
	vector<string> diags (2*sqrt-1);
	vector<int> isubi (2*sqrt-1);
	vector<int> jsubi (2*sqrt-1);
	int x = 0;
	for (int a = 0; a < sqrt; a++) {
		isubi[x] = a;
		jsubi[x++] = 0;
	}
	for (int a = 1; a < sqrt; a++) {
		isubi[x] = sqrt-1;
		jsubi[x++] = a;
	}
	for (int a = 0; a < 2*sqrt-1; a++) {
		string addition = "";
		int i = isubi[a], j = jsubi[a];
		while (i >= 0 && j < sqrt) {
			addition += square[i][j];
			i--;
			j++;
		}
		if (!ifpal(addition)) return false;
	}
	return true;
	
}

bool ifpal(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i-1]) return false;
	}
	return true;
}