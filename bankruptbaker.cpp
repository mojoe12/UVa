#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string toUpper (string s) {
	string news;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c - 'a' >= 0 && c - 'a' < 26) c -= 32;
		news += c;
	}
	return news;
}

bool comp (pair<string, int> i, pair<string, int> j) {
	if (i.second == j.second) return i.first < j.first;
	return i.second < j.second;
}


int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {

		string binder;
		getline(cin, binder);
		getline(cin, binder);
		int a, b, budget;
		cin >> a >> b >> budget;
		map<string, int> ingreds;
		for (int i = 0; i < a; i++) {
			string ingred;
			int cost;
			cin >> ingred >> cost;
			ingreds.insert( make_pair(ingred, cost) );
		}
		map<string, int> recipes;
		for (int i = 0; i < b; i++) {
			string recipe;
			getline(cin, recipe);
			getline(cin, recipe);
			int ningreds;
			cin >> ningreds;
			long long totalcost = 0;
			for (int j = 0; j < ningreds; j++) {
				string ingred;
				int numneeded;
				cin >> ingred >> numneeded;
				totalcost += numneeded * ingreds[ingred];
			}
			recipes.insert( make_pair(recipe, totalcost) );
		}
		
		vector< pair<string, int> > recipesv;
		for (map<string, int>::iterator it = recipes.begin(); it != recipes.end(); it++) {
			recipesv.push_back(*it);
		}
		
		cout << toUpper(binder) << endl;
		
		sort(recipesv.begin(), recipesv.end(), comp);
		
		for (int i = 0; i < recipesv.size(); i++) {
			if (recipesv[i].second <= budget) cout << recipesv[i].first << endl;
			else {
				if (i == 0) cout << "Too expensive!\n";
				break;
			}
		}
		cout << endl;
	}
}