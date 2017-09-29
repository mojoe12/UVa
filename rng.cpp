#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i < 10000; i++) {
		cout << (rand() % 2) << endl;
	}
	return 0;
}