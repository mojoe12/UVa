#include <iostream>
#include <string>
using namespace std;

bool ifleap (int y) {
	return y % 4 == 0 && (y % 100 || y % 400 == 0);
}

int getday (int m, int y) {
	int x = (ifleap(y)) ? 1 : 0;
	switch (m) {
		case 1: return 31;
		case 2: return 28 + x;
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
		default: return -100000;
	}
}

string sign(int day, int month) {
	if ((month == 1 && day >= 21) || (month == 2 && day <= 19)) return "aquarius";
	if ((month == 2 && day >= 20) || (month == 3 && day <= 20)) return "pisces";
	if ((month == 3 && day >= 21) || (month == 4 && day <= 20)) return "aries";
	if ((month == 4 && day >= 21) || (month == 5 && day <= 21)) return "taurus";
	if ((month == 5 && day >= 22) || (month == 6 && day <= 21)) return "gemini";
	if ((month == 6 && day >= 22) || (month == 7 && day <= 22)) return "cancer";
	if ((month == 7 && day >= 23) || (month == 8 && day <= 21)) return "leo";
	if ((month == 8 && day >= 22) || (month == 9 && day <= 23)) return "virgo";
	if ((month == 9 && day >= 24) || (month == 10 && day <= 23)) return "libra";
	if ((month == 10 && day >= 24) || (month == 11 && day <= 22)) return "scorpio";
	if ((month == 11 && day >= 23) || (month == 12 && day <= 22)) return "sagittarius";
	if ((month == 12 && day >= 23) || (month == 1 && day <= 20)) return "capricorn";
	return "";
}


int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		string input;
		cin >> input;
		int month, day, year;
		month = 10 * (input[0] - '0') + (input[1] - '0');
		day = 10 * (input[2] - '0') + (input[3] - '0');
		year = stoi(input.substr(4, 4));
		for (int i = 0; i < 280; i++) {
			day++;
			if (day > getday(month, year)) {
				day = 1;
				month++;
				if (month > 12) {
					month = 1;
					year++;
				}
			}
		}
		cout << c << ' ';
		if (month < 10) cout << '0';
		cout << month << '/';
		if (day < 10) cout << '0';
		cout << day << '/' << year << " ";
		cout << sign(day, month) << endl;
	}
}