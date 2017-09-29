#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int four (vector< pair<char, char> >& cards);
int three(vector< pair<char, char> >& cards);
int suitcount (vector< pair<char, char> >& cards, char suit);
bool ifstopped (vector< pair<char, char> >& cards, char suit);
char most(vector< pair<char, char> >& cards);

int main(int argc, char *argv[]) {
	string s;
	while (getline(cin, s)) {
		vector<pair<char, char> > cards;
		for (int i = 0; i < 38; i += 3) {
			cards.push_back( make_pair(s[i], s[i+1]));
		}
		
		if (four(cards) + three(cards) < 14) {
			cout << "PASS\n";
			continue;
		}
		else if (four(cards) > 15 && ifstopped(cards, 'S') && ifstopped(cards, 'H') && ifstopped(cards, 'D') && ifstopped(cards, 'C')) {
			cout << "BID NO-TRUMP\n";
			continue;
		}
		else {
			cout << "BID " << most(cards) << endl;
		}
	}
}

int four (vector< pair<char, char> >& cards) {
	int total = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].first == 'A') total += 4;
		else if (cards[i].first == 'K') {
			total += 3;
			if ( suitcount(cards, cards[i].second) < 2) total--;
		}
		else if (cards[i].first == 'Q') {
			total += 2;
			if ( suitcount(cards, cards[i].second) < 3) total--;
		}
		else if (cards[i].first == 'J') {
			total++;
			if ( suitcount(cards, cards[i].second) < 4) total--;
		}
	}
	return total;
}

int three(vector< pair<char, char> >& cards) {
	int total = 0;
	char suits[4] = {'S', 'H', 'D', 'C'};
	for (int i = 0; i < 4; i++) {
		char suit = suits[i];
		if (suitcount(cards, suit) == 2) total++;
		else if (suitcount(cards, suit) < 2) total += 2;
	}
	return total;
}

int suitcount (vector< pair<char, char> >& cards, char suit) {
	int count = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].second == suit) count++;
	}
	return count;
}

bool ifstopped (vector< pair<char, char> >& cards, char suit) {
	
	int count = suitcount(cards, suit);
	if (find(cards.begin(), cards.end(), make_pair('A', suit) )!= cards.end()) return true;
	if (find(cards.begin(), cards.end(), make_pair('K', suit) )!= cards.end() && count > 1) return true;
	if (find(cards.begin(), cards.end(), make_pair('Q', suit) )!= cards.end() && count > 2) return true;
	return false;
}

char most(vector< pair<char, char> >& cards) {
	// s h d c
	vector<int> counts (4);
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].second == 'S') counts[0]++;
		else if (cards[i].second == 'H') counts[1]++;
		else if (cards[i].second == 'D') counts[2]++;
		else if (cards[i].second == 'C') counts[3]++;
	}
	int max = 0, maxi = 0;
	for (int i = 0; i < 4; i++) {
		if (counts[i] > max) {
			max = counts[i];
			maxi = i;
		}
	}
	char suits[4] = {'S', 'H', 'D', 'C'};
	return suits[maxi];
}