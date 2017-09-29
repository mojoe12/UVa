/*#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
/*
ID: josephh2
PROG: haybales
LANG: C++11

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("haybales.in"); ofstream fout ("haybales.out");
	
	int n, q;
	fin >> n >> q;
	vector<int> hays (n);
	for (int i = 0; i < n; i++) {
		fin >> hays[i];
	}
	sort(hays.begin(), hays.end());
	
	const int counter = 50;
	
	map<int, double> positions;
	int previous = 0;
	for (int i = 0; i < n; i++) {
		for (int j = previous; i > 0 && j < hays[i]; j += counter) {
			positions.insert(pair<int, double> (j, i - .5));
		}
		positions.insert(pair<int, double> (hays[i], i));
		previous = 1 + hays[i];
	}
	
	for (int i = 0; i < q; i++) {
		int a, b;
		fin >> a >> b;
		int lowindex = 0;
		if (a < hays[0]) lowindex = 0;
		else if (a > hays[n-1]) lowindex = n;
		else {
			for (int j = 0; j <= counter; j++) {
				if (positions.count(a-j)) {
					lowindex = ceil(positions[a-j]);
					break;
				}
			}
		}
		
		int highindex = 0;
		if (b < hays[0]) highindex = -1;
		else if (b > hays[n-1]) highindex = n-1;
		else {
			for (int j = 0; j <= counter; j++) {
				if (positions.count(b+j))  {
					highindex = floor(positions[b+j]);
					break;
				}
			}
		}
		fout << 1 + highindex - lowindex << endl;
	}
}*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
/*
ID: josephh2
PROG: haybales
LANG: C++11
*/
using namespace std;
int main() {
	ifstream fin ("haybales.in"); ofstream fout ("haybales.out");
	
	int n, q;
	fin >> n >> q;
	vector<int> hays (n);
	for (int i = 0; i < n; i++) fin >> hays[i];
	sort(hays.begin(), hays.end());
	
	for (int i = 0; i < q; i++) {
		int a, b;
		fin >> a >> b;
		
		int num = 0;
		for (int j = 0; j < n; j++) {
			if (hays[j] > b) break;
			if (hays[j] >= a) num++;
		}
		fout << num << endl;
	}
}