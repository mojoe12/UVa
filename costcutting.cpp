#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int b = 0;
		int sals[3];
		cin >> sals[0] >> sals[1] >> sals[2];
		if (sals[0] > sals[1] && sals[0] > sals[2]) {
			if (sals[1] > sals[2]) b = sals[1];
			else b = sals[2];
		}
		else if (sals[1] > sals[2] && sals[1] > sals[0]) {
			if (sals[2] > sals[0]) b = sals[2];
			else b = sals[0];
		}
		else if (sals[2] > sals[0] && sals[2] > sals[1]) {
			if (sals[1] > sals[0]) b = sals[1];
			else b = sals[0];
		}
		cout << "Case " << i << ": " << b << endl;
	}
}