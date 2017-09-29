#include <iostream>
#include <cmath>
#include <fstream> 
using namespace std;
const int n4period = 100;

int main(int argc, char *argv[]) {
	/*
	ifstream fin ("ryansnumbers.txt"); ofstream fout ("dmrop.txt");
	double t, fun, fun0, fun1, bestoi = 0;
	int number = 0;
	for (int counter = 0; fin >> t >> fun; counter++) {
		if (counter % n4period == 0) {
			fout << t << "\t";
			fun0 = fun;
			bestoi = 0;
		}
		if (abs(fun) > bestoi) bestoi = abs(fun);
		if (counter % n4period == 1) fun1 = fun;
		if (counter % n4period == n4period - 1) {
			switch ((int)ceil(bestoi)) {
				case 1: {fout << "00"; break;}
				case 2: {fout << "01"; break;}
				case 3: {fout << "10"; break;}
				default: fout << "11";
			}
			if (round(fun0) > ceil(bestoi) * 0.5) fout << "01\n";
			else if (round(fun0) < ceil(bestoi) * - 0.5) fout << "11\n";
			else if (fun1 > fun0) fout << "00\n";
			else fout << "10\n";
		}
	}*/
	ifstream fin("dmrop.txt");
	double time1, time2;
	string x1, x2;
	while (fin >> time1 >> x1 >> time2 >> x2) {
		x1 += x2;
		int num = 0;
		for (int i = 0; i < 8; i++) {
			num += (x1[i] - '0') * pow(2, 7-i);
		}
		char c = ' ' + num - 32;
		cout << c;
	}
}