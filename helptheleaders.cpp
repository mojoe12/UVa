#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

// function declarations
void makespeech(vector<string>& topics, map<string, vector<string> >& badpairs, int s, vector<string>& speech, int index);
bool comp(string i, string j);
void toUpper(string& s);

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int t, p, s;
		cin >> t >> p >> s;
		vector<string> topics (t);
		map<string, vector<string> > badpairs;
		for (int i = 0; i < t; i++) {
			string s;
			cin >> s;
			toUpper(s);
			topics[i] = s;
			badpairs.insert( make_pair(s, vector<string>() ));
		}
		
		sort(topics.begin(), topics.end(), comp);
		
		for (int i = 0; i < p; i++) {
			string x, y;
			cin >> x >> y;
			toUpper(x);
			toUpper(y);
			badpairs[x].push_back(y);
			badpairs[y].push_back(x);
		}
		
		cout << "Set " << c+1 << ":\n";
		
		vector<string> speech;
		makespeech(topics, badpairs, s, speech, 0);
		
		
		cout << endl;
	}
}

// function definitions

void makespeech(vector<string>& topics, map<string, vector<string> >& badpairs, int s, vector<string>& speech, int index) {
	
	if (speech.size() == s) {
		for (int i = 0; i < s-1; i++) cout << speech[i] << ' ';
		cout << speech[s-1] << endl;
		return;
	}
	
	if (index >= topics.size()) return;
	
	bool ifok = true;
	for (int j = 0; ifok && j < speech.size(); j++) {
		vector<string>::iterator it = find(badpairs[speech[j]].begin(), badpairs[speech[j]].end(), topics[index]);
		if (it != badpairs[speech[j]].end()) ifok = false;
		//cout << topics[index] << ' ' << speech[j] << ' ' << ifok << endl;
	}
	if (ifok) {
		speech.push_back(topics[index]);
		makespeech(topics, badpairs, s, speech, index+1);
		speech.pop_back();
	}
	
	makespeech(topics, badpairs, s, speech, index+1);
}


bool comp(string i, string j) {
	if (i.length() != j.length()) return i.length() > j.length();
	return i < j;
}


void toUpper(string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
	}
}