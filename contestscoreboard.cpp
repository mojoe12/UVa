#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
	int problem;
	int pentime;
	
	data(int p1, int p2) :
		problem(p1),
		pentime(p2) {}
};


bool comp (vector<data> i, vector<data> j) {
	if (i[1].problem != j[1].problem) return i[1].problem > j[1].problem;
	if (i[1].pentime != j[1].pentime) return i[1].pentime < j[1].pentime;
	return i[0].problem < j[0].problem;
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	
	string s;
	getline(cin, s);
	getline(cin, s);
	
	for (int c = 0; c < k; c++) {
		
		if (c) cout << endl;
		
		vector< vector<data> > teaminfo;
		map<int, int> teammap;
		
		for(getline(cin, s); s != ""; getline(cin, s)) {
			
			// get team
			int index = 0;
			int team = 0; 
			while (s[index] != ' ') team = team * 10 + s[index++] - '0';
			
			// find index for this team or make a new one
			int teamindex = 0;
			if (teammap.count(team)) {
				teamindex = teammap[team];
			}
			else {
				// make that new data, then add it to teaminfo
				teamindex = teaminfo.size();
				vector<data> newinfo;
				data newdata1 (team, 0);
				data newdata2 (0, 0);
				newinfo.push_back(newdata1);
				newinfo.push_back(newdata2);
				teaminfo.push_back(newinfo);
				teammap.insert( make_pair(team, teamindex) );
			}
			
			// get the rest of the data
			index++;
			int problem = s[index++] - '0';
			index++;
			int time = 0;
			while (s[index] != ' ') time = time * 10 + s[index++] - '0';
			index++;
			
			char type = s[index];

			// when type is C
			if (type == 'C') {
				bool iffound = false, ifsolved = false;
				int addedtime = time;
				for (int i = 2; !iffound && i < teaminfo[teamindex].size(); i++) {
					if (teaminfo[teamindex][i].problem == problem) {
						iffound = true;
						if (teaminfo[teamindex][i].pentime >= 0) {
							addedtime += teaminfo[teamindex][i].pentime;
							teaminfo[teamindex][i].pentime = -1;
						}
						else ifsolved = true;
					}
				}
				if (!iffound) {
					data newproblem (problem, -1);
					teaminfo[teamindex].push_back(newproblem);
				}
				if (!ifsolved) {
					teaminfo[teamindex][1].problem++;
					teaminfo[teamindex][1].pentime += addedtime;
				}
			}
			else if (type == 'I') {
				bool iffound = false;
				for (int i = 2; !iffound && i < teaminfo[teamindex].size(); i++) {
					if (teaminfo[teamindex][i].problem == problem) {
						iffound = true;
						if (teaminfo[teamindex][i].pentime >= 0) {
							teaminfo[teamindex][i].pentime += 20;
						}
					}
				}
				if (!iffound) {
					data newproblem (problem, 20);
					teaminfo[teamindex].push_back(newproblem);
				}
			}
		}
		
		sort(teaminfo.begin(), teaminfo.end(), comp);
		
		for (int i = 0; i < teaminfo.size(); i++) {
			cout << teaminfo[i][0].problem << ' ';
			cout << teaminfo[i][1].problem << ' ';
			cout << teaminfo[i][1].pentime << endl;
		}
	}
}