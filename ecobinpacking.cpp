#include <iostream>
using namespace std;
bool getperm(string &p);

int main(int argc, char *argv[]) {
	int b1, g1, c1, b2, g2, c2, b3, g3, c3;
	while (cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
		int minmoves = 2147483647;
		string bestperm = "";
		string perm = "";
		while (getperm(perm)) {
			int nmoves = g1 + b1 + c1 + g2 + b2 + c2 + g3 + b3 + c3;
				 if (perm[0] == 'G') nmoves -= g1;
			else if (perm[1] == 'G') nmoves -= g2;
			else if (perm[2] == 'G') nmoves -= g3;
				 if (perm[0] == 'B') nmoves -= b1;
			else if (perm[1] == 'B') nmoves -= b2;
			else if (perm[2] == 'B') nmoves -= b3;
				 if (perm[0] == 'C') nmoves -= c1;
			else if (perm[1] == 'C') nmoves -= c2;
			else if (perm[2] == 'C') nmoves -= c3;
			if (nmoves < minmoves) {
				minmoves = nmoves;
				bestperm = perm;
			}
		}
		cout << bestperm << " " << minmoves << endl;
	}
	
}
bool getperm(string &p) {
	if (p == "") p = "BCG";
	else if (p == "BCG") p = "BGC";
	else if (p == "BGC") p = "CBG";
	else if (p == "CBG") p = "CGB";
	else if (p == "CGB") p = "GBC";
	else if (p == "GBC") p = "GCB";
	else if (p == "GCB") return false;
	return true;

}