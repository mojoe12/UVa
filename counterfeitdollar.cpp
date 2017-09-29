#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// dont disprove it's light. guess that its light
// fuck how many times am i going to fuck this up

bool check (vector<string>& input, char d, bool ifheavy) {
	int inc = (ifheavy) ? 1 : -1;
	for (int comp = 0; comp < 9; comp += 3) {
		string a = input[comp], b = input[comp+1], c = input[comp+2];
		
		int l = 0, r = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == d) l += inc;
			if (b[i] == d) r += inc;
		}
				
		if (c == "even" && l != r) return false;
		if (c == "up" && l <= r) return false;
		if (c == "down" && l >= r) return false;
	}
	return true;
}


int main() {
	
	int k;
	cin >> k;
	
	for (int y = 0; y < k; y++) {
		vector<string> input (9);
		for (int i = 0; i < 9; i++) cin >> input[i];
		
		char answer = ' ';
		bool ifheavy = true;
		
		for (char d = 'A'; d <= 'L'; d++) 
		{
			bool heavyok = check(input, d, true);
			bool lightok = check(input, d, false);
			if (heavyok != lightok) answer = d;
			if (lightok) ifheavy = false;
		}
		
		cout << answer << " is the counterfeit coin and it is ";
		if (ifheavy) cout << "heavy.\n";
		else cout << "light.\n";
		
	}
}


