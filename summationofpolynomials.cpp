#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



int main() {
	
	long long x;
	while (cin >> x) {
		long double ansroot = x * (x + 1) / 2;
		long double ans = ansroot * ansroot;
		cout << setprecision(0) << fixed;
		cout << ans << endl;
	}
}


