#include <iostream>

using namespace std;
int modify (string s);
string bend(int d, int m);
int main(int argc, char *argv[]) {
	 while (true) {
		int l;
		cin >> l;
		if (l == 0) break;
		string direc = "+x";
		for (int i = 0; i < l-1; i++) {
			string s;
			cin >> s;
			direc = bend(modify(direc), modify(s));
		}
		cout << direc << endl;
	}
}
int modify (string s) {
	if (s == "+x") return 1;
	if (s == "-x") return -1;
	if (s == "+y") return 2;
	if (s == "-y") return -2;
	if (s == "+z") return 3;
	if (s == "-z") return -3;
	return 0;
}
string bend(int d, int m) {
	switch (d) {
		case 1: switch (m) {
			case 0: return "+x";
			case 2: return "+y";
			case -2: return "-y";
			case 3: return "+z";
			case -3: return "-z";
		}
		case -1: switch (m) {
			case 0: return "-x";
			case 2: return "-y";
			case -2: return "+y";
			case 3: return "-z";
			case -3: return "+z";
		}
		case 2: switch (m) {
			case 0: return "+y";
			case 2: return "-x";
			case -2: return "+x";
			case 3: return "+y";
			case -3: return "+y";
		}
		case -2: switch (m) {
			case 0: return "-y";
			case 2: return "+x";
			case -2: return "-x";
			case 3: return "-y";
			case -3: return "-y";
		}
		case 3: switch (m) {
			case 0: return "+z";
			case 2: return "+z";
			case -2: return "+z";
			case 3: return "-x";
			case -3: return "+x";
		}
		case -3: switch (m) {
			case 0: return "-z";
			case 2: return "-z";
			case -2: return "-z";
			case 3: return "+x";
			case -3: return "-x";
		}
		default: return "";
	}
}