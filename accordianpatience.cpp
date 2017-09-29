#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>


using namespace std;

// function declarations

struct Game {
	char cards [52][52][2];
	int topindex [52];
	int npiles;
	
	Game() {
		for (int i = 0; i < 52; i++) topindex[i] = -1;
		npiles = 52;
	}
	
	char topsuit (int i) {
		return cards[i][topindex[i]][0];
	}
	char toprank (int i) {
		return cards[i][topindex[i]][1];
	}
	void push (int i, char suit, char rank) {
		cards[i][topindex[i]+1][0] = suit;
		cards[i][topindex[i]+1][1] = rank;
		topindex[i]++;
	}
	void pop(int i) {
		topindex[i]--;
		if (topindex[i] < 0) npiles--;
	}
};



int main() {
		
	// setup input
	char c;
	while (scanf(" %c", &c)) {
		if (c == '#') break;
		
		Game game = Game();

		char s = c;
		char r;
		for (int i = 1; ; i++) {
			if (i % 2) {
				scanf("%c", &r);
				game.push(i/2, s, r);
				if (i >= 103) break;
			}
			else {
				scanf(" %c", &s);
			}
		}
		
		int index1 = 0, index2 = 0;
		while (true) {
			
			for (int i = 0; i < 52; i++) {
				if (game.topindex[i] > -1) cout << game.topindex[i]+1 << game.topsuit(i) << game.toprank(i) << ' ';
			}
			cout << endl;
			
			
			int index1 = -1, index2 = -1;
			for (int i = 0; i < 52; i++) {
				if (game.topindex[i] < 0) continue;
				int gindex1 = -1, gindex2 = -1, nfound = 0;
				
				for (int x = i-1; x > -1 && nfound < 3; x--) {
					if (game.topindex[x] > -1) nfound++;
					if (nfound == 1) gindex2 = x;
					if (nfound == 3) gindex1 = x;
				}
				//cout << i << gindex1 << gindex2 << endl;
				if (gindex1 > -1 && (game.topsuit(i) == game.topsuit(gindex1) || game.toprank(i) == game.toprank(gindex1))) {
					index1 = gindex1;
					index2 = i;
					break;
				}
				
				if (gindex2 == 13) cout << "here";
				if (gindex2 > -1 && (game.topsuit(i) == game.topsuit(gindex2) || game.toprank(i) == game.toprank(gindex2))) {
					index1 = gindex2;
					index2 = i;
					break;
				}
			}
			
			//cout << index1 << index2 << endl;
			if (index1 > -1 && index2 > -1) {
				char ns = game.topsuit(index2);
				char nr = game.toprank(index2);
				game.pop(index2);
				game.push(index1, ns, nr);
			}
			else break;
		}
		
		printf("%i pile", game.npiles);
		if (game.npiles > 1) printf("s");
		printf(" remaining: ");
		for (int i = 0; i < 52; i++) {
			if (game.topindex[i] > -1) 
				printf(" %i", game.topindex[i] + 1); 
		}
		printf("\n");
		
	}
}