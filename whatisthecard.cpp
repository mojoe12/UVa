#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	string cardss;
	for (int c = 1; c <= k; c++) {
		vector<string> cards (52);
		for (int i = 51; i >= 0; i--) cin >> cards[i];
		int y = 0, index = 25;
		for (int i = 0; i < 3; i++) {
			int x = (cards[index][0] - '0' > 9) ? 10 : (cards[index][0] - '0');
			y += x;
			index += 11 - x;
		}
		y = 52 - y;
		if (y < index) y -= index - 25;
		cout << "Case " << c << ": " << cards[y] << endl;
	}
}