#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool norepeat (int n) {
	vector<int> digs (10);
	while (n) {
		if (n % 10 == 0 || digs[n % 10]) return false;
		digs[n % 10]++;
		n /= 10;
	}
	return true;
}


bool runaround (int n) {
	string s = "";
	while (n) {
		string x = "";
		x += ('0' + (n % 10));
		s = x + s;
		n /= 10;
	}
	int l = s.length();

	vector<int> counts (l);
	int index = 0;
	for (int i = 0; i < l; i++) {
		int x = s[index] - '0';
		index = (index + x) % l;
		if (counts[index]) return false;
		counts[index]++;
	}
	return count(counts.begin(), counts.end(), 1) == l;
}


int main(int argc, char *argv[]) {
	int n;
	for (int c = 1; cin >> n; c++) {
		if (!n) break;

		int i = n;
		while (1) {
			if (norepeat(i) && runaround(i)) break;
			i++;
		}
 		cout << "Case " << c << ": " << i << endl;
	}
}