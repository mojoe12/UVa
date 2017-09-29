#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;

// function declarations

int getob (char c) {
	if (c == 'J') return 1;
	if (c == 'Q') return 2;
	if (c == 'K') return 3;
	if (c == 'A') return 4;
	return 0;
}


int main() {
	
	// setup input
	
	string s;
	while (cin >> s) {
		if (s == "#") break;
		
		string dealer = "", player = "", middle = "";
		player = s[1] + player;
		for (int i = 1; i < 52; i++) {
			cin >> s;
			if (i % 2) dealer = s[1] + dealer;
			else player = s[1] + player;
		}
		
		int obligation = 0;
		bool toplay = true; // player goes
		int di = 0, pi = 0;
		while (true)
		{
			
			char card;
			if (toplay) card = player[pi++];
			else card = dealer[di++];
			
			middle += card;
			if (getob(card)) {
				obligation = getob(card);
				toplay = !toplay;
			}
			else if (obligation) {
				obligation--;
				if (obligation == 0) {
					if (toplay) dealer = dealer + middle;
					else player = player + middle;
					middle = "";
					toplay = !toplay;
				}
			}
			else toplay = !toplay;
			
			if (toplay && player.size() == pi) break;
			if (!toplay && dealer.size() == di) break;
		}
		
		if (!toplay) {
			cout << 2;
			cout.width(3);
			cout << right << player.size() - pi << endl;
		}
		else {
			cout << 1;
			cout.width(3);
			cout << right << dealer.size() - di << endl;
		}
	}


	// loop through it, apply function


	// output answer


}

// function definitions

