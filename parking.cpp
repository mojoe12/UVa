#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int j = 0; j < k; j++) {
		int n;
		cin >> n;
		int biggest = 0, smallest = 1000;
		for (int p = 0; p < n; p++) {
			int pos;
			cin >> pos;
			if (pos > biggest) biggest = pos;
			if (pos < smallest) smallest = pos;
		}
		cout << 2 * (biggest - smallest) << endl;
	}
}