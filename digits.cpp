#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		string s;
		getline(cin, s);
		if (s == "END") break;
		else if (s == "0") {
			cout << 2 << endl;
			continue;
		}
		else if (s == "1") {
			cout << 1 << endl;
			continue;
		}
		int num = s.length();
		int newnum = -1;
		int i = 1;
		for (; newnum != num; i++) {
			newnum = num;
			num = 1 + floor(log10(num));
		}
		cout << i << endl;
	}
} // bad algo but works :(
// its cause by starting with the length of the string i avoid a really big starting number and then i start with i = 1
// really, i should incorporate this into the loop but not worth