#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	unsigned long long n, b;
	while (cin >> n >> b) {
		if (b > 50) {
			cout << "no\n";
			continue;
		}
		unsigned long long poww = round(pow(2, b+1));
		if (n >= poww) cout << "no\n";
		else cout << "yes\n";
	}
}