#include <iostream>
#include <vector>
using namespace std;
class Saxophone {
public:
	Saxophone();
	void getFingers(char note);
	void playNote();
	void printCounter();
private:
	vector<bool> fingers;
	vector<bool> ifactive;
	vector<int> counters;
};
Saxophone::Saxophone() {
	fingers = vector<bool> (10);
	ifactive = vector<bool> (10);
	counters = vector<int> (10);
}
void Saxophone::getFingers(char note) {
	fingers[0] = note == 'D' || note == 'E' || note == 'F' || note == 'G' || note == 'A' || note == 'B';
	fingers[1] = note != 'C';
	fingers[2] = note != 'B' && note != 'b';
	fingers[3] = note != 'a' && note != 'b' && note != 'C' && note != 'A' && note != 'B';
	fingers[4] = 0;
	fingers[5] = 0;
	fingers[6] = note == 'c' || note == 'd' || note == 'e' || note == 'f' || note == 'D' || note == 'E' || note == 'F';
	fingers[7] = note == 'c' || note == 'd' || note == 'e' || note == 'D' || note == 'E';
	fingers[8] = note == 'c' || note == 'd' || note == 'D';
	fingers[9] = note == 'c';
}
void Saxophone::playNote() {
	for (int i = 0; i < 10; i++) {
		if (fingers[i] && !ifactive[i]) counters[i]++;
		ifactive[i] = fingers[i];
	}
}
void Saxophone::printCounter() {
	for (int i = 0; i < 9; i++) {
		cout << counters[i] << ' ';
	}
	cout << counters[9] << endl;
}
int main() {
	int k;
	cin >> k;
	string blank;
	getline(cin, blank);
	for (int c = 0; c < k; c++) {
		Saxophone sax = Saxophone();
		string song;
		getline(cin, song);
		for (int i = 0; i < song.length(); i++) {
			sax.getFingers(song[i]);
			sax.playNote();
		}
		sax.printCounter();
	}
}