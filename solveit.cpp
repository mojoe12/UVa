#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;

int main() {
	
	int p, q, r, s, t, u;
	const double eps = 1e-10;
	while (cin >> p >> q >> r >> s >> t >> u) {
		
		double funcat0 = u + p + r;
		double funcat1 =  u + p*exp(-1) + q*sin(1) + r*cos(1) + s*tan(1) + t;
		if ((funcat0 < -eps && funcat1 < -eps) || (funcat0 > eps && funcat1 > eps)) {
			cout << "No solution\n";
			continue;
		}
		
		double minn = 0, maxx = 1;
		while (abs(minn - maxx) > 4e-5) {
			double x = (minn + maxx) / 2;
			double func = u + p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x;
			if (func > eps) minn = x;
		 	else maxx = x;
		} 
		
		cout << setprecision(4) << fixed << minn << endl;
	}




}


