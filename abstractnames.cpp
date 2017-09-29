#include <iostream>

using namespace std;

bool isVowel (char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y': return true;
		default: return false;
	}
}


int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	for (int c = 0; c < n; c++) {
		string a, b;
		cin >> a >> b;
		bool ifsame = true;
		if (a.length() != b.length()) ifsame = false;
		for (int i = 0; ifsame && i < a.length(); i++) {
			if ( a[i] != b[i] && !isVowel(a[i]) ) ifsame = false; 
		}
		cout << (ifsame ? "Yes\n" : "No\n");
	}
}