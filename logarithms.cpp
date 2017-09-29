#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



int main() {
	
	int n;
	while (cin >> n) {
		if (!n) break;
		int l = 0;
		for (; n / exp(l) > 2; l++) ;
		double x = 1 - n / exp(l);
		cout << l << ' ';
		cout << setprecision(8) << fixed << x << endl;
	}




}


