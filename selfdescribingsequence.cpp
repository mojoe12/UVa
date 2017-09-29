#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

long long f (vector< pair<int, long long> >& fvec, int x) {
	long long sum = 0;
	for (int i = 0; i < fvec.size(); i++) {
		sum += fvec[i].second;
		if (fvec[i].first == x-1) break;
	}
	return sum;
}


int main() {

	// i have to have a vector of f(n) and how many of those it has
	vector< pair<int, long long> > fvec;
	fvec.reserve(70000);
	
	long long sum = 1;
	int x = 1;
	while (x <= 70000) {
		cout << sum << endl;
		fvec.push_back( make_pair(x, f(fvec, x)));
		x++;
		sum += f(fvec, x);
	}

	for (int i = 0; i < fvec.size(); i++) cout << fvec[i].first << ' ' << fvec[i].second << endl;
	
	int n;
	while (cin >> n) {
		if (!n) break;
		int sum = 0;
		for (int i = 0; i < fvec.size(); i++) {
			cout << f(fvec, n) << endl;
		}
	}
	

}


