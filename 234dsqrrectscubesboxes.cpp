#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {
	
	int n;
	while (cin >> n) {
		
		t2 = ((n+1)^(2d) - no area ) / 2
		no area = ( (n+1)^(d+1) * d - just points) / 2^(d+1)
		just points = (n+1)^d
		
		(3^6- x) / 2
		x = 3^3 * 
		this is too hard
		
		
		long long t2 = 0, s2 = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				t2 += (n - x) * (n - y);
				s2 += (n - y);
			}
		}
		long long r2 = t2 - s2;
		cout << s2 << ' ' << r2 << ' ';
		
		long long t3 = 0, s3 = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				for (int z = 0; z < n; z++) {
					t3 += (n - x) * (n - y) * (n - z);
					s3 += n - max(max(x, y), z);
				}

			}
		}
		long long r3 = t3 - s3;
		cout << s3 << ' ' << r3 << ' ';
		
		long long t4 = 0, s4 = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				for (int z = 0; z < n; z++) {
					for (int w = 0; w < n; w++) {
						t4 += (n - x) * (n - y) * (n - z) * (n - w);
						s4 += n - max(max(x, y), max(z, w));
					}
				}
			}
		}
		long long r4 = t4 - s4;
		cout << s4 << ' ' << r4 << endl;
		
	}




}


