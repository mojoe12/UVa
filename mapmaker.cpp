#include <iostream>
#include <vector>
using namespace std;

class array {
	public: 
		string name;
		int baseaddress, nbytes, ndims;
		vector<int> lowers, uppers;
};


int main(int argc, char *argv[]) {
	int narrays, nrefs;
	cin >> narrays >> nrefs;
	vector<array> arrays (narrays);
	for (int c = 0; c < narrays; c++) {
		cin >> arrays[c].name >> arrays[c].baseaddress;
		cin >> arrays[c].nbytes >> arrays[c].ndims;
		vector<int> lows(arrays[c].ndims), upps(arrays[c].ndims);
		for (int i = 0; i < arrays[c].ndims; i++) {
			cin >> lows[i] >> upps[i];
		}
		arrays[c].lowers = lows;
		arrays[c].uppers = upps;
	}
	for (int c = 0; c < nrefs; c++) {
		string name;
		cin >> name;
		array chosen;
		for (int i = 0; i < narrays; i++) {
			if (name == arrays[i].name) chosen = arrays[i];
		}

		vector<int> cvals (chosen.ndims);
		cvals[chosen.ndims-1] = chosen.nbytes;
		for (int i = chosen.ndims-2; i >= 0; i--) {
			cvals[i] = cvals[i+1] * (chosen.uppers[i+1] - chosen.lowers[i+1] + 1);
		}
		int address = chosen.baseaddress;
		for (int i = 0; i < chosen.ndims; i++) {
			address -= cvals[i] * chosen.lowers[i];
		}
		
		cout << name << '[';
		int index;
		for (int i = 0; i < chosen.ndims-1; i++) {
			cin >> index;
			address += index * cvals[i];
			cout << index << ", ";
		}
		cin >> index;
		address += index * cvals[chosen.ndims-1];
		cout << index << "] = " << address << endl;
	}
}