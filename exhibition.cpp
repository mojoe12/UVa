#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	
	cout << fixed << setprecision(6);
	for (int c = 1; c <= k; c++) {
		int n;
		cin >> n;
		vector< vector<int> > stamps (n, vector<int> ());
		map<int, int> ifunique;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			vector<int> stampadd;
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				if (ifunique.count(x) && ifunique[x] != i) ifunique[x] = -1;
				else {
					if (!ifunique.count(x)) stampadd.push_back(x);
					ifunique.insert( make_pair(x, i) );
				}
			}
			stamps[i] = stampadd;
		}
		
		vector<int> nunique (n);
		int totalnumunique = 0;
		for (int i = 0; i < n; i++) {
			int numunique = 0;
			for (int j = 0; j < stamps[i].size(); j++) {
				if (ifunique[stamps[i][j]] != -1) numunique++;
			}
			nunique[i] = numunique;
			totalnumunique += numunique;
		}
		
		cout << "Case " << c << ':';
		for (int i = 0; i < n; i++) {
			cout << ' ' << (100 * nunique[i]) / (totalnumunique * 1.) << '%';
		}
		cout << endl;
	}
}