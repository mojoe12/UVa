#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input


	// loop through it, apply function
	
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int c = 0; c < k; c++) {
		
		vector<string> ram (1000, "000");
		vector<int> reg (10);
		for (int i = 0; getline(cin, s); i++) {
			if (s == "") break;
			ram[i] = s;
		}
		
		int counter = 0;
		bool ifhalted = false;
		for (int i = 0; !ifhalted && i < ram.size(); i++) {
			
			//for (int j = 0; j < 10; j++) cout << reg[j] << ' '; for (int j = 0; j < ram.size(); j++) cout << ram[j] << ' '; cout << endl;
			
			int a = ram[i][1] - '0', b = ram[i][2] - '0';
			switch (ram[i][0]) 
			{
				case '0': {
					if (reg[b]) i = reg[a]-1;
					break;
				}
				case '1': {
					if (a == 0 && b == 0) ifhalted = true;
					break;
				}
				case '2': {
					reg[a] = b;
					break;
				}
				case '3': {
					reg[a] = (b + reg[a]) % 1000;
					break;
				}
				case '4': {
					reg[a] = (b * reg[a]) % 1000;
					break;
				}
				case '5': {
					reg[a] = reg[b];
					break;
				}
				case '6': {
					reg[a] = (reg[a] + reg[b]) % 1000;
					break;
				}
				case '7': {
					reg[a] = (reg[a] * reg[b]) % 1000;
					break;
				}
				case '8': {
					string r = ram[reg[b]];
					reg[a] = (r[0] - '0') * 100 + (r[1] - '0') * 10 + (r[2] - '0');
					break;
				}
				case '9': {
					int toR = reg[a];
					string r = "000";
					r[2] += toR % 10;
					r[1] += (toR / 10) % 10;
					r[0] += toR / 100;
					ram[reg[b]] = r;
					break;
				}
			}
			
			counter++;
		}
		
		if (c) cout << endl;
		cout << counter << endl;
		
	}


	// output answer


}

// function definitions

