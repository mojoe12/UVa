#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		double sum = 0;
		for (int i = 0; i < 12; i++) {
			double bal;
			cin >> bal;
			sum += bal;
		}
		sum /= 12;
		int x = (int) sum;
		string numWithCommas = to_string(x);
		for (int insertPosition = numWithCommas.length() - 3; insertPosition > 0; insertPosition -= 3) {
		    numWithCommas.insert(insertPosition, ",");
		}
		cout << c << " $" << numWithCommas << '.';
		int y = round((sum - x) * 100);
		if (y < 10) cout << '0';
		cout << y << endl;
	}
}