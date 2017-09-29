#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations



int main() {
	
	// setup input
	
	string s;
	while (getline(cin, s)) {
		if (s == "Game Over") break;
		
		int sum = 0;
		int count1 = 1, count2 = 1;
		int prev = 0, frame = 1;
		bool if2 = false;
		for (int i = 0; i < s.size(); i += 2) {
			char c = s[i];
			int num = c - '0';
			if (c == '/') num = (10 - prev);
			else if (c == 'X') num = 10;
			
			sum += num * count1;
			
			count1 = count2;
			count2 = 1 + (c == 'X' && frame < 10);
			if ((c == '/' || c == 'X') && frame < 10) count1++;
			
			if (if2 || c == 'X') frame++;
			if2 = !if2 && (c != 'X');
			prev = num;
		}
		
		cout << sum << endl;
	}
	


	// loop through it, apply function


	// output answer


}

// function definitions

