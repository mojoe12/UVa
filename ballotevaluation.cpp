#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	map<string, int> votes;
	for (int i = 0; i < a; i++) {
		string party;
		double nvotes;
		cin >> party >> nvotes;
		int nvotesi = (int) (10 * nvotes);
		votes.insert( make_pair(party, nvotesi) );
	}
	string bet;
	getline(cin, bet);
	for (int c = 1; c <= b; c++) {
		getline(cin, bet);
		
		string word = "";
		int totalcount = 0;
		string comparison;

		for (int i = 0; i < bet.length(); i++) {
			if (bet[i] == ' ') {
				if (word == "<" || word == ">" || word == "<=" || word == ">=" || word == "=") {
					comparison = word;
				}
				else if (word != "+") totalcount += votes[word];
				word = "";
			}
			else word += bet[i];
		}
		int check = 10 * stoi(word);
		bool ifcorrect = true;

		if (comparison == "<") ifcorrect = totalcount < check;
		else if (comparison == ">") ifcorrect = totalcount > check;
		else if (comparison == "<=") ifcorrect = totalcount <= check;
		else if (comparison == ">=") ifcorrect = totalcount >= check;
		else if (comparison == "=") ifcorrect = totalcount == check;

		cout << "Guess #" << c << " was ";
		if (!ifcorrect) cout << "in";
		cout << "correct." << endl;
	}
}