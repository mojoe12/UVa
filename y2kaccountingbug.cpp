#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void account(string months, int s, int d, int& maxtotal);

int main() {
	
	int s, d;
	while (cin >> s >> d) {
		string months = "";
		int maxtotal = 0;
		account(months, s, d, maxtotal);
		if (maxtotal) cout << maxtotal << endl;
		else cout << "Deficit\n";
	}
}

void account(string months, int s, int d, int& maxtotal) 
{
	int l = months.length();
	if (l == 12) {
		int sum = 0;
		for (int i = 0; i < 12; i++) {
			if (months[i] == 's') sum += s;
			if (months[i] == 'd') sum -= d;
		}
		maxtotal = max(maxtotal, sum);
		return;
	}
	
	int sum = 0;
	if (l >= 4) {
		for (int i = 1; i < 5; i++) {
			if (months[l - i] == 's') sum += s;
			if (months[l - i] == 'd') sum -= d;
		}
	}
	if (l < 4 || sum + s < 0) {
		months += 's';
		account(months, s, d, maxtotal);
		months = months.substr(0, l);
	}
	if (l < 4 || sum - d < 0) {
		months += 'd';
		account(months, s, d, maxtotal);
		months = months.substr(0, l);
	}
}