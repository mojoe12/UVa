#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getnum(char rank) {
	switch (rank) {
		case 'A': return  0;
		case 'T': return  9;
		case 'J': return 10;
		case 'Q': return 11;
		case 'K': return 12;
		 default: return rank - '1';
	}
}

int main(int argc, char *argv[]) {
	while (true) {
		vector< vector <char> > card (13, vector<char> (8));
		string input;
		bool ifnat = true;
		for (int i = 0; i < 8 && ifnat; i += 2) {
			for (int j = 12; j >= 0; j--) {
				cin >> input;
				if (input == "#") {ifnat = false; break;}
				card[j][i] = input[0];
				card[j][i+1] = input[1];
			}
		}
		if (!ifnat) break;
		int pile = 12, numlifts = 0;
		char rank, suit;
		while (card[pile].size() > 0) {
			numlifts++;
			rank = card[pile][0];
			suit = card[pile][1];
			card[pile].erase(card[pile].begin(), card[pile].begin() + 2);
			pile = getnum(rank);
		}
		if (numlifts < 10) cout << '0';
		cout << numlifts << ',' << rank << suit << endl;
	}
}