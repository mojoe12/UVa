#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int m, n;
	while (cin >> m >> n) {
		int cuts = m * n - 1;
		cout << cuts << endl;
	}
}