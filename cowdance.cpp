#include <iostream>
#include <queue>
#include <fstream>
/*
ID: josephh2
PROG: cowdance
LANG: C++11
*/


using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin ("cowdance.in"); ofstream fout ("cowdance.out");
	
	int n, tmax;
	fin >> n >> tmax;
	vector<int> durs (n);
	for (int j = 0; j < n; j++) fin >> durs[j];
	
	int ansk = n;
	for (int k = 1; ansk == n && k < n; k++) {
		int time = 0;
		int i = 0;
		priority_queue<int, vector<int>, greater<int> > stage;
		for (; i < k; i++) {
			stage.push(durs[i]);
		}
		
		while (stage.size() && time <= tmax) {
			time = stage.top();
			//cout << time << endl;
			stage.pop();
			if (i < n) stage.push(time + durs[i]);
			i++;
		}
		if (time <= tmax) ansk = k;
	}
	fout << ansk << endl;
}