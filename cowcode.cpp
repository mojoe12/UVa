#include <iostream>
#include <cmath>
#include <fstream>
/*
ID: josephh2
PROG: cowcode
LANG: C++11
*/

using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("cowcode.in"); ofstream fout ("cowcode.out");
	
	string s;
	unsigned long long i;
	fin >> s >> i;
	unsigned long long n = s.length();
	
	unsigned long long logi = ceil(log2( (long double) i/n ));
	unsigned long long len = n * (1 << logi);
	
	i--;
	while (i >= n) {
		len >>= 1;
		//cout << i << ' ' << len << endl;
		if (i >= len) i = (i-1)%len;
	}
	fout << s[i] << endl;
}