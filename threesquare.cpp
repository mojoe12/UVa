#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int g = 0; g < k; g++) {
		int n;
		cin >> n;
		int x = 0, y = 0, z = 0;
		bool ifsolved = false;
		for (x = 0; !ifsolved && 3*x*x <= n; x++) {
			for (y = x; !ifsolved && x*x + 2*y*y <= n; y++) {
				int zsq = n - x*x - y*y;
				if (sqrt(zsq) == round(sqrt(zsq))) {
					z = sqrt(zsq);
					ifsolved = true;
					cout << x << ' ' << y << ' ' << z << endl;
				}
			}
		}
		if (!ifsolved) cout << "-1\n";
	}
}