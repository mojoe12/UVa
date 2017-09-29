#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;



int main() {
	
	string s;
	
	vector<string> lookup, names;
	vector<int> costs;
	while (cin >> s) {
		if (s == "000000") break;
		cin.ignore();
		string newname;
		getline(cin, newname, '$');
		int cost;
		cin >> cost;
		if (s[1] == '0' && (s.size() < 3 || s.size() > 5)) continue;
		if (s[1] != '0' && (s.size() < 2 || s.size() > 6)) continue;
		lookup.push_back(s);
		names.push_back(newname);
		costs.push_back(cost);
	}
	
	while (cin >> s) {
		if (s == "#") break;
		
		int duration;
		cin >> duration;
		
		int answer = -1;
		if (s[0] == '0') {
			for (int i = 1; i < s.length(); i++) {
				string ss = s.substr(0, i);
				for (int j = 0; j < lookup.size(); j++) {
					if (lookup[j] == ss) answer = j;
				}
			}
		}
		
		cout.width(16);
		cout << left << s;
		
		if ((answer > -1 && names[answer].size()) || s[0] != '0') {
			
			int cost = (answer > -1) ? costs[answer] : 0;
			string name = (answer > -1) ? names[answer] : "Local";
			string othernum = (answer > -1) ? s.substr(lookup[answer].size()) : s;
			
			cout << name;
			cout.width(35 - name.length());
			cout << right << othernum;
			cout.width(5);
			cout << right << duration;
			cout.width(6);
			cout << right << fixed << setprecision(2) << (cost / 100.0);
			cout.width(7);
			cout << right << fixed << setprecision(2) << (cost * duration / 100.0);
		}
		else {
			cout.width(35);
			cout << left << "Unknown";
			cout.width(5);
			cout << right << duration;
			cout << "        -1.00";
		}
		cout << endl;
		
	}




}


