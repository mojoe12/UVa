#include <iostream>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string slogan;
	getline(cin, slogan);
	map<string, string> slogans;
	for (int i = 0; i < n; i++) {
		getline(cin, slogan);
		string first = slogan;
		getline(cin, slogan);
		string second = slogan;
		slogans.insert( make_pair(first, second));
	}
	int q;
	cin >> q;
	getline(cin, slogan);
	for (int i = 0; i < q; i++) {
		getline(cin, slogan);
		cout << slogans[slogan] << endl;
	}
}