#include <iostream>
#include <cmath>
using namespace std;

int angle (int hour, int minute) {
	int mo12 = minute/12;
	int hourangle = mo12 * 6 + hour * 30;
	int minangle = 6 * minute;
	int ang = abs(hourangle - minangle);
	if (ang > 180) return 360 - ang;
	return ang;
}

int main(int argc, char *argv[]) {
	int x;
	while (cin >> x) {
		bool ifever = false;
		int h = 0, m = 0;
		while (h != 12 || m != 59) {
			if (angle(h,m) == x) {
				ifever = true;
				break;
			}
			m++;
			if (m == 60) {
				m = 0;
				h++;
			}
		}
		if (ifever) cout << "Y\n";
		else cout << "N\n";
	}
}