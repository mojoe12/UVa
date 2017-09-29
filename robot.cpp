#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int k; 
	cin >> k;
	for (int j = 0; j < k; j++) {
		int n;
		cin >> n;
		int moves[n];
		int pos = 0;
		for (int i = 0; i < n; i++) {
			string move;
			cin >> move;
			if (move == "RIGHT") {
				pos++;
				moves[i] = 1;
			}
			else if (move == "LEFT") {
				pos--;
				moves[i] = -1;
			}
			else if (move == "SAME") {
				string s;
				cin >> s;
				int x;
				cin >> x;
				pos += moves[x-1];
				moves[i] = moves[x-1];
			}
		}
		cout << pos << endl;
	} 
}