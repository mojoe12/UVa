#include <iostream>

using namespace std;
int turn(int a, int b, bool ifclockwise);

int main(int argc, char *argv[]) {
	while (true) {
		int pos0, posa, posb, posc;
		cin >> pos0 >> posa >> posb >> posc;
		if (pos0 == 0 & posa == 0 && posb == 0 && posc == 0) break;
		int sum = 1080;
		sum += turn(pos0, posa, false);
		sum += turn(posa, posb, true);
		sum += turn(posb, posc, false);
		cout << sum << endl;
	}
}

int turn(int a, int b, bool ifcounter) {
	int pos = a;
	int sumdegree = 0;
	while (pos != b) {
		if (ifcounter) pos++;
		else pos--;
		sumdegree += 9;
		if (pos == 40) pos = 0;
		if (pos == -1) pos = 39;
	}
	return sumdegree;
}