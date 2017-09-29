#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		cout << z * (2*x-y) / (x+y) << endl;
	}
}