#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("nocross.in");
	ofstream fout ("nocross.out");
	
	int n;
	fin >> n;
	vector<int> top (n);
	for (int i = 0; i < n; i++) fin >> top[i];
	vector<int> bot (n);
	for (int i = 0; i < n; i++) fin >> bot[i];
	
	
	vector<pair<int, int> > possible;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (abs(top[i] - top[b]) < 5) {
				possible.push_back(make_pair(i, j));
			}
		}
	}
	
	
}









/*#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("nocross.in");
	ofstream fout ("nocross.out");
	
	int n;
	fin >> n;
	vector<int> top (n);
	for (int i = 0; i < n; i++) fin >> top[i];
	vector<int> bot (n);
	for (int i = 0; i < n; i++) fin >> bot[i];
	
	int maxcross = 0;
	for (int sdist = 0; sdist < n; sdist++) {
		vector<bool> topb (n);
		fill(topb.begin(), topb.end(), true);
		vector<bool> botb (n);
		fill(botb.begin(), botb.end(), true);
		
		vector<pair<int, int> > crosses (0);
		for (int dist = sdist; dist < n; dist++) {
			for (int i = 0; i < n - dist; i++) {
				
				int j = i - dist;
				if (j >= 0) {
					bool ifcrossable = topb[i] && botb[j] && abs(top[i] - bot[j]) < 5;
					
					for (int x = 0; ifcrossable && x < crosses.size(); x++) {
						ifcrossable = !(crosses[x].first > i && crosses[x].second < j);
					}
					if (ifcrossable) {
						crosses.push_back( make_pair(i, j) );
						topb[i] = false;
						botb[j] = false;
					}
				}
			}
			
		}
		for (int dist = sdist; dist < n; dist++) {
			for (int i = dist; i < n; i++) {
				
				int j = i - dist;
				if (j >= 0) {
					bool ifcrossable = topb[i] && botb[j] && abs(top[i] - bot[j]) < 5;
					
					for (int x = 0; ifcrossable && x < crosses.size(); x++) {
						ifcrossable = !(crosses[x].first < i && crosses[x].second > j);
					}
					if (ifcrossable) {
						crosses.push_back( make_pair(i, j) );
						topb[i] = false;
						botb[j] = false;
					}
				}
			}
			
		}
		maxcross = max(maxcross, (int)crosses.size());
	}
	fout << maxcross << endl;
	
	
}*/