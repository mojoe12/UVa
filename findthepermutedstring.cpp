#include <iostream>
#include <vector>
#include <string>

using namespace std;
string findperms(string& s, int index);

int main() {

	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string s;
		int index;
		cin >> s >> index;
		cout << findperms(s, index-1) << endl;
	}
}

string findperms(string& s, int index) {
	int n = s.length();
	if (n == 1) return s;
	char c = s[n-1];
	s.pop_back();
	string sub = findperms(s, index / n);
	sub.insert(sub.begin() + (index % n), c);
	return sub;
}