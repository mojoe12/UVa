#include <iostream>
#include <algorithm>
using namespace std;
bool comp (char a, char b) {
	if (a - 'A' == b  - 'a') return true;
	else if (a - 'a' == b - 'A') return false;
	return tolower(a) < tolower(b);
}
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string word;
		cin >> word;
		sort(word.begin(), word.end(), comp);
		do {
			cout << word << endl;
		}
		while (next_permutation(word.begin(), word.end(), comp));
	}
}