#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int getage(string s, string t);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s, t;
	getline(cin,s);
	for (int c = 1; c <= k; c++) {
		for (getline(cin,s); s == ""; getline(cin,s)) ;
		getline(cin,t);
		int age = getage(s,t);
		cout << "Case #" << c << ": ";
		if (age < 0) cout << "Invalid birth date" << endl;
		else if (age > 130) cout << "Check birth date" << endl;
		else cout << age << endl;
		
	}
}

int getage(string s, string t) {
	vector<int> current (3);
	int i = 0;
	current[0] = 10 * (s[i++] - '0') + (s[i++] - '0'); i++;
	current[1] = 10 * (s[i++] - '0') + (s[i++] - '0'); i++;
	current[2] = 1000 * (s[i++] - '0') + 100 * (s[i++] - '0') + 10 * (s[i++] - '0') + (s[i++] - '0');
	vector<int> birth (3);
	i = 0;
	birth[0] = 10 * (t[i++] - '0') + (t[i++] - '0'); i++;
	birth[1] = 10 * (t[i++] - '0') + (t[i++] - '0'); i++;
	birth[2] = 1000 * (t[i++] - '0') + 100 * (t[i++] - '0') + 10 * (t[i++] - '0') + (t[i++] - '0');
	bool ifunborn = current[2] < birth[2] || (current[2] == birth[2] && current[1] < birth[1]) || (current[2] == birth[2] && current[1] == birth[1] && current[0] < birth[0]);
	if (ifunborn) return -1;
	bool ifhappened = current[1] > birth[1] || (current[1] == birth[1] && current[0] >= birth[0]);
	if (!ifhappened) birth[2]++;
	return current[2] - birth[2];
}
