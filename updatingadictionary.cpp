#include <iostream>
#include <map>
#include <vector>

using namespace std;

void collect(map<string, string>& dict, string s) {
	string key = "", value = "";
	bool add2key = true;
	for (int i = 1; i < s.length(); i++) {
		char c = s[i];
		if (c == ':') {
			add2key = false;
		}
		else if (c == ',' || c == '}') {
			if (key.size() && value.size())
				dict.insert( make_pair(key, value) );
			key = "";
			value = "";
			add2key = true;
		}
		else if (add2key) {
			key += c;
		}
		else {
			value += c;
		}
	}
}



int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string line1, line2;
	getline(cin, line1);
	
	typedef map<string, string>::iterator it_type;
	
	for (int c = 0; c < k; c++) {

		getline(cin, line1);
		map<string, string> dict1;
		collect(dict1, line1);
		
		getline(cin, line2);
		map<string, string> dict2;
		collect(dict2, line2);
		
		
		vector<string> adds;
		vector<string> minuses;
		vector<string> changes;
		
		for (it_type it = dict2.begin(); it != dict2.end(); it++) {
			string key = it->first, value = it->second;
			if (!dict1.count(key)) adds.push_back(key);
			else if (dict1[key] != value) changes.push_back(key);
		}
		for (it_type it = dict1.begin(); it != dict1.end(); it++) {
			string key = it->first;
			if (!dict2.count(key)) minuses.push_back(key);
		}

		if (adds.size() + minuses.size() + changes.size() == 0) 
			cout << "No changes\n";
		if (adds.size()) {
			cout << '+';
			for (int i = 0; i < adds.size(); i++) {
				if (i) cout << ',';
				cout << adds[i];
			}
			cout << endl;
		}
		if (minuses.size()) {
			cout << '-';
			for (int i = 0; i < minuses.size(); i++) {
				if (i) cout << ',';
				cout << minuses[i];
			}
			cout << endl;
		}
		if (changes.size()) {
			cout << '*';
			for (int i = 0; i < changes.size(); i++) {
				if (i) cout << ',';
				cout << changes[i];
			}
			cout << endl;
		}
		
		cout << endl;
	}
}