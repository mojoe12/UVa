#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		int my = 1;
		for (int i = 0; i < n/2; i++) {
			my *= 10;
		}
		int m = my*my-1;
		for (int x = 0; x <= m; x++) {
			int z = (x % my) + (x / my);
			if (z * z == x) {
				for (int i = (m+1)/10; i > 1 && x < i; i /= 10) {
					cout << 0;
				}
				cout << x << endl;
			}
		}
	}
}