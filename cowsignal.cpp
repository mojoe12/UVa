#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
/*
ID: josephh2
PROG: cowsignal
LANG: C++11
*/
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("cowsignal.in"); ofstream fout ("cowsignal.out");
	
	int m, n, k;
	fin >> m >> n >> k;
	
	vector<vector<char> > sig (m, vector<char>(n));
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			fin >> sig[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int y = 0; y < k; y++) {
			for (int j = 0; j < n; j++) {
				for (int x = 0; x < k; x++) {
					fout << sig[i][j];
				}
			}
			fout << endl;
		}
	}

}