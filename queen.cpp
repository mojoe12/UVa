#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {
	while (1) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 0) break;
		
		else if (x1 == x2 && y1 == y2) cout << 0 << endl;
		else if (x1 == x2 || y1 == y2) cout << 1 << endl;
		else if (abs(x2-x1) == abs(y2-y1)) cout << 1 << endl;
		else cout << 2 << endl;
	}
}