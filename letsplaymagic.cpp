#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		int pos = -1;
		vector<string> cards (n);
		fill(cards.begin(), cards.end(), "  ");
		for (int i = 0; i < n; i++) {
			string card, length;
			cin >> card >> length;
			for (int j = 0; j < length.length(); pos = (pos+1) % n) {
				if (cards[(pos + 1) % n] == "  ") {
					j++;
				}
			}
			cards[pos] = card;
		}
		cout << cards[0];
		for (int i = 1; i < n; i++) cout << " " << cards[i];
		cout << endl;
	}
}