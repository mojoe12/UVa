#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class car {
	public:	
		int number, position;
		car () {}
		car (int n, int p) {
			number = n;
			position = p;
		}
};

bool comp(car a, car b) {
	return a.position < b.position;
}
bool ifpossible (vector<car> cars) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].position != i) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<car> cars (n);
		for (int i = 0; i < n; i++) {
			int num, gain;
			cin >> num >> gain;
			cars[i] = car (num, i + gain);
		}
		sort(cars.begin(), cars.end(), comp);
		if (ifpossible(cars)) {
			for (int i = 0; i < n-1; i++) {
				cout << cars[i].number << ' ';
			}
			cout << cars[n-1].number << endl;
		}
		else cout << "-1\n";
	}
}