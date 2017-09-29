#include <iostream>

using namespace std;

int main() {
	
	long long m, x;
	while (cin >> m >> x) {
		if (!m && !x) break;
		
		long long numer = (m - 1) * 100, denom = 100 - x;
		long long s = (!denom) ? 0 : numer / denom;
		if (denom && numer % denom == 0) s--;
		if (s < m) cout << "Not found\n";
		else cout << s << endl;
	}
}