#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	cout << fixed << setprecision(3);
	while (true) {
		string time;
		cin >> time;
		int h = time[0] - '0';
		int i = 2;
		if (time[1] != ':') {
			h = h * 10 + (time[1] - '0');
			i++;
		}
		int m = 10 * (time[i++] - '0') + (time[i] - '0');
		if (h == 0 && m == 0) break;
		double ang = abs(30 * h - 5.5 * m);
		if (ang > 180) ang = 360 - ang;
		cout << ang << endl;
	}
}