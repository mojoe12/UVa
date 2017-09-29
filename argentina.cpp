#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct player {
	string name;
	int atk;
	int def;
};

bool comp1 (player i, player j) {
	return i.name < j.name;
}

bool comp2 (pair<int, player> i, pair<int, player> j) {
	if (i.second.atk != j.second.atk)
		return i.second.atk > j.second.atk;
	if (i.second.def != j.second.def)
		return i.second.def > j.second.def;
	return i.first < j.first;
}

int main(int argc, char *argv[]) {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		vector<player> team (10);
		int sumdef = 0;
		for (int i = 0; i < 10; i++) {
			player newplayer;
			cin >> newplayer.name >> newplayer.atk >> newplayer.def;
			sumdef += newplayer.def;
			team[i] = newplayer;
		}

		sort(team.begin(), team.end(), comp1);
		
		// 10 choose 5 is 252
		vector<vector<int> > teams (252, vector<int> (5));
		vector<pair<int, player> > atkscores;

		int counter = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = i+1; j < 10; j++) {
				for (int k = j+1; k < 10; k++) {
					for (int l = k+1; l < 10; l++) {
						for (int m = l+1; m < 10; m++) {
							int teama[] = {i, j, k, l, m};
							vector<int> teamv;
							teamv.assign(teama, teama + 5);
							int atksum = 0, defsum = 0;
							{
								atksum += team[i].atk;
								atksum += team[j].atk;
								atksum += team[k].atk;
								atksum += team[l].atk;
								atksum += team[m].atk;
								defsum += team[i].def;
								defsum += team[j].def;
								defsum += team[k].def;
								defsum += team[l].def;
								defsum += team[m].def;
							}
							
							player p1;
							p1.name = "";
							p1.atk = atksum;
							p1.def = sumdef - defsum;
							
							atkscores.push_back( make_pair(counter, p1) );
							teams[counter] = teamv;
							counter++;
						}
					}
				}
			}
		}
		
		sort(atkscores.begin(), atkscores.end(), comp2);
		vector<int> best = teams[atkscores[0].first];
		vector<player> attackers;
		vector<player> defenders;
		
		int tick = 0;
		for (int i = 0; i < 10; i++) {
			if (i == best[tick]) {
				attackers.push_back(team[i]);
				tick++;
			}
			else {
				defenders.push_back(team[i]);
			}
		}
		
		cout << "Case " << c << ":\n(" << attackers[0].name;
		for (int i = 1; i < 5; i++) cout << ", " << attackers[i].name;
		cout << ")\n(" << defenders[0].name;
		for (int i = 1; i < 5; i++) cout << ", " << defenders[i].name;
		cout << ")\n";
	}
}