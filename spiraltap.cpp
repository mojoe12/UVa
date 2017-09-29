#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		long long size, pos;
		cin >> size >> pos;
		if (size == 0 && pos == 0) break;
		long long a = 1 + 2 * ( ((int) sqrt(pos) -1) /2 );
		int direc = 1; // up, left, down, right
		long long p = a*a, x = (size+a)/2, y = x;
		if (p != pos) {
			y++;
			p++;
			for (double move = a+.5; p < pos;) {
				for (int i = 0; i < (long long) move && p < pos; i++) {
					p++;
					if (direc == 0) y++;
					else if (direc == 1) x--;
					else if (direc == 2) y--;
					else if (direc == 3) x++;
				}
				move += .5;
				direc = (direc + 1) % 4;
			}
		}
		cout << "Line = " << y << ", column = " << x << ".\n";
	}
}