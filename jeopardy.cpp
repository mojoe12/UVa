#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "") break;
		cout << s << endl;
	}
}