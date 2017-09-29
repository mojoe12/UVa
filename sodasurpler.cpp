#include <iostream>

using namespace std;

int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		int empties = x + y, numdrank = 0;
		while (empties >= z) {
			numdrank += (empties / z);
			empties = empties / z + empties % z;
		}
		cout << numdrank << endl;
	}
}