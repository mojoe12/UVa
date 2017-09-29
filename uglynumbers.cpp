#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	
	vector<long double> allnums;
	const int n = 50;
	allnums.reserve(n * n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				allnums.push_back(pow(2., i) * pow(3., j) * pow(5., k));
			}
		}
	}
	sort(allnums.begin(), allnums.end());
	cout << "The 1500'th ugly number is ";
	cout << fixed << setprecision(0) << allnums[1499] << ".\n";
}


