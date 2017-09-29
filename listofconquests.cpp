#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	
	map<string, int> mapp;
	
	for (int c = 0; c < k; c++) {
		getline(cin, s);
				
		string country = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') break;
			country += s[i];
		}
				
		if (!mapp.count(country)) {
			mapp.insert(pair<string, int> (country, 1));
		}
		
		else {
			mapp[country]++;
		}
	}
	
	typedef map<string, int>::iterator it_type;
	for (it_type i = mapp.begin(); i != mapp.end(); i++) {
		string c = i -> first;
		int nbabes = i -> second;
		cout << c << ' ' << nbabes << endl;
	}
}