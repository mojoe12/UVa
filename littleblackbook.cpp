#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void parse (vector<string>& toFill, string toParse, char parseBy, int startIndex = 0) 
{
	int index = startIndex;
	string currentstring = "";
	int len = toParse.length();
	for (int i = 0; i <= len; i++) {
		if (i == len || toParse[i] == parseBy) {
			if (index < toFill.size()) {
				toFill[index++] = currentstring;
			}
			else {
				toFill.push_back(currentstring);
				index++;
			}
			currentstring = "";
		}
		else currentstring += toParse[i];
	}
}

bool comp (vector<string> i, vector<string> j) {
	return i[3] < j[3];
}


int main(int argc, char *argv[]) 
{
	int k;
	cin >> k;
	string s;
	getline(cin, s);
	
	vector< vector<string> > allinfo;
	for (int c = 0; c < k; c++) {
		string dept;
		getline(cin, dept);
		getline(cin, s);
		while (s != "") {
			vector<string> info (8);
			info[0] = dept;
			parse(info, s, ',', 1);
			allinfo.push_back(info);
			getline(cin, s);
		}
	}
	
	sort(allinfo.begin(), allinfo.end(), comp);
	
	for (int i = 0; i < allinfo.size(); i++) {
		cout << "----------------------------------------\n";
		cout << allinfo[i][1] << ' ' << allinfo[i][2] << ' ';
		cout << allinfo[i][3] << endl << allinfo[i][4] << endl;
		cout << "Department: " << allinfo[i][0] << endl;
		cout << "Home Phone: " << allinfo[i][5] << endl;
		cout << "Work Phone: " << allinfo[i][6] << endl;
		cout << "Campus Box: " << allinfo[i][7] << endl;
	}

}