#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {
	cout << fixed << setprecision(0);
	int k;
	long long n;
	cin >> k;
	for (int c = 0; c < k; c++) {
		cin >> n;
		cout << floor( (sqrt(8*n+1) -1) /2) << endl;
	}
}