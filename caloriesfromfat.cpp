#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	const int calories_per_g[5] = {9, 4, 4, 4, 7};

	while (true) {
    	string s;
		getline(cin, s);
		if (s[0] == '-') break;
		double fat = 0.0, total = 0.0, calories[5];
		while (true) {
			istringstream iss(s);
			double p = 100.0, c = 0.0;
			for (int i = 0; i < 5; i++) {
				int q;
				char u;
				iss >> q >> u;
				switch (u) {
					case 'g':
						calories[i] = q * calories_per_g[i];
						c += calories[i];
						break;
					case 'C':
						calories[i] = q;
						c += q;
						break;
					case '%':
						calories[i] = -q;
						p -= q;
						break;
				}
			}
			double t = 0.0;
			if (p < 100.0) { // some are represented by %
				t = 100.0 * c / p; // total calories
				for (int i = 0; i < 5; i++) {
					if (calories[i] < 0.0) calories[i] = t * (-calories[i]) / 100.0;
				}
			}
      		else {
				for (int i = 0; i < 5; i++) {
					t += calories[i];
				}
			}
			fat += calories[0];
			total += t;
			getline(cin, s);
			if (s[0] == '-') break;
		}
    	cout << fixed << setprecision(0) << fat * 100.0 / total << "%\n";
	}
}
