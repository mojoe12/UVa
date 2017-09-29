#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

struct block {
	block() :
	x(0), y(0), z(0) {}
	block(int X, int Y, int Z) :
	x(X), y(Y), z(Z) {}
	int x;
	int y;
	int z;
};

struct LISelement {
	LISelement() :
	value(block(0,0,0)), len(0) {}
	block value;
	int len;
}



int main() {
	
	int n;
	while (cin >> n) {
		if (!n) break;
		
		vector<LISelement> arr (n);
		for (int i = 0; i < n; i++) {
			cin >> arr.value.x >> arr.value.y >> arr.value.z;
		}
		
		for (int i = 0; i < n; i++) {
			int maxlen = 0;
			
		}
		
		
	}




}


