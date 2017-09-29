#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

long double change(long double angle, bool iftodeg);
void runNgps (int n, long double distanceRadius);
class Coordinate {
	public:
		long double X, Y;
		Coordinate();
		Coordinate (long double, long double);
		void move (long double, long double);
};
class Vector {
	public:
		Coordinate head, tail;
		Vector (Coordinate, Coordinate);
		long double vecAngle ();
		long double distance ();
		long double getheading ();
		void rotate (long double);
};
class Polygon {
	public:
		int n;
		Coordinate center;
		vector<Coordinate> positions;
		Polygon(int, Coordinate);
		Polygon(long double, Coordinate, int);
		Polygon(vector<Coordinate>);
		void rotate (long double angle);
		long double difference(Polygon);
		long double getheading();
		Vector box();
		Polygon bestpoly (long double);
};

int main(int argc, char *argv[]) {
	// 
	long double distanceRadius = .00001182, errorRadius = 2.5;
	int n = 4;
	runNgps(n, distanceRadius);
}

Coordinate::Coordinate() {
	X = 0;
	Y = 0;
}
Coordinate::Coordinate(long double x, long double y) {
	X = x;
	Y = y;
}
void Coordinate::move (long double deltax, long double deltay) {
	X += deltax;
	Y += deltay;
}

Vector::Vector (Coordinate headi, Coordinate taili) {
	head = headi;
	tail = taili;
}
long double Vector::vecAngle () {
	return atan2(head.Y - tail.Y, head.X - tail.X);
}
long double Vector::distance () {
	long double dist = (head.X - tail.X) * (head.X - tail.X);
	dist += (head.Y - tail.Y) * (head.Y - tail.Y);
	return dist;
}
long double Vector::getheading() {
	long double angRadians = vecAngle();
	const long double fullcircle = 2 * 3.1415926;
	if (angRadians < 0) angRadians += fullcircle;
	return change(angRadians, true);
}
void Vector::rotate (long double angle) {
	angle = change(angle, false);
	Coordinate rot = head;
	rot.move(-tail.X, -tail.Y);
 	long double newx = rot.X * cos(angle) - rot.Y * sin(angle);
	long double newy = rot.X * sin(angle) + rot.Y * cos(angle);
	head = Coordinate (newx, newy);
	head.move (tail.X, tail.Y);
}

Polygon::Polygon (int input, Coordinate centeri) {
	positions = vector<Coordinate> (input);
	n = input;
	center = centeri;
}
Polygon::Polygon (long double distanceRadius, Coordinate centeri, int ni) {
	center = centeri;
	n = ni;
	positions = vector<Coordinate> (ni);
	const long double fullcircle = 360;
	Vector curr (Coordinate (center.X, center.Y + distanceRadius), center); // top
	positions[0] = curr.head;
	for (int i = 1; i < n; i++) {
		curr.rotate(fullcircle / n);
		positions[i] = curr.head;
		//cout << curr.head.Y << endl;
	}
}
Polygon::Polygon (vector<Coordinate> points) {
	center = points[0]; // irrelevant, never called
	n = points.size();
	positions = points;
}
void Polygon::rotate (long double angle) {
	vector <Coordinate> newpos (n);
	for (int i = 0; i < n; i++) {
		Vector vec (positions[i], center);
		vec.rotate(angle);
		newpos[i] = vec.head;
	}
	positions = newpos;
}
long double Polygon::difference (Polygon s2) {
	long double diff = 0;
	for (int i = 0; i < n; i++) {
		Vector vec (positions[i], s2.positions[i]);
		diff += vec.distance();
	}
	return diff;
}
long double Polygon::getheading() {
	Vector north = Vector(positions[0], center);
	return north.getheading();
}
Vector Polygon::box () {
	long double farleft = 1000, fartop = -1000, farright = -1000, farbot = 1000;
	for (int i = 0; i < n; i++) {
		if (positions[i].X < farleft) farleft = positions[i].X;
		if (positions[i].X > farright) farright = positions[i].X;
		if (positions[i].Y < farbot) farbot = positions[i].Y;
		if (positions[i].Y > fartop) fartop = positions[i].Y;
	}
	long double xdist = farright - farleft, ydist = fartop - farbot;
	farleft += xdist / 4.0;
	farright -= xdist / 4.0;
	farbot += ydist / 4.0;
	fartop -= ydist / 4.0;
	Coordinate head (farright, fartop);
	Coordinate tail (farleft, farbot);
	return Vector(head, tail);
}
Polygon Polygon::bestpoly(long double distanceRadius) {
	Polygon bestsim = *this;
	Polygon currsim = *this;
	long double minerror = 10000;
	const long double fullcircle = 360, accdeg = .5, acccen = 0.0001;
	Vector boxx = box();
	for (long double x = boxx.tail.X; x < boxx.head.X; x += acccen) {
		for (long double y = boxx.tail.Y; y < boxx.head.Y; y += acccen) {
			Coordinate center (x, y);
		 	currsim = Polygon(distanceRadius, center, n);
			//currsim.rotate (-fullcircle / (2*n));
			for (int i = 0; i < fullcircle / (accdeg); i++) {
				//cout << difference(currsim) << endl;
				if (difference(currsim) < minerror) {
					minerror = difference(currsim);
					bestsim = currsim;
				}
				currsim.rotate(accdeg);
			}
		}
	}
	return bestsim;
}

long double change(long double angle, bool iftodeg) {
	const long double multiplier = 180 / 3.141592653;
	if (iftodeg) return angle * multiplier;
	else return angle / multiplier;
}

void runNgps (int n, long double distanceRadius) {
	const int numcoords = 289;
	ofstream fout ("headings.txt");
	ifstream fin("postprocess2.txt");

	long double x, y, sumdist = 0;
	string time;
	
	//long double sumsq = 0, sumsq1 = 0, sum = 0, sum1 = 0;
	for (int i = 0; i < numcoords; i++) {
		vector<Coordinate> points (n);
		fin >> x >> y;
		Coordinate tpoint (x, y);
		points[0] = tpoint;

		fin >> x >> y;
		Coordinate lpoint (x, y);
		points[1] = lpoint;
		
		fin >> x >> y;
		Coordinate bpoint (x, y);
		points[2] = bpoint;
		
		fin >> x >> y;
		Coordinate rpoint (x, y);
		points[3] = rpoint;
		
		Vector vert (points[2], points[0]);
		Vector hori (points[3], points[1]);
		
		distanceRadius = (sqrt(vert.distance()) + sqrt(hori.distance())) / 4;
		Polygon newpoly (points);
		Polygon bestpol = newpoly.bestpoly(distanceRadius);
		
		long double heading1 = (vert.getheading() + hori.getheading() - 90) / 2;
		heading1 = 90 - heading1; // changes by convention
		if (heading1 < 0) heading1 += 360;
		
		long double heading = bestpol.getheading();
		heading = 90 - heading; 
		if (heading < 0) heading += 360;
		
		fin >> time;
		//fout << heading1 << '\t' << 
		fout << time << '\t' << heading << endl;
		
		/* if were running below, watch out for 360 - 0 jump
		sum += heading;
		sumsq += heading * heading;
		sum1 += heading1;
		sumsq1 += heading1 * heading1;
		*/
	}
	/*
	cout << sqrt((sumsq / numcoords) - (sum * sum / (numcoords * numcoords))) << " ";
	cout << sqrt((sumsq1 / numcoords) - ((sum1 * sum1) / (numcoords * numcoords))) << endl;
	cout << sumdist / (4 * numcoords);
	*/
}
