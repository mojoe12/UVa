#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool getsteps(int a, int b, int ca, int cb, int n, vector< vector<bool> >& states, vector<int>& steps);
string getstring(int a);

int main() {
	
	int ca, cb, n;
	while (cin >> ca >> cb >> n) {
		int a = 0, b = 0;
		vector<int> steps;
		vector< vector<bool> > states (ca+1, vector<bool> (cb+1, false));
		getsteps(a, b, ca, cb, n, states, steps);
		
		for (int i = 0; i < steps.size(); i++) {
			cout << getstring(steps[i]) << endl;
		}
		cout << "success\n";
		
	}

}

bool getsteps(int a, int b, int ca, int cb, int n, vector<vector<bool> >& states, vector<int>& steps) {
	
	if (states[a][b]) return false;
	else states[a][b] = true;
	if (a == n || b == n) return true;
	
	if (a != ca) {
		steps.push_back(0);
		if (getsteps(ca, b, ca, cb, n, states, steps)) return true;
		steps.pop_back();
	}
	if (b != cb) { // fill b
		steps.push_back(1);
		if (getsteps(a, cb, ca, cb, n, states, steps)) return true;
		steps.pop_back();
	}
	
	if (a != 0) { // empty a
		steps.push_back(2);
		if (getsteps(0, b, ca, cb, n, states, steps)) return true ;
		steps.pop_back();
	}
	if (b != 0) {
		steps.push_back(3);
		if (getsteps(a, 0, ca, cb, n, states, steps)) return true;
		steps.pop_back();
	} // empty b
	
	if (a != 0 && b != cb) {
		steps.push_back(4);
		if (getsteps(max(0, a - (cb - b)), min(cb, b + a), ca, cb, n, states, steps)) return true;
		steps.pop_back();
	}// fill b with a
	if (b != 0 && a != ca) {
		steps.push_back(5);
		if (getsteps(min(ca, a + b), max(0, b - (ca - a)), ca, cb, n, states, steps)) return true;
		steps.pop_back();
	}// fill a with b
	return false;
}

string getstring(int a) {
	switch (a) {
		case 0: return "fill A";
		case 1: return "fill B";
		case 2: return "empty A";
		case 3: return "empty B";
		case 4: return "pour A B";
		case 5: return "pour B A";
	}
	return "";
}