#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	while (cin >> s) {
		int sum = 3600000 * (s[0] - '0') + 360000 * (s[1] - '0') + 60000 * (s[2] - '0') + 6000 * (s[3] - '0') + 1000 * (s[4] - '0') + 100 * (s[5] - '0') + 10 * (s[6] - '0') + s[7] - '0';
		double secs = (sum * 125) / 108.0;
		int time = (int)(secs / 1000000);
		string ret = to_string(time);
		time = (int)(secs / 10000) % 100;
		if (time < 10) ret += '0';
		ret += to_string(time);
		time = (int)(secs / 100) % 100;
		if (time < 10) ret += '0';
		ret += to_string(time);
		time = (int)(secs) % 100;
		if (time < 10) ret += '0';
		cout << ret + to_string(time) << endl;
	}
}