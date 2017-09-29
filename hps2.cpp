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
	fin >> n;
	vector<int> plays (n);
	for (int i = 0; i < n; i++) {
		char c;
		fin >> c;
		if (c == 'P') plays[i] = 0;
		else if (c == 'S') plays[i] = 1;
		else plays[i] = 2;
	}
	
	int bestscore = 0;
	vector<int> counts(3);
	for (int x = 0; x < n; x++) {
		fill(counts.begin(), counts.end(), 0);
		
		int i = 0, bestbef = 0;
		for_each(plays.begin(), plays.begin()+x, [&counts] (int p){ counts[p]++; });
		int best = max(counts[0], max(counts[1], counts[2]) );

		fill(counts.begin(), counts.end(), 0);
		for_each(plays.begin()+x, plays.end(), [&counts] (int p){ counts[p]++; });
		best += max(counts[0], max(counts[1], counts[2]) );
		
		if (best > bestscore) bestscore = best;
	}
	fout << bestscore << endl;
}