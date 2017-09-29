#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>


using namespace std;

int chord (int a, int b, int c) {
	if ((c - b == 3 || c - b == -9) && (b - a == 4 || b - a == -8)) return 2; // major
	if ((c - b == 4 || c - b == -8) && (b - a == 3 || b - a == -9)) return 1;
	return 0;
}

string edit (string a) {
	if (a[0] >= 'a' && a[0] <= 'z') a[0] -= 32;
	if (a == "Bb") return "A#";
	if (a == "Cb") return "B";
	if (a == "B#") return "C";
	if (a == "Db") return "C#";
	if (a == "Eb") return "D#";
	if (a == "Fb") return "E";
	if (a == "E#") return "F";
	if (a == "Gb") return "F#";
	if (a == "Ab") return "G#";
	return a;
} 

int main() {
	
	
	map<string, int> notes;
	notes.insert(make_pair("A", 0));
	notes.insert(make_pair("A#", 1));
	notes.insert(make_pair("Bb", 1));
	notes.insert(make_pair("B", 2));
	notes.insert(make_pair("Cb", 2));
	notes.insert(make_pair("B#", 3));
	notes.insert(make_pair("C", 3));
	notes.insert(make_pair("C#", 4));
	notes.insert(make_pair("Db", 4));
	notes.insert(make_pair("D", 5));
	notes.insert(make_pair("D#", 6));
	notes.insert(make_pair("Eb", 6));
	notes.insert(make_pair("E", 7));
	notes.insert(make_pair("Fb", 7));
	notes.insert(make_pair("E#", 8));
	notes.insert(make_pair("F", 8));
	notes.insert(make_pair("F#", 9));
	notes.insert(make_pair("Gb", 9));
	notes.insert(make_pair("G", 10));
	notes.insert(make_pair("G#", 11));
	notes.insert(make_pair("Ab", 11));



	string a, b, c;
	while (cin >> a >> b >> c) {
		string oa = a, ob = b, oc = c;

		a = edit(a);
		b = edit(b);
		c = edit(c);
		int an = notes[a], bn = notes[b], cn = notes[c];
		
		
		int ch = chord(an, bn, cn), fnl = -1;
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << a;
			if (fnl < 0) fnl = ch;
		}
		ch = chord(an, cn, bn);
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << a;
			if (fnl < 0) fnl = ch;
		}
		ch = chord(bn, an, cn);
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << b;
			if (fnl < 0) fnl = ch;
		}
		ch = chord(bn, cn, an);
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << b;
			if (fnl < 0) fnl = ch;
		}
		ch = chord(cn, an, bn);
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << c;
			if (fnl < 0) fnl = ch;
		}
		ch = chord(cn, bn, an);
		if (ch) {
			cout << oa << ' ' << ob << ' ' << oc << " is a " << c;
			if (fnl < 0) fnl = ch;
		}
		
		if (fnl < 0) cout << oa << ' ' << ob << ' ' << oc << " is unrecognized.\n";
		else if (fnl == 1) cout << " Minor chord.\n";
		else cout << " Major chord.\n";
	}

}


