#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

bool bingo (vector< vector<bool> >& card) {
	for (int i = 0; i < 5; i++) {
		bool ifwon = true;
		for (int j = 0; ifwon && j < 5; j++) {
			ifwon = card[i][j];
		}
		if (ifwon) return true;
	}
	for (int j = 0; j < 5; j++) {
		bool ifwon = true;
		for (int i = 0; ifwon && i < 5; i++) {
			ifwon = card[i][j];
		}
		if (ifwon) return true;
	}
	bool ifwon = true;
	for (int i = 0, j = 0; ifwon && i < 5; i++, j++) {
		ifwon = card[i][j];
	}
	if (ifwon) return true;
	ifwon = true;
	for (int i = 0, j = 4; ifwon && i < 5; i++, j--) {
		ifwon = card[i][j];
	}
	return ifwon;
}

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		
		map<int, pair<int, int> > numbers;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < ((i == 2) ? 4 : 5); j++) {
				int x;
				cin >> x;
				numbers.insert( make_pair(x, make_pair(i, j + (i == 2 && j > 1))));
			}
		}
		
		vector< vector<bool> > card (5, vector<bool> (5, false));
		card[2][2] = true;
		bool ifwon = false;
		for (int i = 0; i < 75; i++) {
			int x;
			cin >> x;
			if (numbers.count(x)) card[numbers[x].first][numbers[x].second] = true;
			
			if (!ifwon && bingo(card)) {
				cout << "BINGO after " << i+1 << " numbers announced\n";
				ifwon = true;
			}
		}
		
	}



}


