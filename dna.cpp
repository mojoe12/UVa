#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void getdna(string dna, int p, int index, int nchange, vector<string>& dnas);

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) 
	{
		int n, p;
		cin >> n >> p;
		string dna;
		cin >> dna;
		vector<string> dnas (0);
		getdna (dna, p, 0, 0, dnas);
		
		sort(dnas.begin(), dnas.end());
		int count = dnas.size();
		for (int i = 1; i < dnas.size(); i++) 
		{
			if (dnas[i-1] == dnas[i]) {
				dnas[i-1] = "";
				count--;
			}
		}
		cout << count << endl;
		for (int i = 0; i < dnas.size(); i++) 
		{
			if (dnas[i].length()) cout << dnas[i] << endl;
		}
	}
}

// function definitions

void getdna(string dna, int p, int index, int nchange, vector<string>& dnas) 
{
	if (nchange > p) return;
	else dnas.push_back(dna);
	
	if (index == dna.size()) return;
	
	char orig = dna[index];
	
	dna[index] = 'A';
	getdna(dna, p, index+1, nchange + (orig != 'A'), dnas);
	dna[index] = 'C';
	getdna(dna, p, index+1, nchange + (orig != 'C'), dnas);
	dna[index] = 'G';
	getdna(dna, p, index+1, nchange + (orig != 'G'), dnas);
	dna[index] = 'T';
	getdna(dna, p, index+1, nchange + (orig != 'T'), dnas);
	
}