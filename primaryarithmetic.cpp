#include <iostream>
#include <cmath>
using namespace std;
int main() {
	while (true) {
		string a, b;
		cin >> a >> b;
		if (a == "0" && b == "0") break;
		int alen = a.length(), blen = b.length();
		int minlen = min(alen, blen);
		bool iflastcarry = false;
		int numcarries = 0;
		int i = 1;
		for (; i <= minlen; i++) {
			int sumdigs = (a[alen - i] - '0') + (b[blen - i]- '0');
			bool ifcarry = sumdigs > 9 || (sumdigs > 8 && iflastcarry);
			if (ifcarry) {
				iflastcarry = true;
				numcarries++;
			}
			else iflastcarry = false;
			
		}
		int maxlen = max(alen, blen);
		if (maxlen > minlen) {
			while (alen == maxlen && a[alen-i] == '9' && iflastcarry == true) {
				numcarries++;
				i++;
			}
			while (blen == maxlen && b[blen-i] == '9' && iflastcarry == true) {
				numcarries++;
				i++;
			}
		}
		if (!numcarries) cout << "No carry operation.\n";
		else if (numcarries == 1) cout << "1 carry operation.\n";
		else cout << numcarries << " carry operations.\n";
	}
}