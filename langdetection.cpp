#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	for (int i = 1;; i++) {
		string s;
		cin >> s;
		if (s == "#") break;
		string lang = "UNKNOWN";
		if (s == "HELLO") lang = "ENGLISH";
		else if (s == "HOLA") lang = "SPANISH";
		else if (s == "HALLO") lang = "GERMAN";
		else if (s == "CIAO") lang = "ITALIAN";
		else if (s == "BONJOUR") lang = "FRENCH";
		else if (s == "ZDRAVSTVUJTE") lang = "RUSSIAN";
		cout << "Case " << i << ": " << lang << endl;
	}
}