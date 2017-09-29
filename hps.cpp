#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
/*
ID: josephh2
PROG: hps
LANG: C++11
*/

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("hps.in"); ofstream fout ("hps.out");
	
	// paper = 0, scissors = 1, hoof = 2
	// 1 > 0, 2 > 1, 0 > 2
	
	int n;
	cin >> n;
	vector<int> plays (n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'P') plays[i] = 0;
		else if (c == 'S') plays[i] = 1;
		else plays[i] = 2;
	}
	
	int bestscore = 0;
	for (int x = 0; x < n/2; x++) {
		int papebef = count(plays.begin(), plays.begin()+x, 0);
		int scisbef = count(plays.begin(), plays.begin()+x, 1);
		int hoofbef = count(plays.begin(), plays.begin()+x, 2);
		int bestbef = max(papebef, max(scisbef, hoofbef));
		
		int papeaft = count(plays.begin()+x, plays.end(), 0);
		int scisaft = count(plays.begin()+x, plays.end(), 1);
		int hoofaft = count(plays.begin()+x, plays.end(), 2);
		int bestaft = max(papeaft, max(scisaft, hoofaft));
		
		int best = bestbef + bestaft;
		if (best > bestscore) bestscore = best;
	}
	cout << bestscore << endl;
}