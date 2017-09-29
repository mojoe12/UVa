#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string toLower (string s);
bool comp (vector<int> i, vector<int> j);

struct custom_string_comparer
{
    bool operator()(const string& s1, const string& s2) const
    {
         return toLower(s1) < toLower(s2);
    }
};

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		
		string tname;
		getline(cin, tname);
		int nteams;
		cin >> nteams;
		getline(cin, s);
		map<string, int, custom_string_comparer> namesmap;
		vector<string> namesvec (nteams);
		vector<int> zeros (10);
		for (int i = 0; i < 10; i++) zeros[i] = 0; 
		vector< vector<int> > allinfo (nteams, zeros);
		for (int i = 0; i < nteams; i++) {
			getline(cin, s);
			namesmap.insert( make_pair(s, i) );
			namesvec[i] = s;
			allinfo[i][0] = i;
		}
		
		map<string, int>::iterator it = namesmap.begin();
		for (int x = 0; it != namesmap.end(); it++, x++) {
			allinfo[it->second][9] = x;
		}
		
		int ngames;
		cin >> ngames;
		getline(cin, s);
		for (int i = 0; i < ngames; i++) {
			getline(cin, s);

			int len = s.length();
			string team1 = "", team2 = "";
			int index = 0;
			for (; index < len; index++) {
				if (s[index] == '#') break;
				else team1 += s[index];
			}
			
			int score1 = 0, score2 = 0;
			for (index++; index < len; index++) {
				if (s[index] == '@') break;
				else score1 = score1 * 10 + (s[index] - '0');
			}
			for (index++; index < len; index++) {
				if (s[index] == '#') break;
				else score2 = score2 * 10 + (s[index] - '0');
			}
						
			for (index++; index < len; index++) {
				team2 += s[index];
			}
			
			int team1index = namesmap[team1];
			int team2index = namesmap[team2];
			allinfo[team1index][2]++;
			allinfo[team2index][2]++;
			allinfo[team1index][6] += score1 - score2;
			allinfo[team2index][6] += score2 - score1;
			allinfo[team1index][7] += score1;
			allinfo[team2index][7] += score2;
			allinfo[team1index][8] += score2;
			allinfo[team2index][8] += score1;
			
			if (score1 > score2) {
				allinfo[team1index][1] += 3;
				allinfo[team1index][3]++;
				allinfo[team2index][5]++;
			}
			else if (score1 < score2) {
				allinfo[team2index][1] += 3;
				allinfo[team2index][3]++;
				allinfo[team1index][5]++;
			}
			else {
				allinfo[team1index][1]++;
				allinfo[team2index][1]++;
				allinfo[team1index][4]++;
				allinfo[team2index][4]++;
			}
		}
		
		sort(allinfo.begin(), allinfo.end(), comp);
		
		cout << tname << endl;
		for (int i = 0; i < nteams; i++) {
			cout << i+1 << ") " << namesvec[allinfo[i][0]] << ' ';
			cout << allinfo[i][1] << "p, " << allinfo[i][2] << "g (";
			cout << allinfo[i][3] << '-' << allinfo[i][4] << '-';
			cout << allinfo[i][5] << "), " << allinfo[i][6] << "gd (";
			cout << allinfo[i][7] << '-' << allinfo[i][8] << ")\n";
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


bool comp (vector<int> i, vector<int> j) {
	if (i[1] != j[1]) return i[1] > j[1];
	if (i[3] != j[3]) return i[3] > j[3];
	if (i[6] != j[6]) return i[6] > j[6];
	if (i[7] != j[7]) return i[7] > j[7];
	if (i[2] != j[2]) return i[2] < j[2];
	return i[9] < j[9];
}