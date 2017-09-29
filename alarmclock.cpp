#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;
		if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
		int dif = h2*60+m2 - (h1*60+m1);
		if (h2 < h1 || (h2 == h1 && m2 < m1)) dif += 24*60;
		cout << dif << endl;
	}
}