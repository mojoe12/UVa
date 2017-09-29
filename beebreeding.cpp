#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

pair<int, int> getcoords (int n) {
	int row = 0;
	int start = sqrt((n-1) / 3) - 1; // change
	for (int i = max(start, 0); ; i++) {
		if (3 * i * (i + 1) + 1 >= n) {
			row = i;
			break;
		}
	}
	
	int maxn = 3 * row * (row + 1) + 1;
	
	int cx = row, cy = 0;
	int edge = 0, index = 0;
	for (int i = maxn; i > n; i--) {
		
		if (edge == 0) {
			cy--;
			if (cy == -row) edge++;
		}
		else if (edge == 1) {
			cx--;
			if (cx == 0) edge++;
		}
		else if (edge == 2) {
			cx--;
			cy++;
			if (cy == 0) edge++;
		}
		else if (edge == 3) {
			cy++;
			if (cy == row) edge++;
		}
		else if (edge == 4) {
			cx++;
			if (cx == 0) edge++;
		}
		else if (edge == 5) {
			cx++;
			cy--;
		}
		}
	
	return make_pair(cx, cy);
}




int main() {
	
	// setup input
	int a, b;
	while (cin >> a >> b) {
		if (!a && !b) break;
		
		pair<int, int> coordsa = getcoords(a);
		int ax = coordsa.first, ay = coordsa.second;
		pair<int, int> coordsb = getcoords(b);
		int bx = coordsb.first, by = coordsb.second;
		
		// im gonna try physically jumping to the next one
		// map out which are the neighbors

		int dist = 0;
		while (ax != bx || ay != by) 
		{
			if (ax < bx && ay > by) {
				ax++;
				ay--;
			}
			else if (ax > bx && ay < by) {
				ax--;
				ay++;
			}
			else if (ax < bx) ax++;
			else if (ax > bx) ax--;
			else if (ay < by) ay++;
			else if (ay > by) ay--;
			
			dist++;
		}
		cout << "The distance between cells " << a << " and ";
		cout << b << " is " << dist << ".\n";
	}
}