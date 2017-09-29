#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

string ending (int i){
	if (i % 100 > 9 && i % 100 < 14) return "th";
	switch (i % 10) {
		case 1: return "st";
		case 2: return "nd";
		case 3: return "rd";
		default: return "th";
	}
}


int main() {
	vector<long double> allnums;
	const int n = 35;
	allnums.reserve(n * n * n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					allnums.push_back(pow(2., i) * pow(3., j) * pow(5., k) * pow(7., l));
				}
			}
		}
	}
	sort(allnums.begin(), allnums.end());
	int i;
	while (cin >> i) {
		if (!i) break;
		cout << "The " << i << ending(i);
		cout << " humble number is ";
		cout << fixed << setprecision(0) << allnums[i-1] << ".\n";
	}
}


