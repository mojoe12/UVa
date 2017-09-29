#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		
		map<int, bool> xcards;
		int card;
		for (int i = 0; i < x; i++) {
			cin >> card;
			xcards.insert( make_pair(card, true) );
		}
		
		set<int> ycards;
		for (int i = 0; i < y; i++) {
			cin >> card;
			if (xcards.count(card)) xcards[card] = false;
			else ycards.insert(card);
		}
		
		int xsize = 0;
		for (map<int,bool>::iterator it = xcards.begin(); it != xcards.end(); it++) {
			if (it -> second) xsize++;
		}
		int ysize = ycards.size();
		
		cout << min(xsize, ysize) << endl;
	}
}