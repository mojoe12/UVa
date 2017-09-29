#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n, m;
		cin >> n >> m;
		
		vector<int> edges (m, -1);
		vector<int> count (m, 0);
		bool ifyes = true;
		
		for (int i = 0; i < n; i++) {
			vector<int> specedge;
			for (int j = 0; j < m; j++) {
				
				int x;
				cin >> x;
				if (!x) continue;
				
				count[j]++;
				
				if (edges[j] == -1) edges[j] = i;
				else {
					if (find(specedge.begin(), specedge.end(), edges[j]) != specedge.end()) ifyes = false;
					else specedge.push_back(edges[j]);
				}
				
			}
		}
		
		for (int j = 0; ifyes && j < m; j++) if (count[j] != 2) ifyes = false;
		
		if (ifyes) cout << "Yes\n";
		else cout << "No\n";	
		
	}


	// loop through it, apply function


	// output answer


}

// function definitions

