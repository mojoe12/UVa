#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {
	
	cout << fixed << setprecision(2);
	
	int m, n;
	while (cin >> m) {
		if (m == 0) break;
		cin >> n;
		
		vector<int> front (m);
		for (int i = 0; i < m; i++) cin >> front[i];
		
		vector<double> ratios (m * n);
		for (int i = 0; i < n; i++) {
			int rear;
			cin >> rear;
			for (int j = 0; j < m; j++) {
				ratios[i*m + j] = rear * 1.0 / front[j];
			}
		}
		
		sort(ratios.begin(), ratios.end());
		
		double bestdif = 1.0;
		
		for (int i = 1; i < m*n; i++) {
			bestdif = max(bestdif, ratios[i]/ratios[i-1]);
		}
		
		cout << bestdif << endl;
		
	}
}