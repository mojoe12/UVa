#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		int n;
		cin >> n;
		string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
		string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
		vector<string> cards (52);
		for (int i = 0; i < 52; i++) {
			string newcard = ranks[i % 13];
			newcard = newcard + " of ";
			newcard = newcard + suits[i / 13];
			cards[i] = newcard;
		}
		
		vector< vector<int> > shuffles (n, vector<int> (52));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 52; j++) {
				cin >> shuffles[i][j];
			}
		}
		
		string s;
		getline(cin, s);
		while (getline(cin, s)) {
			if (s == "") break;
			int shuffle = stoi(s);
			vector<string> newcards (52);
			for (int j = 0; j < 52; j++) {
				newcards[j] = cards[shuffles[shuffle-1][j]-1];
			}
			cards = newcards;
		}
		
		for (int i = 0; i < 52; i++) {
			cout << cards[i] << endl;
		}
	}
}