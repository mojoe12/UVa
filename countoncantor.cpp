#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	while (cin >> n) {
		int sumab = 0;
		for (int i = 3; ; i++) {
			if ( (i-1) * (i-2) / 2 > n - 1) {
				sumab = i-1;
				break;
			}
		}
		int a = n - (sumab-1) * (sumab-2) / 2;
		int b = sumab - a;
		if (sumab % 2 == 0) swap(a, b);
		cout << "TERM " << n << " IS " << a << '/' << b << endl;
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