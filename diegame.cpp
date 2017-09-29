#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int nrolls;
		cin >> nrolls;
		if (nrolls < 1) break;
		int top = 1, north = 2, west = 3;
		for (int i = 0; i < nrolls; i++) {
			string dir;
			cin >> dir;
			int east = 7 - west;
			int south = 7 - north;
			int bottom = 7 - top;
			if (dir == "north") {
				int northt = north, bottomt = bottom, southt = south;
				north = top;
				bottom = northt;
				south = bottomt;
				top = southt;
			}
			else if (dir == "south") {
				int topt = top, southt = south, bottomt = bottom;
				top = north;
				south = topt;
				bottom = southt;
				north = bottomt;
			}
			else if (dir == "east") {
				int eastt = east, bottomt = bottom, westt = west;
				east = top;
				bottom = eastt;
				west = bottomt;
				top = westt;
			}
			else if (dir == "west") {
				int westt = west, bottomt = bottom, eastt = east;
				west = top;
				bottom = westt;
				east = bottomt;
				top = eastt;
			}
		}
		cout << top << endl;
	}
}