#include <iostream>
#include <list>

using namespace std;

int main() {
	
	string input;
	while (cin >> input) {
		
		list<char> output;
		list<char>::iterator it = output.begin();
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '[') it = output.begin();
			else if (input[i] == ']') it = output.end();
			else output.insert(it, input[i]);
		}
		
		for (it = output.begin(); it != output.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
}