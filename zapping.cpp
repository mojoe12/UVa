#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 || b == -1) break;
		int dif = (b>a) ? (b-a) : (a-b); 
		int zap = (dif>50) ? (100 - dif) : (dif);
		cout << zap << endl;
	}
}