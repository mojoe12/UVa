#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



int main() {
	
	int x;
	cout.precision(3);
	for (int c = 1; cin >> x; c++) {
		if (!x) break;
		if (x == 1) {
			double u, v, t;
			cin >> u >> v >> t;
			double a = (v - u) / t;
			double s = .5 * a * t * t + u * t;
			cout << "Case " << c << ": ";
			cout << fixed << s << ' ' << fixed << a << endl;
		}
		else if (x == 2) {
			double u, v, a;
			cin >> u >> v >> a;
			double t = (v - u) / a;
			double s = .5 * a * t * t + u * t;
			cout << "Case " << c << ": ";
			cout << fixed << s << ' ' << fixed << t << endl;
		}
		else if (x == 3) {
			double u, a, s;
			cin >> u >> a >> s;
			double t = (-u + sqrt(u * u + 2 * a * s)) / a;
			double v = u + a * t;
			cout << "Case " << c << ": ";
			cout << fixed << v << ' ' << fixed << t << endl;
		}
		else if (x == 4) {
			double v, a, s;
			cin >> v >> a >> s;
			double t = (v - sqrt(v * v - 2 * a * s)) / a;
			double u = v - a * t;
			cout << "Case " << c << ": ";
			cout << fixed << u << ' ' << fixed << t << endl;
		}
	}



}


