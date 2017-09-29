#include <iostream>
#include <vector>
using namespace std;

vector<int> blank () {
	vector<int> dante (0);
	return dante;
}

int findcol(vector< vector<int> > blox, int a) {
	for (int i = 0; i < blox.size(); i++) {
		for (int j = 0; j < blox[i].size(); j++) {
			if (blox[i][j] == a) return i;
		}
	}
	return 0;
} 

int findrow(vector< vector<int> > blox, int a) {
	for (int i = 0; i < blox.size(); i++) {
		for (int j = 0; j < blox[i].size(); j++) {
			if (blox[i][j] == a) return j;
		}
	}
	return 0;
} 

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector< vector<int> > blox (n, vector<int> (1));
	for (int i = 0; i < n; i++) blox[i][0] = i; 
	string command;
	cin >> command;
	while (command != "quit") {
		string oo;
		int a, b;
		cin >> a >> oo >> b;
		int acol = findcol(blox, a), bcol = findcol(blox, b);
		int arow = findrow(blox, a), brow = findrow(blox, b);
		if (acol == bcol || a == b) {
			cin >> command;
			continue;
		};
		if (command == "pile" && oo == "over") {
			for (int i = arow; i < blox[acol].size(); i++) {
				blox[bcol].push_back(blox[acol][i]);
			}
			for (int i = blox[acol].size()-1; i >= arow; i--) {
				blox[acol].pop_back();
			}
		}
		else if (command == "pile" && oo == "onto") {
			for (int i = blox[bcol].size()-1; i > brow; i--) {
				int num = blox[bcol][i];
				blox[num].push_back(num);
				blox[bcol].pop_back();
			}
			for (int i = arow; i < blox[acol].size(); i++) {
				blox[bcol].push_back(blox[acol][i]);
			}
			for (int i = blox[acol].size()-1; i >= arow; i--) {
				blox[acol].pop_back();
			}
		}
		else if (command == "move" && oo == "over") {
			for (int i = blox[acol].size()-1; i > arow; i--) {
				int num = blox[acol][i];
				blox[num].push_back(num);
				blox[acol].pop_back();
			}
			blox[bcol].push_back(a);
			blox[acol].pop_back();
		}
		else if (command == "move" && oo == "onto") {
			for (int i = blox[bcol].size()-1; i > brow; i--) {
				int num = blox[bcol][i];
				blox[num].push_back(num);
				blox[bcol].pop_back();
			}
			for (int i = blox[acol].size()-1; i > arow; i--) {
				int num = blox[acol][i];
				blox[num].push_back(num);

				blox[acol].pop_back();
			}
			blox[bcol].push_back(a);
			blox[acol].pop_back();
		}
		cin >> command;
	}
	for (int i = 0; i < n; i++) {
		cout << i << ':';
		for (int j = 0; j < blox[i].size(); j++) cout << ' ' << blox[i][j];
		cout << endl;
	}
}