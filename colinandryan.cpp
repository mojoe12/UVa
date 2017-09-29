#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		long long C, r;
		cin >> C >> r;
		cout << "Case " << c << ":";
		
		long long e = C - r;
		
		if (!e) {
			cout << " 0" << endl;
			continue;
		}
		
		vector<long long> divs;
		for (long long i = 1; i <= floor(sqrt(e)); i++) {
			if (e % i == 0) {
				divs.push_back(i);
				if (e != i*i) divs.push_back(e / i);
			}
		}
		sort(divs.begin(), divs.end());
		for (int i = 0; i < divs.size(); i++) {
			if (divs[i] > r) cout << ' ' << divs[i];
		}
		cout << endl;
		
	}
}