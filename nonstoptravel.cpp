#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct light {
	double location;
	int green;
	int yellow;
	int red;
};

bool ifgreen(light lt, int mph) {
	double time = (3600 * lt.location) / mph;
	int sum = lt.green + lt.yellow + lt.red;
	double mod = time - sum * floor(time / sum);
	bool retval = mod <= lt.green + lt.yellow;
	return retval;
}

void print(bool& ifspace, int jumpsize, int prevspeed) {
	if (ifspace) cout << ' ';
	else ifspace = true;
	if (jumpsize == 1) cout << prevspeed;
	else cout << prevspeed << '-' << prevspeed + jumpsize-1;
}

int main(int argc, char *argv[]) {
	int n;
	for (int c = 1; cin >> n; c++) {
		if (n == -1) break;
		
		vector<light> lights (n); 
		for (int i = 0; i < n; i++) {
			cin >> lights[i].location >> lights[i].green;
			cin >> lights[i].yellow >> lights[i].red;
		}
		
		vector<int> okspeeds;
		for (int mph = 30; mph <= 60; mph++) {
			bool ifok = true;
			for (int i = 0; ifok && i < n; i++) {
				ifok = ifgreen(lights[i], mph);
			}
			if (ifok) okspeeds.push_back(mph);
		}
		
		cout << "Case " << c << ": ";

		if (!okspeeds.size()) {
			cout << "No acceptable speeds.\n";
			continue;
		}
		
		bool ifspace = false;
		int prevspeed = 0, jumpsize = 1;
		for (int i = 0; i < okspeeds.size(); i++) {
			if (okspeeds[i] == prevspeed + jumpsize) {
				jumpsize++;
			}
			else {
				if (prevspeed) {
					print(ifspace, jumpsize, prevspeed);
					cout << ',';
				}
				prevspeed = okspeeds[i];
				jumpsize = 1;
			}
		}
		print(ifspace, jumpsize, prevspeed);
		cout << endl;
	}
}