#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

void decompose(const string& s, int& si, int nc, string& answer, int starti, int endi, int startj, int endj) {
	//cout << starti << ' ' << endi << ' ' << startj << ' ' << endj << endl;
	if (starti == endi || startj == endj) return;
	if (s[si] == 'D') {
		si++;
		int midi = (endi - starti + 1) / 2 + starti;
		int midj = (endj - startj + 1) / 2 + startj;
		decompose(s, si, nc, answer, starti, midi, startj, midj);
		decompose(s, si, nc, answer, starti, midi, midj, endj);
		decompose(s, si, nc, answer, midi, endi, startj, midj);
		decompose(s, si, nc, answer, midi, endi, midj, endj);
	}
	else {
		for (int i = starti; i < endi; i++) {
			string::iterator it = answer.begin() + i * nc;
			fill(it + startj, it + endj, s[si]);
		}
		si++;
	}
}

void compose (string& s, int nc, const string& answer, int starti, int endi, int startj, int endj) {
	//cout << starti << ' ' << endi << ' ' << startj << ' ' << endj << endl;
	if (starti == endi || startj == endj) return;
	char valtomatch = answer[starti * nc + startj];
	bool allsame = true;
	for (int i = starti; allsame && i < endi; i++) {
		for (int j = startj; allsame && j < endj; j++) {
			if (answer[i * nc + j] != valtomatch) allsame = false;
		}
	}
	
	if (allsame) s.push_back(valtomatch);
	else {
		s.push_back('D');
		int midi = (endi - starti + 1) / 2 + starti;
		int midj = (endj - startj + 1) / 2 + startj;
		compose(s, nc, answer, starti, midi, startj, midj);
		compose(s, nc, answer, starti, midi, midj, endj);
		compose(s, nc, answer, midi, endi, startj, midj);
		compose(s, nc, answer, midi, endi, midj, endj);
	}
}

void input (string& s, string& extra) {
	string newline;
	while (true) {
		getline(cin, newline);
		bool done = newline.size() == 1 && newline[0] == '#';
		done = done || (newline.size() > 1 && newline[1] == ' ');
		if (done) {
			extra = newline;
			break;
		}
		s += newline;
	}
}

void parse (string& inputs, char& c, int& nr, int& nc) {
	int index = 0;
	c = inputs[index++];
	while (inputs[index] == ' ') index++;
	while (inputs[index] != ' ') {
		nr = 10 * nr + (inputs[index++] - '0');
	}
	while (inputs[index] == ' ') index++;
	while (index < inputs.length() && inputs[index] != ' ') {
		nc = 10 * nc + (inputs[index++] - '0');
	}
}

void print(char c, int nr, int nc, string s) {
	cout << c;
	cout.width(4);
	cout << right << nr;
	cout.width(4);
	cout << right << nc;
	cout << endl;
	for (int i = 0; i < s.length(); i += 50) 
		cout << s.substr(i, 50) << endl;
}

int main() {
	
	string inputs;
	getline(cin, inputs);
	while (true) {
		char c;
		int nr = 0, nc = 0;
		if (inputs[0] == '#') break;
		parse(inputs, c, nr, nc);
		if (c == 'D') {
			string s = "", answer (nr * nc, 'X'); // maybe
			input(s, inputs);
			int si = 0;
			decompose(s, si, nc, answer, 0, nr, 0, nc);
			print('B', nr, nc, answer);
		}
		else {
			string s = "", answer;
			input(answer, inputs);
			compose(s, nc, answer, 0, nr, 0, nc);
			print('D', nr, nc, s);
		}
	}




}


