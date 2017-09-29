#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

pair<int, int> tonums (string s) {
	int num1 = 0, num2 = 0;
	int i = 0;
	for (; i < s.size(); i++) {
		if (s[i] == ' ') {
			i++;
			break;
		}
		num1 = 10 * num1 + (s[i] - '0');
	}
	for (; i < s.size(); i++) {
		num2 = 10 * num2 + (s[i] - '0');
	}
	return make_pair(num1, num2);
}

int tonum (string s) {
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		num = 10 * num + (s[i] - '0');
	}
	return num;
}


int main() {
	
	
	string s;
	getline(cin, s);
	int k = tonum(s);
	getline(cin, s);
	
	
	for (int c = 0; c < k; c++) {
		if (c) cout << endl;
		getline(cin, s);
		int numyears = tonum(s);
		vector< vector<bool> > space (22, vector<bool> (22, false));
		while (getline(cin, s)) {
			if (s == "") break;
			space[tonums(s).first][tonums(s).second] = true;
		}
		
		for (int y = 0; y < numyears; y++) {
			
			for (int i = 0; i < 20; i++) cout << '*'; cout << endl;
			
			for (int i = 1; i <= 20; i++) {
				for (int j = 1; j <= 20; j++) {
					cout << (space[i][j] ? 'O' : ' ');
				}
				cout << endl;
			}
			
			vector< vector<bool> > newyear = space;
			
			for (int i = 1; i <= 20; i++) {
				for (int j = 1; j <= 20; j++) {
					
					int nn = 0; // number of neighbors
					
					nn += space[i-1][j-1];
					nn += space[i-1][j];
					nn += space[i-1][j+1];
					nn += space[i][j-1];
					nn += space[i][j+1];
					nn += space[i+1][j-1];
					nn += space[i+1][j];
					nn += space[i+1][j+1];
					
					if (space[i][j] && (nn < 2 || nn > 3)) newyear[i][j] = false;
					if (!space[i][j] && nn == 3) newyear[i][j] = true;
				}
			}
			
			space = newyear;
		}
		for (int i = 0; i < 20; i++) cout << '*'; cout << endl;
	}
	
	
}