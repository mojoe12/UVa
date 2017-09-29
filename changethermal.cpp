#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) {
	cout << fixed << setprecision(2);
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int tempc, diff;
		cin >> tempc >> diff;
		double tempf = 32 + (9 * tempc / 5.0);
		tempf += diff;
		double newtempc = 5 * (tempf - 32) / 9.0;
		cout << "Case " << c << ": ";
		cout << newtempc << endl;
	}
}