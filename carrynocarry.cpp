#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	long a, b;
	while (cin >> a >> b) {
		long x = a ^ b;
		cout << x << endl;
	}
}