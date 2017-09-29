#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
/*
ID: josephh2
PROG: blocks
LANG: C++11
*/
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("blocks.in"); ofstream fout ("blocks.out");
	int n;
	fin >> n;
	vector<int> total (26), currenta (26), currentb(26);
	for (int i = 0; i < n; i++) {
		string a, b;
		fin >> a >> b;
		
		fill(currenta.begin(), currenta.end(), 0);
		fill(currentb.begin(), currentb.end(), 0);
		
		for (int j = 0; j < a.length(); j++) {
			char c = a[j];
			int x = c - 'a';
			currenta[x]++;
		}
		for (int j = 0; j < b.length(); j++) {
			char c = b[j];
			int x = c - 'a';
			currentb[x]++;
		}
		
		for (int j = 0; j < 26; j++) {
			total[j] += max(currenta[j], currentb[j]);
		}
		
	}
	for (int i = 0; i < 26; i++) {
		fout << total[i] << endl;
	}
}