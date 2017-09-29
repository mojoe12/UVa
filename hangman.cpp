#include <iostream>
#include <vector>
using namespace std;

int main() {
	while (true) {
		int rnum;
		cin >> rnum;
		if (rnum == -1) break;
		string word, guesses;
		cin >> word >> guesses;
		int badtries = 0, numspaces = 0;
		vector<char> tries (0);
		bool iflost = false;
		for (int i = 0; i < guesses.length(); i++) {
			char c = guesses[i];
			
			bool iftried = false;
			for (int j = 0; j < tries.size(); j++) {
				if (tries[j] == c) iftried = true;
			}
			if (iftried) continue;
			else tries.push_back(c);
			
			bool ifgood = false;
			for (int j = 0; j < word.length(); j++) {
				if (word[j] == c) {
					word[j] = ' ';
					numspaces++;
					ifgood = true;
				}
			}
			if (!ifgood && numspaces < word.length()) {
				badtries++;
			}
		}
		cout << "Round " << rnum << endl;
		if (badtries >= 7) {
			cout << "You lose.\n";
			continue;
		}
		bool ifwon = true;
		for (int i = 0; i < word.length(); i++) {
			ifwon = ifwon && (word[i] == ' ');
		}
		if (ifwon) cout << "You win.\n";
		else cout << "You chickened out.\n";
	}
}