#include <iostream>
#include <fstream>
#include <algorithm>
/*
ID: josephh2
PROG: square
LANG: C++11
*/
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("square.in"); ofstream fout ("square.out");
	int r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2;
	fin >> r1x1 >> r1y1 >> r1x2 >> r1y2;
	fin >> r2x1 >> r2y1 >> r2x2 >> r2y2;
	int llx = min(r1x1, r2x1);
	int lly = min(r1y1, r2y1);
	int upx = max(r1x2, r2x2);
	int upy = max(r1y2, r2y2);
	
	int len = max(upx - llx, upy - lly);
	fout << len * len << endl;
}