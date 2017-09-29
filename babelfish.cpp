#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	string english, foreign;
	string s;
	
	map<string, string> mp;
	while (getline(cin, s)) {
		if (s == "") break;
		english = "";
		foreign = "";
		bool ifeng = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') ifeng = false;
			else if (ifeng) english += s[i];
			else foreign += s[i];
		}
		mp.insert( make_pair(foreign, english) );
	}
	while (cin >> s) {
		if (mp.count(s)) cout << (mp[s]) << endl;
		else cout << "eh\n";
	}
	return 0;
}