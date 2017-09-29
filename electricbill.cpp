#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int getconsumption (int p) {
	if (p < 200) return p / 2;
	if (p < 29900) return 100 + (p - 200) / 3;
	if (p < 4979900) return 10000 + (p - 29900) / 5;
	return 1000000 + (p - 4979900) / 7;
}

int getprice (int c) {
	if (c < 100) return 2 * c;
	if (c < 10000) return 200 + 3 * (c - 100);
	if (c < 1000000) return 29900 + 5 * (c - 10000);
	return 4979900 + 7 * (c - 1000000);
}


int main() {
	
	for (int i = 0; i < 10000000; i++) {
		if (getconsumption(getprice(i)) != i) {
			cout << "uhoh!\n";
		}
	}
	
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) break;
		
		int sum = getconsumption(a);
		
		int min = 0, max = sum / 2, con;
		
		while (true) {
			con = (min + max) / 2;
			int neighbor = sum - con;
			//cout << con << endl;
			int mp = getprice(con);
			int np = getprice(neighbor);
			if (np - mp > b) {
				if (min == con) break;
				min = con;
			}
			else {
				if (max == con) break;
				max = con;
			}
		}
		
		cout << getprice(max) << endl;
	}




}


