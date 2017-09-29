#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;


int main() {
	
	double h, w;
	while (cin >> h >> w) {
		
		double sum = h + w;
		double root = sqrt(sum * sum - 3 * h * w);
		double maxx = 1e-7 + (sum - root) / 6.0;
		double minn = 1e-7 + min(h, w) / 2.0;
		
		cout << setprecision(3) << fixed << maxx;
		cout << " 0.000 ";
		cout << setprecision(3) << fixed << minn << endl;
		
	}

}

// volume is x * (h - 2x) * (w - 2x)
// this is x (hw - 2xw - 2xh + 4xx)
// hwx - 2xxw - 2xxh + 4xxx
// hw - 4xw - 4xh + 12xx
// a = 12, b = -4(h+w), c = hw
// x = -b +- sqrt(b^2 - 4ac) // 2a