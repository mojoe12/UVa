#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		long long sum = 0;
		vector<int> streets (n);
		for (int i = 0; i < n; i++) {
			cin >> streets[i];
		}
		
		sort(streets.begin(), streets.end());
		int vito = 0;
		if (n % 2) vito = streets[n/2];
		else vito = (streets[(n/2) - 1] + streets[n/2]) / 2;
		
		long long sumdist = 0;
		for (int i = 0; i < n; i++) {
			sumdist += abs(streets[i] - vito);
		}
		
		cout << sumdist << endl;
	}
}