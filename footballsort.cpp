#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ios>
#include <iomanip>
using namespace std;

bool comp (vector<int>& i, vector<int>& j) {
	if (i[1] != j[1]) return i[1] > j[1];
	if (i[5] != j[5]) return i[5] > j[5];
	if (i[3] != j[3]) return i[3] > j[3];
	return i[6] < j[6];
}

string toLower(string);

struct custom_string_comparer
{
    bool operator()(const string& s1, const string& s2) const
    {
         return toLower(s1) < toLower(s2);
    }
};

int main(int argc, char *argv[]) {
	int t, g;
	bool iffirst = true;
	while (cin >> t >> g) {
		if (!t && !g) break;
		
		if (!iffirst) cout << endl;
		else iffirst = false;
		
		vector<string> namesvec (t);
		map<string, int, custom_string_comparer> namesmap;
		vector< vector<int> > allinfo (t, vector<int> (7, 0));

		for (int i = 0; i < t; i++) {
			cin >> namesvec[i];
			namesmap.insert( make_pair(namesvec[i], i));
			allinfo[i][0] = i;
		}

		
		map<string, int>::iterator it = namesmap.begin();
		for (int x = 0; it != namesmap.end(); it++, x++) {
			allinfo[it->second][6] = x;
		}
		
		
		for (int gi = 0; gi < g; gi++) {
			string team1, team2;
			int score1, score2;
			cin >> team1 >> score1;
			char c;
			cin >> c;
			cin >> score2 >> team2;
			
			int team1index = namesmap[team1];
			int team2index = namesmap[team2];
			
			if (score1 > score2) allinfo[team1index][1] += 3;
			else if (score1 < score2) allinfo[team2index][1] += 3;
			else {
				allinfo[team1index][1]++;
				allinfo[team2index][1]++;
			}
			
			allinfo[team1index][2]++;
			allinfo[team2index][2]++;
			allinfo[team1index][3] += score1;
			allinfo[team2index][3] += score2;
			allinfo[team1index][4] += score2;
			allinfo[team2index][4] += score1;
			allinfo[team1index][5] += score1 - score2;
			allinfo[team2index][5] += score2 - score1;
		}
				
		sort(allinfo.begin(), allinfo.end(), comp);
		
		for (int i = 0; i < t; i++) {
			if (i < 1 ||
			allinfo[i-1][1] != allinfo[i][1] ||
			allinfo[i-1][3] != allinfo[i][3] ||
			allinfo[i-1][5] != allinfo[i][5]) {
				cout.width(2);
				cout << right << i+1 << ". ";
			}
			else cout << "    ";
			
			cout.width(15);
			cout << right << namesvec[allinfo[i][0]];
			for (int j = 1; j < 6; j++) {
				cout.width(4);
				cout << right << allinfo[i][j];
			}
			
			if (!allinfo[i][2]) {
				cout.width(7);
				cout << right << "N/A" << endl;
			}
			else {
				double percent = 100 * allinfo[i][1] / (3.0 * allinfo[i][2]);
				cout << fixed << setprecision(2);
				cout.width(7);
				cout << right << percent << endl;
			}
			
		}
		
		
	}
}

string toLower (string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	return s;
}






















