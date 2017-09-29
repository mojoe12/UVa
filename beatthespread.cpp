#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int c = 0; c < k; c++) {
		unsigned long sum, dif;
		cin >> sum >> dif;
		if ((sum - dif) % 2 == 1 || sum < dif) {
			cout << "impossible" << endl;
			continue;
		}
		unsigned long a = (sum + dif) / 2, b = sum - a;
		cout << a << " " << b << endl;
	}
}