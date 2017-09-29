#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int g = 0; g < k; g++) {
		int a, b, c, ap, bp, cp;
		cin >> a >> b >> c;
		bool ifsolved = false;
		int x, y, z;
		for (x = -100; x <= 100; x++) {
			ap = a - x;
			if (x) bp = b / x;
			else continue;
			
			cp = c - x * x;
			
			if (ap * ap != 2 * bp + cp) continue;
			if (sqrt(cp - 2 * bp) != round(sqrt(cp - 2 * bp))) continue;
			
			
			int sum = ap;
			int dif = sqrt(cp - 2 * bp);
			
			z = (sum + dif) / 2;
			y = sum - z;
			
			if (x >= y || y >= z || x >= z) continue;
			
			/*if (y > z) {
				int temp = y;
				y = z;
				z = temp;
			}*/
			
			if (x + y + z != a) continue;
			if (x * y * z != b) continue;
			if (x * x + y * y + z * z != c) continue;
			
			ifsolved = true;
			cout << x << ' ' << y << ' ' << z << endl;
		}
		
		if (!ifsolved) cout << "No solution.\n";
	}
}