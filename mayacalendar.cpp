#include <iostream>
using namespace std;
int getmonth(string name);
string getname (int num);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	cout << k << endl;
	for (int c = 0; c < k; c++) {
		int days;
		cin >> days;
		string months;
		cin >> months;
		cin >> months;
		int month = getmonth(months);
		int year;
		cin >> year;
		int numdays = days + year * 365 + month * 20;
		int nyears = numdays / 260;
		int num = 1 + (numdays % 260) % 13;
		string name = getname((numdays % 260) % 20);
		cout << num << " " << name << " " << nyears << endl;
	}
}
int getmonth(string name) {
	if (name == "pop") return 0;
	if (name == "no") return 1;
	if (name == "zip") return 2;
	if (name == "zotz") return 3;
	if (name == "tzec") return 4;
	if (name == "xul") return 5;
	if (name == "yoxkin") return 6;
	if (name == "mol") return 7;
	if (name == "chen") return 8;
	if (name == "yax") return 9;
	if (name == "zac") return 10;
	if (name == "ceh") return 11;
	if (name == "mac") return 12;
	if (name == "kankin") return 13;
	if (name == "muan") return 14;
	if (name == "pax") return 15;
	if (name == "koyab") return 16;
	if (name == "cumhu") return 17;
	if (name == "uayet") return 18;
	return -1;
}
string getname (int num) {
	switch (num) {
		case 0: return "imix";
		case 1: return "ik";
		case 2: return "akbal";
		case 3: return "kan";
		case 4: return "chicchan";
		case 5: return "cimi";
		case 6: return "manik";
		case 7: return "lamat";
		case 8: return "muluk";
		case 9: return "ok";
		case 10: return "chuen";
		case 11: return "eb";
		case 12: return "ben";
		case 13: return "ix";
		case 14: return "mem";
		case 15: return "cib";
		case 16: return "caban";
		case 17: return "eznab";
		case 18: return "canac";
		case 19: return "ahau";
		default: return "";
	}
}