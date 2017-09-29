#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		vector<int> possibles (10);
		for (int i = 0; i < 10; i++) possibles[i] = i+1;
		int guess;
		while (true) {
			cin >> guess;
			if (guess < 1) break;
			string response;
			getline(cin, response);
			getline(cin, response);
			if (response == "right on") break;
			if (response == "too low") {
				for (int i = 0; i < guess; i++) {
					possibles[i] = 0;
				}
			}
			else if (response == "too high") {
				for (int i = guess-1; i < 10; i++) {
					possibles[i] = 0;
				}
			}
		}
		if (guess < 1) break;
		if (find(possibles.begin(), possibles.end(), guess) == possibles.end()) {
			cout << "Stan is dishonest\n";
		}
		else cout << "Stan may be honest\n";
	}
}