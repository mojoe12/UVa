#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m == 1 && n == 1) break;
		
		pair<int, int> l (0, 1);
		pair<int, int> r (1, 0);
		
		string s = "";
		while (true) {
			pair<int, int> mid (l.first + r.first, l.second + r.second);
			//cout << mid.first << ' ' << mid.second << endl;
			if (m * mid.second == n * mid.first) break;
			else if (m * mid.second > n * mid.first) {
				s.push_back('R');
				l = mid;
			}
			else {
				s.push_back('L');
				r = mid;
			}
		}
		
		cout << s << endl;
		
		
	}
	




}


