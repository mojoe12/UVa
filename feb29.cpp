#include <iostream>
#include <cmath>
using namespace std;

int getmonth (string monthi) {
	switch (monthi[0]) {
		case 'F': return 2;
		case 'D': return 12;
		case 'N': return 11;
		case 'O': return 10;
		case 'S': return 9;
		case 'M': return (monthi[2] == 'y') ? 5 : 3;
		case 'A': return (monthi[1] == 'u') ? 8 : 4;
		case 'J': return (monthi[3] == 'e') ? 6 : (monthi[2] == 'n') ? 1: 7;
		default: return -1;
	}
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		string months1, months2;
		char nothin;
		long long day1, year1, day2, year2;
		cin >> months1 >> day1 >> nothin >> year1 >> months2 >> day2 >> nothin >> year2;
		int month1 = getmonth(months1), month2 = getmonth(months2);
		long long curryear = (month1 > 2) ? year1+1 : year1;
		long long lastyear = (month2 > 2 || (month2 == 2 && day2 == 29)) ? year2 : year2-1;
		curryear = 4 * (long long) ceil (curryear / 4.0);
		lastyear = 4 * (lastyear / 4);
		long long nleaps = 0;
		if (lastyear - curryear > 100) {
			long long fto400 = 400 * (long long) ceil (curryear / 400.0), bto400 = 400 * (lastyear / 400);
			nleaps = 1 + 97 * (bto400 - fto400) / 400;
			nleaps += (fto400 - curryear) / 4 - (fto400 - curryear) / 100;
			nleaps += (lastyear - bto400) / 4 - (lastyear - bto400) / 100;
		}
		else {
			for (; curryear <= lastyear; curryear += 4) {
				if (curryear % 4 == 0 && (curryear % 400 == 0 || curryear % 100 != 0)) nleaps++;
			}
		}
		cout << "Case " << c << ": " << nleaps << endl;
	}
}