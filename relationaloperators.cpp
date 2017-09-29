#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) cout << '>' << endl;
		else if (a < b) cout << '<' << endl;
		else cout << '=' << endl;
	}
}a