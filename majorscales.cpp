#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

void check (vector<bool>& scales, int note) {
	for (int i = 0; i < 12; i++) {
		int dist = (note >= i) ? note-i : 12 - i + note;
		switch (dist) {
			case 1:
			case 3:
			case 6:
			case 8:
			case 10:
			scales[i] = false;
		}
	}
}


int main() {
	
	string num2note[12] = {"C", "C#", "D", "D#", 
	"E", "F", "F#", "G", "G#", "A", "A#", "B"};
	
	map<string, int> note2num;
	for (int i = 0; i < 12; i++) {
		note2num.insert( make_pair(num2note[i], i));
	}
	
	string s;
	while (getline(cin, s)) {
		if (s == "END") break;
		
		vector<bool> scales (12, true);
		
		int i = 0;
		while (i < s.size()) {
			string note = ""; 
			note += s[i++];
			if (i < s.size() && s[i] != ' ') note += s[i++];
			i++;
			check(scales, note2num[note]);
		}
		
		bool iffirst = true;
		for (int i = 0; i < 12; i++) {
			if (scales[i]) {
				if (!iffirst) cout << ' ';
				else iffirst = false;
				cout << num2note[i];
			}
		}
		cout << endl;
	}




}


