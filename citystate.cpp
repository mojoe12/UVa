#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
/*
ID: josephh2
PROG: citystate
LANG: C++11
*/
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin ("citystate.in"); ofstream fout ("citystate.out");
	
	int n;
	fin >> n;
	
	multimap<string, string> cityToState;
	multimap<string, string> stateToCity;
	
	int numpairs = 0;
	for (int i = 0; i < n; i++) {
		string city, state;
		fin >> city >> state;
		
		string city2 = "";
		city2 += city[0];
		city2 += city[1];
		city = city2;
		
		for (auto j = stateToCity.find(city2); (*j).first == city; j++) {
			string newcity = (*(stateToCity.find(city2))).second; // check every city
			if (newcity == state) {
				/*if ((*cityToState.find(newcity)).second != state)*/ numpairs++;
			}
		}
		
		// check if the city reveals a state
		// if it does, run that city in the state and get the city
		
		cityToState.insert(pair<string, string> (city, state));
		stateToCity.insert(pair<string, string> (state, city));
	}
	fout << numpairs << endl;
	
}