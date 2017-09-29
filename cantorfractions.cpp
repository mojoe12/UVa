#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	long long n;
	while (cin >> n) {
		long long sumab = 0;
		long long start = sqrt(n * 2) - 1;
		if (start < 3) start = 3;
		for (long long i = start; ; i++) {
			if ( (i-1) * (i-2) / 2 > n - 1) {
				sumab = i-1;
				break;
			}
		}
		long long b = n - (sumab-1) * (sumab-2) / 2;
		long long a = sumab - b;
		cout << a << '/' << b << endl;
	}
}
/*


	// loop through it, apply function


	// output answer


}

// function definitions

1 -> (1,1)
2 -> (1,2)
3 -> (2,1)
6 -> (3,1)
5 -> (2,2)


.5 * (a+b-1) * (a+b-2) + a = row

= .5(a+b)^2 - 3/2(a+b) + 1 + a = row
sqrt(row*2)*/