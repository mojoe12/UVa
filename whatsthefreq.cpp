#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	for (getline(cin, s); s != ""; getline(cin, s)) {
		vector<int> counts (52);
		for (int i = 0; i < s.length(); i++) {
			int n = s[i] - 'A';
			if (n > 25) n -= 6;
			if (n < 0 || n > 51) continue;
			counts[n]++;
		}
		string bestchars;
		int bestcount = 0;
		for (int i = 0; i < 52; i++) {
			char c = (i > 25) ? ('A' + i + 6) : ('A' + i);
			if (counts[i] > bestcount) {
				bestcount = counts[i];
				bestchars = "";
				bestchars += c;
			}
			else if (counts[i] == bestcount) {
				bestchars += c;
			}
		}
		cout << bestchars << ' ' << bestcount << endl;
	}
}