#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int i = 1;; i++) {
		string s;
		cin >> s;
		if (s == "*") break;
		else {
			string diff = (s == "Hajj") ? "kb" : "sgh";
			cout << "Case " << i << ": Hajj-e-A" << diff << "ar" << endl;
		}
	}
}