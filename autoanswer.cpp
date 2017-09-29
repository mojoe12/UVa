#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n; 
		cin >> n;
		n = int((5*(7492+(n*63))-498)/10);
		n = abs(n) % 10;
		cout << n << endl;
	}
}