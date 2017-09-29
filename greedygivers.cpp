#include <iostream>	
#include <string>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	bool putline = false;
	string s;
	while (cin >> s) { // maybe
		if (s == "") break;
		int NP = stoi(s);
		vector<string> friends (NP);
		for (int i = 0; i < NP; i++) cin >> friends[i];
		vector<int> balances (NP);
		for (int i = 0; i < NP; i++) balances[i] = 0;
		for (int g = 0; g < NP; g++) {
			string GPName;
			cin >> GPName;
			int AmountGiven, PeopleGivingTo;
			cin >> AmountGiven >> PeopleGivingTo;
			int index = 0;
			for (int i = 0; i < NP; i++) if (GPName == friends[i]) index = i;
			if (PeopleGivingTo != 0) balances[index] += (AmountGiven % PeopleGivingTo) - AmountGiven;
			for (int nreceived = 0; nreceived != PeopleGivingTo; nreceived++) {
				string PersonReceiving;
				cin >> PersonReceiving;
				index = 0;
				for (int i = 0; i < NP; i++) if (PersonReceiving == friends[i]) index = i;
				if (PeopleGivingTo != 0) balances[index] += AmountGiven / PeopleGivingTo;
			}
		}
		if (putline) cout << endl;
		else putline = true;
		for (int i = 0; i < NP; i++) cout << friends[i] << " " << balances[i] << endl;
	}
}