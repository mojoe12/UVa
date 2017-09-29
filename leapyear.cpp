#include <iostream>
using namespace std;

bool div3(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += (s[i] - '0');
	}
	return sum % 3 == 0;
}

bool div4(string s) {
	int x = (s[s.length()-1] - '0');
	x += 10 * (s[s.length()-2] - '0');
	return x % 4 == 0;
}

bool div5(string s) {
	char c = s[s.length()-1];
	return c == '0' || c == '5';
}

bool div11(string s) {
	int sume = 0, sumo = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i%2 == 0) sume += (s[i] - '0');
		else sumo += (s[i] - '0');
	}
	return (sumo - sume) % 11 == 0;
}

bool div100(string s) {
	return (s[s.length()-1] == '0') && (s[s.length()-2] == '0');
}

bool div400(string s) {
	if (!div100(s)) return false;
	int x = (s[s.length()-3] - '0');
	x += 10 * (s[s.length()-4] - '0');
	return x % 4 == 0;
}

int main(int argc, char *argv[]) {
	string y;
	bool ifspace = false;
	while (cin >> y) {
		if (ifspace) cout << endl;
		else ifspace = true;
		
		bool leap = div4(y) && (!div100(y) || div400(y));
		bool hulu = div3(y) && div5(y);
		bool bulu = leap && div5(y) && div11(y);
		bool ordy = !(leap || hulu || bulu);
		if (leap) cout << "This is leap year." << endl;
		if (hulu) cout << "This is huluculu festival year." << endl;
		if (bulu) cout << "This is bulukulu festival year." << endl;
		if (ordy) cout << "This is an ordinary year." << endl;
	}
}