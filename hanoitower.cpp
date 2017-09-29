#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

void place(vector< stack<int> >& balls, int& b, int& maxx) {
	int n = balls.size();
	
	//for (int i = 0; i < n; i++) cout << balls[i].size() << ' '; cout << endl;
	
	for (int i = 0; i < n; i++) {
		if (!balls[i].size()) {
			balls[i].push(b++);
			maxx = max(maxx, b);
			place(balls, b, maxx);
		}
		else {
			int x = sqrt(b + balls[i].top());
			if (x * x == b + balls[i].top()) {
				maxx = max(maxx, b);
				balls[i].push(b++);
				place(balls, b, maxx);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	vector<int> answers (k);
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector< stack<int> > balls (n);
		int b = 1, max = 1;
		place(balls, b, max);
		answers[c] = (n == 1) ? 1 : max;
	}
	for (int c = 0; c < k; c++) cout << answers[c] << endl;
}
