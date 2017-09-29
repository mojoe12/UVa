#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



int main() {
	int k;
	cin >> k;
	while (k--) {
		double l, k, t1, t2, h;
		cin >> l >> k >> t1 >> t2 >> h;
		
		double x = h + t2 * k;
		
		double r = sqrt(x * x - 4 * t1 * l * k);
		double rmin = (x - r) / (2 * t1);
		double rmax = (x + r) / (2 * t1);
		
		cout << setprecision(6) << fixed << rmin;
		cout << ' ' << fixed << rmax << endl;
	}




}


