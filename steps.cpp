#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int x, y;
		cin >> x >> y;
		int d = y - x;
		
		for (int n = 1; ; n++) {
			int half = n / 2;
			int sumd = half * (half + 1 - n % 2);
			cout << n << ' ' << sumd << endl;
			if (sumd > d) {
				cout << n - 1 << endl;
				break;
			}
		}
	}




}


