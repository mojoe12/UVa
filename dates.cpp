#include <iostream>
using namespace std;

bool leap (int year) {
	return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
}

int ndays(int month, bool ifleap) {
	int x = (ifleap) ? 29 : 28;
	switch (month) {
		case 1: return 31;
		case 2: return x;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
		default: return -1;
	}
}

int getmonth (string monthi) {
	if (monthi[1] == 'F') return 2;
	if (monthi[1] == 'D') return 12;
	if (monthi[1] == 'N') return 11;
	if (monthi[1] == 'O') return 10;
	if (monthi[1] == 'S') return 9;
	if (monthi[1] == 'A' && monthi[2] == 'u') return 8;
	if (monthi[1] == 'A') return 4;
	if (monthi[1] == 'J' && monthi[4] == 'e') return 6;
	if (monthi[1] == 'J' && monthi[3] == 'n') return 1;
	if (monthi[1] == 'J') return 7;
	if (monthi[1] == 'M' && monthi[3] == 'y') return 5;
	if (monthi[1] == 'M') return 3;
	if (monthi[1] == 'F') return 2;
	return -1;
}

string monthname(int m) {
	switch (m) {
		case 1: return "-January-";
		case 2: return "-February-";
		case 3: return "-March-";
		case 4: return "-April-";
		case 5: return "-May-";
		case 6: return "-June-";
		case 7: return "-July-";
		case 8: return "-August-";
		case 9: return "-September-";
		case 10: return "-October-";
		case 11: return "-November-";
		case 12: return "-December-";
		default: return "rip";
	}
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int year;
		cin >> year;
		string s;
		cin >> s;
		int month = getmonth(s);
		int currday = 10 * (s[s.length()-2] - '0') + s[s.length()-1] - '0';
		int daysi;
		cin >> daysi;
		for (int d = 0; d < daysi; d++) {
			currday++;
			if (currday > ndays(month, leap(year))) {
				currday = 1;
				month++;
				if (month == 13) {
					month = 1;
					year++;
				}
			}
		}
		cout << "Case " << c << ": " << year << monthname(month);
		if (currday < 10) cout << '0';
		cout << currday << endl;
	}
}