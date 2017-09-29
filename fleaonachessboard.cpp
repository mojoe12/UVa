#include <iostream>

using namespace std;

int main() {
	
	while (true) {
		int s, x, y, dx, dy;
		cin >> s >> x >> y >> dx >> dy;
		if (!s) break;
		
		int njumps = 0;
		int cx = x, cy = y;
		bool possibl = true;
		for (; !( (cx/s + cy/s) % 2 && cx % s && cy % s); njumps++) {
			cx += dx;
			cy += dy;
			if (njumps > 1005) {
				possibl = false;
				break;
			};
		}
		
		if (possibl) {
			cout << "After " << njumps << " jumps the flea lands at (" << cx << ", " << cy << ").\n";
		}
		else {
			cout << "The flea cannot escape from black squares.\n";
		}

	}

}