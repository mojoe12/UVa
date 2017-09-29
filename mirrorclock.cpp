#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int tonum(string time, bool ifhour) {
	if (ifhour) return 10 * (time[0] - '0') + time[1] - '0';
	return 10 * (time[3] - '0') + time[4] - '0';
}
string totime (int hour, int min) {
	string h = to_string(hour);
	if (hour < 10) h = "0" + h;
	string m = to_string(min);
	if (min < 10) m = "0" + m;
	return h + ':' + m;
}
int flip (int h, int m) {
	if (h == 12) {
		if (m == 0) return 12;
		return 11;
	}
	if (m == 0) return abs(12-h);
	if (h == 11) return 12;
	return abs(11-h);
}
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		string input;
		cin >> input;
		int hour = tonum(input, true);
		int min = tonum(input, false);
		hour = flip(hour, min);
		if (min != 0) min = abs(60 - min);
		cout << totime(hour, min) << endl;
	}
}