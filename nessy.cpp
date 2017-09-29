#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a = ceil((a-2)/3.0);
		b = ceil((b-2)/3.0);
		cout << a * b << endl;
	}
}