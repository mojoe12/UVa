#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input
	
	int nteams;
	for (int c = 1; cin >> nteams; c++) {
		if (!nteams) break;
		
		vector<int> sizes (nteams);
		vector<int> points (nteams, -1);
		vector<int> starts (nteams);
		map<int, int> teams;
		
		int sumsize = 0;
		for (int i = 0; i < nteams; i++) {
			cin >> sizes[i];
			sumsize += sizes[i];
			for (int j = 0; j < sizes[i]; j++) {
				int num;
				cin >> num;
				teams.insert( make_pair(num, i) );
			}
		}
		
		vector<int> printout;
		
		// problem is when you get rid of one but re add it
		// if you finish off a team you have to start over
		
		vector<int> q (sumsize, -1);
		int index = 0, addpoint = 0, currteam = 0;
		string s;
		while (cin >> s) {
			if (s == "STOP") break;
			if (s == "DEQUEUE") {
				if (q[index % sumsize] == -1 || starts[currteam+1] == (index % sumsize)) {
					points[currteam] = -1;
					currteam++;
					index = starts[currteam];
				}
				printout.push_back(q[(index++) % sumsize]);
			}
			else {
				int x;
				cin >> x;
				int team = teams[x];
				if (points[team] > -1) {
					q[(points[team]++) % sumsize] = x;
				}
				else {
					starts[team] = addpoint % sumsize;
					q[addpoint % sumsize] = x;
					points[team] = addpoint+1;
					addpoint += sizes[team];
				}
			}
		}
		
		cout << "Scenario #" << c << endl;
		for (int i = 0; i < printout.size(); i++) {
			cout << printout[i] << endl;
		}
		cout << endl;
	}

}