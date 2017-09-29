/*#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
double carrier (double t) {
	return sin(6283 * t);
}
double amfunc (double t) {
	return 500 / t;
}
double fmfunc (double integral, double t) {
	return cos(6283 * t + integral);
}
double integral (double t) {
	return t * t * t * 500 / 3;
}

int main(int argc, char *argv[]) {
	ofstream fout ("modoutput.txt");
	fout << fixed << setprecision(10);
	//amplitude modulation
	for (double t = 0; t <= 0.2; t += .0001) {
		cout << t;
		fout << t << " " << carrier(t) * amfunc(t) << endl;
	}
	// frequency modulation
	const int fdev = 1000;
	for (double t = 0; t <= 0.2; t += .0001) {
		double newintegral = 6.283 * 1000 * integral(t);
		fout << t << " " << fmfunc(newintegral, t) << endl;
	}
}
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ifstream fin ("ryansnumbers.txt"); ofstream fout ("moddecode.txt");
	double t, func;
	while (fin >> t >> func){
		double middle = 13.14159 - 2.094*t*t;
		fout << t << "\t" << acos(func) / middle << endl;
	}
}