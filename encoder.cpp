#include <iostream>
#include <string>

using namespace std;

string encode(string s);
string decode(string s);
char fromASCII(int i);
string reverse(string s);
string run(string s);


int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	cout << run(s) << endl;
	while (getline(cin, s)) {
		cout << run(s) << endl;
	}
}

string run(string s) {
	bool ifnum = (s[0] - '0' < 10 && s[0] - '0' > -1);
	if (ifnum) return decode(s);
	return encode(s);
}

string encode(string s) {
	string newstring = "";
	s = reverse(s);
	for (int i = 0; i < s.length(); i++) {
		int answer = (s[i] - ' ') + 32;
		string answers = to_string(answer);
		newstring = newstring + reverse(answers);
	}
	return newstring;
}

string decode(string s) {
	string newstring = "";
	for (int i = 0; i < s.length(); i += 2) {
		int num = s[i+1] - '0';
		int code = (s[i] - '0') + 10 * num;
		if (num > -1 && num < 3) {
			code += 100;
			i++;
		}
		newstring = newstring + fromASCII(code);
	}
	return reverse(newstring);
}

char fromASCII(int i) { //CHECK
	i -= 32;
	return (char) (' ' + i);
}

string reverse(string s) { //CHECK
	string news = s;
	for (int i = 0; i < s.length(); i++) {
		news[i] = s[s.length()-i-1];
	}
	return news;
}
