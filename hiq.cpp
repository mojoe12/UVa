#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int checkleft (int n) {
	switch (n) {
		case 3: return 1;
		case 6: return 4;
		case 30: return 28;
		case 33: return 31;
	}
	if (n > 6 && n < 28 && n % 7 > 1) return n-2;
	return 0;
}
int checkright (int n) {
	switch (n) {
		case 1: return 3;
		case 4: return 6;
		case 28: return 30;
		case 31: return 33;
	}
	if (n > 6 && n < 28 && n % 7 < 5) return n+2;
	return 0;
}

int checkbottom (int n) {
	if (n > 25) return 0;
	if (n < 4 || n > 22) return n + 8;
	if (n < 7 || (n > 15 && n < 19)) return n + 12;
	if (n < 14) return n + 14;
	return 0;
}
int checktop (int n) {
	if (n < 9) return 0;
	if (n > 30 || n < 12) return n - 8;
	if (n > 27 || (n < 19 && n > 15)) return n - 12;
	if (n > 20) return n - 14;
	return 0;
}

int checkleft1 (int n) {
	return n-1;
}
int checkright1 (int n) {
	return n+1;
}

int checkbottom1 (int n) {
	if (n > 18) return n + 5;
	if (n > 6) return n + 7;
	if (n > 3) return n + 5; 
	return n+3;
}

int checktop1 (int n) {
	if (n < 16) return n - 5;
	if (n < 28) return n - 7;
	if (n < 31) return n - 5; 
	return n-3;
}




int main() {
	
	int k;
	cin >> k;
	cout << "HI Q OUTPUT\n";
	for (int c = 0; c < k; c++) {
		vector<bool> game (34, false);
		int x;
		while (cin >> x) {
			if (!x) break;
			game[x] = true;
		}
		
		while (true) {
			bool moved = false;
			
			/*cout << "  "; for (int i = 1; i < 4; i++) cout << game[i]; cout << endl;
			cout << "  "; for (int i = 4; i < 7; i++) cout << game[i]; cout << endl;
			for (int i = 7; i < 14; i++) cout << game[i]; cout << endl;
			for (int i = 14; i < 21; i++) cout << game[i]; cout << endl;
			for (int i = 21; i < 28; i++) cout << game[i]; cout << endl;
			cout << "  "; for (int i = 28; i < 31; i++) cout << game[i]; cout << endl;
			cout << "  "; for (int i = 31; i < 34; i++) cout << game[i]; cout << endl;
*/
			
			for (int n = 33; !moved && n > 0; n--) {
				if (game[n]) continue;
				// check if theres a move to make
				if (game[checkbottom(n)] && game[checkbottom1(n)]) {
					game[checkbottom1(n)] = game[checkbottom(n)] = false;
					game[n] = moved = true;
					//cout << 'B' << n << endl;
				}
				else if (game[checkright(n)] && game[checkright1(n)]) {
					game[checkright1(n)] = game[checkright(n)] = false;
					game[n] = moved = true;
					//cout << 'R' << n << endl;
				}
				else if (game[checkleft(n)] && game[checkleft1(n)]) {
					game[checkleft1(n)] = game[checkleft(n)] = false;
					game[n] = moved = true;
					//cout << 'L' << n << endl;
				}
				else if (game[checktop(n)] && game[checktop1(n)]) {
					game[checktop1(n)] = game[checktop(n)] = false;
					game[n] = moved = true;
					//cout << 'T' << n << endl;
				}
			}
			
			if (!moved) break;
			
		}
		int sum = 0;
		for (int i = 1; i < 34; i++) {
			sum += (game[i]) * i;
		}
		cout << sum << endl;
	}
	cout << "END OF OUTPUT\n";




}


