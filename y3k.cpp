#include <iostream>
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

void pass (int &day, int &month, int &year) {
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

int main(int argc, char *argv[]) {
	while (true) {
		int ndays, day, month, year;
		cin >> ndays >> day >> month >> year;
		if (day == 0) break;
		
		while (ndays > 364) {
			ndays -= 365;
			if (ndays > 0 && ifleap((month < 3) ? year : year+1)) ndays--;
			year++;
		}
		
		for (int i = 0; i < ndays; i++) {
			pass(day, month, year);
		}
		cout << day << " " << month << " " << year << endl;
	}
}