#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

const int inf = 1000000;

using namespace std;

int shopkeep (const int* prices, int money, vector<int>& skarr) {
	if (money < 0) return inf;
	if (money == 0) return 0;
	
	int& arrval = skarr[money];
	if (arrval == -1) {
		int minnum = inf;
		for (int i = 0; i < 6; i++) {
			int num = shopkeep(prices, money - prices[i], skarr);
			minnum = min(minnum, num);
		}
		arrval = 1 + minnum;
	}
	return arrval;
}


int mincoins (vector<int>& ncoins, const int* prices, int money, const vector<int>& skarr) {
	//cout << money << endl;
	if (money < 0) return skarr[-money];
	if (money == 0) return 0;
	
	int minnum = inf;
	for (int i = 0; i < 6; i++) {
		if (ncoins[i]) {
			ncoins[i]--;
			int num = mincoins(ncoins, prices, money - prices[i], skarr);
			minnum = min(minnum, num);
			ncoins[i]++;
		}
	}
	return 1 + minnum;
}


int main() {
	
	const int prices[] = {1, 2, 4, 10, 20, 40};
	
	vector<int> skarr (39, -1);
	for (int i = 1; i < 40; i++) {
		skarr[i] = shopkeep(prices, i, skarr);
	}
	
	while (true) {
		vector<int> ncoins (6);
		bool shouldbreak = true;
		for (int i = 0; i < 6; i++) {
			cin >> ncoins[i];
			if (ncoins[i]) shouldbreak = false;
		}
		if (shouldbreak) break;
		
		double x;
		cin >> x;
		int money = round(x * 20);
		//cout << money << endl;
		
		cout.width(3);
		cout << right << mincoins(ncoins, prices, money, skarr) << endl;
	}




}


