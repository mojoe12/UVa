#include <iostream>
#include <string>
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
bool ifpal(int hour, int min) {
	string s = "";
	if (hour != 0) s = to_string(hour);
	string add = to_string(min);
	if (min < 10 && hour != 0) add = "0" + add;
	s += add;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - i-1]) return false;
	}
	return true;
}
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	vector<string> answers (k);
	for (int c = 0; c < k; c++) {
		string t;
		cin >> t;
		int hour = tonum(t, 1), min = tonum(t,0);
		do {
			min++;
			if (min == 60) {
				min = 0;
				hour++;
				if (hour == 24) hour = 0;
			}
		} while (!ifpal(hour, min));
		//cout << totime(hour, min) << endl;
		answers[c] = totime(hour, min);
	}
	for (int c = 0; c < k; c++) cout << answers[c] << endl;
}