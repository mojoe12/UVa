#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool next(string& s) 
{
	s[2]++;
	if (s[2] == '4') 
	{
		s[2] = '0';
		s[1]++;
	}
	if (s[1] == '4') 
	{
		s[1] = '0';
		s[0]++;
	}
	return s[0] != '4';
}

void rotateRight(string& s) {
	string t = s;
	s[3] = t[1];
	s[4] = t[3];
	s[2] = t[4];
	s[1] = t[2];
}

void rotateUp(string& s) {
	string t = s;
	s[0] = t[1];
	s[4] = t[0];
	s[5] = t[4];
	s[1] = t[5];
}

void rotateAround(string& s) {
	string t = s;
	s[3] = t[0];
	s[5] = t[3];
	s[2] = t[5];
	s[0] = t[2];
}


int main(int argc, char *argv[]) {
	string s;
	while (cin >> s) 
	{
		string start = s.substr(0, 6);
		string end = s.substr(6, 6);
				
		bool ifposs = false;
		string x = "000";
		string working;
		
		do {
			working = start;
			for (int i = 0; i < x[0] - '0'; i++) {
				rotateRight(working);
			}
			for (int i = 0; i < x[1] - '0'; i++) {
				rotateUp(working);
			}
			for (int i = 0; i < x[2] - '0'; i++) {
				rotateAround(working);
			}
			ifposs = working == end;
		} while (!ifposs && next(x));
		
		if (ifposs) cout << "TRUE\n";
		else cout << "FALSE\n";
		
	}
}