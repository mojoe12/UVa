#include <iostream>
using namespace std;
string getname (int d);
int end (int m);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int month, day;
		cin >> month >> day;
		int m = 1, d = 1, w = 6, ans = 0;
		while (m != 13) {
			if (m == month && d == day) {
				ans = w;
				break;
			}
			w++;
			if (w == 7) w = 0;
			if (d == end(m)) {
				m++;
				d = 1; 
			}
			else d++;
		}
		cout << getname(w) << endl;
	}
}

string getname (int d) {
	switch (d) {
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		default: return "uhoh";
	}
}

int end (int m) {
	switch (m) {
		case 1: return 31;
		case 2: return 28;
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