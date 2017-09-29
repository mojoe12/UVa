#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class entry {
	public:
		string book, author;
		entry () {
			book = "";
			author = "";
		}
		entry (string b, string a) {
			book = b;
			author = a;
		}
};

bool comp (entry a, entry b) {
	if (a.author < b.author) return true;
	return a.author == b.author && a.book < b.book;
}

string getauthor (vector<entry> library, string book) {
	for (int i = 0; i < library.size(); i++) {
		if (book == library[i].book) return library[i].author;
	}
	return "";
}

int borrow (vector<entry> library, string book) {
	int i = 0;
	for (; i < library.size(); i++) {
		if (library[i].book == book) break;
	}
	return i;
}

int ret (vector<entry> library, entry newbook) {
	string previous = "first";
	int i = 0;
	for (; i < library.size(); i++) {
		if (comp(newbook, library[i])) {
			cout << "Put " << newbook.book << ' ';
			if (i > 0) cout << "after ";
			cout << previous << endl;
			return i;
		}
		previous = library[i].book;
	}
	cout << "Put " << newbook.book << ' ';
	if (i > 0) cout << "after ";
	cout << previous << endl;
	return i;
}

int main(int argc, char *argv[]) {
	vector<entry> permlibrary (0);
	while (true) {
		string input, book = "\"", author = "";
		getline(cin, input);
		if (input == "END") break;
		int index = 0;
		do {
			index++;
			book += input[index];
		} while (input[index] != '"');
		for (index += 5; index < input.length(); index++) {
			author += input[index];
		}
		entry newbook (book, author);
		permlibrary.push_back(newbook);
	}
	sort(permlibrary.begin(), permlibrary.end(), comp);
	vector<entry> toreturn (0);
	string action, book;
	vector<entry> library = permlibrary;
	while (cin >> action) {
		if (action == "END") break;
		else if (action == "SHELVE") {			
			sort(toreturn.begin(), toreturn.end(), comp);
			for (int x = 0; x < toreturn.size(); x++) {
				int i = ret(library, toreturn[x]);
				library.insert(library.begin() + i, toreturn[x]);
			}
			toreturn = vector<entry> (0);
			cout << "END\n";
		}
		else {
			char c; cin >> c;
			getline(cin, book);
			book = '"' + book;
			entry newbook (book, getauthor(permlibrary, book));
			if (action == "BORROW") {
				int i = borrow (library, book);
				if (i < library.size()) library.erase(library.begin() + i);
			}
			else if (action == "RETURN") {
				toreturn.push_back(newbook);
			}
		}
	}
}