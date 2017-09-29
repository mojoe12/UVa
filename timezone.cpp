#include <iostream>
using namespace std;
float convert (string tz) {
	if (tz == "UTC") return 0;
	if (tz == "GMT") return 0;
	if (tz == "BST") return 1;
	if (tz == "IST") return 1;
	if (tz == "WET") return 0;
	if (tz == "WEST") return 1;
	if (tz == "CET") return 1;
	if (tz == "CEST") return 2;
	if (tz == "EET") return 2;
	if (tz == "EEST") return 3;
	if (tz == "MSK") return 3;
	if (tz == "MSD") return 4;
	if (tz == "AST") return -4;
	if (tz == "ADT") return -3;
	if (tz == "NST") return -3.5;
	if (tz == "NDT") return -2.5;
	if (tz == "EST") return -5;
	if (tz == "EDT") return -4;
	if (tz == "CST") return -6;
	if (tz == "CDT") return -5;
	if (tz == "MST") return -7;
	if (tz == "MDT") return -6;
	if (tz == "PST") return -8;
	if (tz == "PDT") return -7;
	if (tz == "HST") return -10;
	if (tz == "AKST") return -9;
	if (tz == "AKDT") return -8;
	if (tz == "AEST") return 10;
	if (tz == "AEDT") return 11;
	if (tz == "ACST") return 9.5;
	if (tz == "ACDT") return 10.5;
	if (tz == "AWST") return 8;
	return -1;
}

int main(int argc, char *argv[]) {
	int k, hour, min;
	cin >> k;
	for (int c = 0; c < k; c++) {
		
		string timei, amorpm, otz, ntz;
		bool ifpm = true;
		cin >> timei;
		if (timei  == "midnight" || timei == "noon") {
			ifpm = timei == "noon";
			hour = 12;
			min = 0;
		}
		else {
			int i = 0;
			hour = timei[i++] - '0';
			if (timei[i] != ':') hour = 10 * hour + timei[i++] - '0';
			min = 10 * (timei[i+1] - '0') + timei[i+2] - '0';
			cin >> amorpm;
			if (amorpm == "a.m.") ifpm = false;
		}
		if (hour == 12) hour = 0;
		
		cin >> otz >> ntz;
		float tdiff = convert(ntz) - convert(otz);
		hour += (int) tdiff;
		min += 60 * (tdiff - (int) tdiff);

		if (min >= 60) {
			hour++;
			min -= 60;
		}
		if (min < 0) {
			hour--;
			min += 60;
		}
		if (hour > 11) {
			ifpm = !ifpm;
			hour -= 12;
		}
		if (hour < 0) {
			ifpm = !ifpm;
			hour += 12;
		}
		if (hour > 11) {
			ifpm = !ifpm;
			hour -= 12;
		}
		if (hour < 0) {
			ifpm = !ifpm;
			hour += 12;
		}
		if (hour == 0) hour = 12;
		
		if (hour == 12 && min == 0) {
			if (ifpm) cout << "noon\n";
			else cout << "midnight\n";
		}
		else {
			cout << hour << ':';
			if (min < 10) cout << '0';
			if (ifpm) cout << min <<  " p.m.\n";
			else cout << min << " a.m.\n";
		}
	}
}