#include <iostream>

using namespace std;
// lmao fib numbers get massive, not worth
int f(int n) {
	int a = 0, b = 1;
	for (int i = 0; i < n; i++) {
		int temp = a;
		a = b;
		b += temp;
	}
	return a;
}


int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		cout << "The Fibonacci number for " << n << " is " << f(n) << endl;
	}
}