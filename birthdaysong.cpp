#include <iostream>

using namespace std;
bool sum(int size, bool uses[]);

int main(int argc, char *argv[]) {
	string song[16] = {
		"Happy", "birthday", "to", "you", 
		"Happy", "birthday", "to", "you", 
		"Happy", "birthday", "to", "Rujia", 
		"Happy", "birthday", "to", "you"
	};
	int n;
	cin >> n;
	string* singers = new string [n];
	for (int i = 0; i < n; i++) cin >> singers[i];
	bool uses[n];
	for (int i = 0; i < n; i++) uses[i] = false;
	
	int wnum = 0, pnum = 0;
	while (wnum != 0 || !sum(n, uses)) {
		cout << singers[pnum] << ": " << song[wnum] << endl;
		uses[pnum] = true;
		wnum++;
		pnum++;
		if (wnum >= 16) wnum = 0;
		if (pnum >= n) pnum = 0;
	}
	delete [] singers;
}

bool sum(int size, bool uses[]) {
	bool ifallused = true;
	for (int i = 0; i < size; i++)
		ifallused = ifallused && uses[i];
	return ifallused;
}