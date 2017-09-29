#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int i = 0; i <= 200; i++) {
		for (int a = 2; a < i; a++) {
			for (int b = a; b < i; b++) {
				for (int c = b; c < i; c++) {
					int sum = a*a*a + b*b*b + c*c*c;
					if (sum == i*i*i) {
						cout << "Cube = " << i << ", Triple = (";
						cout << a << ',' << b << ',' << c << ")\n";
					}
				}
			}
		}
	}
}