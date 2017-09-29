#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int suit(char c);
int Rank(char c);
bool comp (pair<char, char> i, pair<char, char> j);


int main(int argc, char *argv[]) {
	while (1) {
		char dealer;
		cin >> dealer;
		if (dealer == '#') break;
		
		pair<char, char> input;
		vector<vector<pair<char, char> > > cards (4, vector<pair<char, char> > (13) );

		int x = 1;
		if (dealer == 'W') x = 2;
		else if (dealer == 'N') x = 3;
		else if (dealer == 'E') x = 0;
		
		for (int i = 0; i < 52; i++) {
			cin >> input.first;
			cin >> input.second;
			cards[(x+i) % 4][i/4] = input;
		}
		for (int i = 0; i < 4; i++) {
			sort(cards[i].begin(), cards[i].end(), comp);
		}
		
		cout << "S: " << cards[0][0].first << cards[0][0].second;
		for (int i = 1; i < 13; i++) cout << ' ' << cards[0][i].first << cards[0][i].second;
		cout << endl << "W: " << cards[1][0].first << cards[1][0].second;
		for (int i = 1; i < 13; i++) cout << ' ' << cards[1][i].first << cards[1][i].second;
		cout << endl << "N: " << cards[2][0].first << cards[2][0].second;
		for (int i = 1; i < 13; i++) cout << ' ' << cards[2][i].first << cards[2][i].second;
		cout << endl << "E: " << cards[3][0].first << cards[3][0].second;
		for (int i = 1; i < 13; i++) cout << ' ' << cards[3][i].first << cards[3][i].second;
		cout << endl;
	}
}

int suit(char c) {
	switch (c) {
		case 'H': return 4;
		case 'S': return 3;
		case 'D': return 2;
		case 'C': return 1;
		default: return 0;
	}
}

int Rank(char c) {
	switch (c) {
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		case 'J': return 11;
		case 'T': return 10;
		default: return (c - '0');
	}
}

bool comp (pair<char, char> i, pair<char, char> j) {
	if (i.first != j.first) return suit(i.first) < suit(j.first);
	return Rank(i.second) < Rank(j.second);
}