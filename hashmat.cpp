#include <iostream>
#include <string>
using namespace std;
int reverse(int freak);
int main(int argc, char *argv[]) {
	cout << reverse(100);
}

int reverse(int freak) {
	string ed = to_string(freak);
	string egg = "";
	for (int i = 0; i < ed.length(); i++) {
		egg = ed[i] + egg;
	}
	return stoi(egg);
}