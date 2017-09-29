#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	map<char, int> mp;
	mp.insert( make_pair('r', 0) );
	mp.insert( make_pair('o', 1) );
	mp.insert( make_pair('y', 2) );
	mp.insert( make_pair('g', 3) );
	mp.insert( make_pair('b', 4) );

	string s;
	vector<vector<char> > bins0 (0, vector<char> (5));
	vector<vector<char> > bins = bins0;
	
	while (getline(cin, s)) {
		if (s[0] == '#') break;
		if (s[0] == 'e') 
		{
			int minmoves = 1000000;
			int bestone = 0;
			for (int i = 0; i < bins.size(); i++) {
				int moves = 0;
				for (int j = 0; j < bins.size(); j++) {
					for (int k = 0; k < 5; k++) {
						if (bins[i][k] != bins[j][k]) moves++;
					}
				}
				if (moves < minmoves) {
					minmoves = moves;
					bestone = i;
				}
			}
			cout << bestone+1 << endl;
			bins = bins0;
		}
		else 
		{
			vector<char> newarray (5);
			for (int i = 0; i <= 16; i += 4) {
				newarray[mp[s[i]]] = s[i+2];
			}
			bins.push_back(newarray);
		}
	}
}