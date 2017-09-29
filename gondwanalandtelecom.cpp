#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;



int main() {


	string step;
	while (cin >> step) {
		if (step == "#") break;
		
		string number;
		int sh, sm, eh, em;
		cin >> number >> sh >> sm >> eh >> em;
		
		
		int d = 0, e = 0, n = 0;
		// calls that go into the next day?
		
		int reh = -1, rem = -1;
		if (eh < sh || (eh == sh && em <= sm)) {
			reh = eh;
			rem = em;
			eh = 24;
			em = 0;
		}
		
		while (true) {
			
			if (sh >= 8 && eh < 18) d += (eh - sh) * 60 + em - sm;
			if (sh >= 8 && eh >= 18 && sh < 18) d += (18 - sh) * 60 - sm;
			if (sh < 8 && eh >= 18) d += (18 - 8) * 60;
			if (sh < 8 && eh < 18 && eh >= 8) d += (eh - 8) * 60 + em;
			
			if (sh >= 18 && eh < 22) e += (eh - sh) * 60 + em - sm;
			if (sh >= 18 && eh >= 22 && sh < 22) e += (22 - sh) * 60 - sm;
			if (sh < 18 && eh >= 22) e += (22 - 18) * 60;
			if (sh < 18 && eh < 22 && eh >= 18) e += (eh - 18) * 60 + em;
			
			if (sh >= 22 && eh < 24) n += (eh - sh) * 60 + em - sm;
			if (sh >= 22 && eh >= 24) n += (24 - sh) * 60 - sm;
			if (sh < 22 && eh >= 24) n += (24 - 22) * 60;
			if (sh < 22 && eh < 24 && eh >= 22) n += (eh - 22) * 60 + em;
			
			if (sh >= 0 && eh < 8) n += (eh - sh) * 60 + em - sm;
			if (sh >= 0 && eh >= 8 && sh < 8) n += (8 - sh) * 60 - sm;
			if (sh < 0 && eh >= 8) n += (8 - 0) * 60;
			if (sh < 0 && eh < 8 && eh >= 0) n += (eh - 0) * 60 + em;
			
			if (reh > -1) {
				eh = reh;
				em = rem;
				sh = 0;
				sm = 0;
				reh = -1;
				rem = -1;
			}
			else break;
		}
		
		
		int sum = 0;
		if (step == "A") sum = 10 * d + 6 * e + 2 * n;
		else if (step == "B") sum = 25 * d + 15 * e + 5 * n;
		else if (step == "C") sum = 53 * d + 33 * e + 13 * n;
		else if (step == "D") sum = 87 * d + 47 * e + 17 * n;
		else if (step == "E") sum = 144 * d + 80 * e + 30 * n;

		double cost = sum / 100.0;
		
		cout.width(10);
		cout << right << number;
		cout.width(6);
		cout << right << d;
		cout.width(6);
		cout << right << e;
		cout.width(6);
		cout << right << n;
		cout.width(3);
		cout << right << step;
		cout.width(8);
		cout << right << fixed << setprecision(2) << cost << endl;
		
	}	




}


