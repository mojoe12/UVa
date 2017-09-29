#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		
		vector<int> a (n);
		for (int i = 0; i < n; ++i) 
		{
			cin >> a[i];
		}
		vector<int> b (n);
		for (int i = 0; i < n; ++i) 
		{
			cin >> b[i];
		}
		
		int numot = 0;
		for (int i = 0; i < n; ++i)
		{
			
			int pos = 0;
			for (int j = 0; j < n; ++j)
			{
				if (a[j] == b[i]) 
				{
					pos = j;
				}
			} //just get the position
			
			for (int j = pos; j > i; --j)
			{
				swap(a[j], a[j - 1]);
			}
			
			numot += max(0, pos - i);
		}
		
		cout << numot << endl;

	}
}