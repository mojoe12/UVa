/*#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("visitfj.in");
	ofstream fout ("visitfj.out");
	
	int n, t;
	fin >> n >> t;
	vector<vector<int> > grass (n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> grass[i][j];
		}
	}
	
	int locx = 0, locy = 0;
	int time = 0;
	while (locx != n-1 || locy != n-1) {
		//cout << locx << ' ' << locy << endl;
		
		int bestx = 0, besty = 0;
		int bestval = INT_MAX;
		bool ifend = false;
		for (int i = -3; i <= 3; i++) {
			int cposx = locx+i;
			if (cposx < 0 || cposx >= n) continue;
			for (int j = abs(i)-3; j <= 3-abs(i); j++) {
				int cposy = locy+j;
				if (cposy < 0 || cposy >= n) continue;
				if (i == 0 && j == 0) continue;
				
				if (abs(i) + abs(j) < 3 && (cposx != n-1 || cposy != n-1)) {
					continue;
				}
				
				int currentval = (n - cposx + n - cposy) * t;
				if (abs(i) + abs(j) == 3) currentval += grass[cposx][cposy];
				if (currentval < bestval) {
					bestval = currentval;
					bestx = cposx;
					besty = cposy;
				}
			}
		}
		
		int dist = abs(bestx - locx) + abs(besty - locy);
		time += dist * t;
		if (dist == 3) time += grass[bestx][besty];
		locx = bestx;
		locy = besty;
	}
	fout << time << endl;
}*/


#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("visitfj.in");
	ofstream fout ("visitfj.out");
	
	int n, t;
	cin >> n >> t;
	vector<vector<int> > grass (n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grass[i][j];
		}
	}
	
	vector<int> prx (n);
	fill(prx.begin(), prx.end(), INT_MAX);
	vector<vector<int> > one (n, vector<int> (n));
	vector<vector<int> > two (n, vector<int> (n));
	vector<vector<int> > three (n, vector<int> (n));
	fill(one.begin(), one.end(), prx);
	fill(two.begin(), two.end(), prx);
	fill(three.begin(), three.end(), prx);
	
	
	
	
	int locx = n-1, locy = n-1;
	
	for (int dist = 0; dist < 3; dist++) {
		for (int i = 0; i < dist; i++) {
			int j = dist-i;
			if (three)
		}
	}	
	
	for (int dist = 3; dist < 2*n-1; dist++) {
		for (int i = 0; i < dist; i++) {
			int j = dist - i;
			
			
			// one move left
			

		}
	}
}