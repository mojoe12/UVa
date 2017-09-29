#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void findperms(string& s, vector<string>& perms);
int factorial(int i);

int main() {

	string s;
	bool iffirst = true;
	while (cin >> s) {
		if (!iffirst) cout << endl;
		else iffirst = false;
		int n = s.length();
		vector<string> perms(factorial(n));
		findperms(s, perms);
		for (int i = 0; i < perms.size(); i++) cout << perms[i] << endl;
	}
}

void findperms(string& s, vector<string>& perms) {
	int n = s.length(), counter = 0;

	char c = s[n-1];
	s.pop_back();
	int newsize = factorial(n - 1);
	vector<string> subperms(newsize);
	if (n > 1) findperms(s, subperms);
	for (int j = 0; j < subperms.size(); j++) {
		for (int k = 0; k < n; k++) {
			string x = subperms[j];
			x.insert(x.begin() + k, c);
			if (counter < perms.size()) perms[counter++] = x;
		}
	}
}

int factorial(int i) {
	if (i <= 1) return 1;
	return i * factorial(i - 1);
}*/