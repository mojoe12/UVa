#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <vector>

using namespace std;

double change(double angle, bool iftodeg);
void ngps (double distanceRadius, double errorRadius, int numExperiments, int n);
class Coordinate {
	public:
		double X, Y;
		Coordinate();
		Coordinate (double, double);
		void move (double, double);
};
class Vector {
	public:
		Coordinate head, tail;
		Vector (Coordinate, Coordinate);
		double vecAngle ();
		double distance ();
		double getheading ();
		void rotate (double);
};
class Polygon {
	public:
		int n;
		Coordinate center;
		vector<Coordinate> positions;
		Polygon(int, Coordinate);
		Polygon(double, Coordinate, int);
		void rotate (double angle);
		double difference(Polygon);
		double getheading();
		Vector box();
		Polygon bestpoly (double);
		Polygon shift(vector<double> shifts);
};

int main(int argc, char *argv[]) {
	double distanceRadius = .5, errorRadius = 1;
	int numExperiments = 100, n = 2;
	for (; n < 17; n++) {
		ngps(distanceRadius, errorRadius, numExperiments, n);
	}
}

Coordinate::Coordinate() {
	X = 0;
	Y = 0;
}
Coordinate::Coordinate(double x, double y) {
	X = x;
	Y = y;
}
void Coordinate::move (double deltax, double deltay) {
	X += deltax;
	Y += deltay;
}

Vector::Vector (Coordinate headi, Coordinate taili) {
	head = headi;
	tail = taili;
}
double Vector::vecAngle () {
	return atan2(head.Y - tail.Y, head.X - tail.X);
}
double Vector::distance () {
	double dist = (head.X - tail.X) * (head.X - tail.X);
	dist += (head.Y - tail.Y) * (head.Y - tail.Y);
	return dist;
}
double Vector::getheading() {
	double angRadians = vecAngle();
	const double fullcircle = 2 * 3.1415926;
	if (angRadians < 0) angRadians += fullcircle;
	return change(angRadians, true);
}
void Vector::rotate (double angle) {
	angle = change(angle, false);
	Coordinate rot = head;
	rot.move(-tail.X, -tail.Y);
 	double newx = rot.X * cos(angle) - rot.Y * sin(angle);
	double newy = rot.X * sin(angle) + rot.Y * cos(angle);
	head = Coordinate (newx, newy);
	head.move (tail.X, tail.Y);
}

Polygon::Polygon (int input, Coordinate centeri) {
	positions = vector<Coordinate> (input);
	n = input;
	center = centeri;
}
Polygon::Polygon (double distanceRadius, Coordinate centeri, int ni) {
	center = centeri;
	n = ni;
	positions = vector<Coordinate> (ni);
	const double fullcircle = 360;
	Vector curr (Coordinate (center.X, center.Y + distanceRadius), center); // top
	positions[0] = curr.head;
	for (int i = 1; i < n; i++) {
		curr.rotate(fullcircle / n);
		positions[i] = curr.head;
	}
}
Polygon Polygon::shift (vector<double> shifts) {
	Polygon poly (n, center);
	vector <Coordinate> newpos (n);
	for (int i = 0; i < n; i++) {
		poly.positions[i] = positions[i];
		poly.positions[i].move(shifts[2*i], shifts[2*i+1]);
	}
	return poly;
}
void Polygon::rotate (double angle) {
	vector <Coordinate> newpos (n);
	for (int i = 0; i < n; i++) {
		Vector vec (positions[i], center);
		vec.rotate(angle);
		newpos[i] = vec.head;
	}
	positions = newpos;
}
double Polygon::difference (Polygon s2) {
	double diff = 0;
	for (int i = 0; i < n; i++) {
		Vector vec (positions[i], s2.positions[i]);
		diff += vec.distance();
	}
	return diff;
}
double Polygon::getheading() {
	Vector north = Vector(positions[0], center);
	return north.getheading();
}
Vector Polygon::box () {
	double farleft = 0, fartop = 0, farright = 0, farbot = 0;
	for (int i = 0; i < n; i++) {
		if (positions[i].X < farleft) farleft = positions[i].X;
		if (positions[i].X > farright) farright = positions[i].X;
		if (positions[i].Y < farbot) farbot = positions[i].Y;
		if (positions[i].Y > fartop) fartop = positions[i].Y;
	}
	double xdist = farright - farleft, ydist = fartop - farbot;
	farleft += xdist / 4.0;
	farright -= xdist / 4.0;
	farbot += ydist / 4.0;
	fartop -= ydist / 4.0;
	Coordinate head (farright, fartop);
	Coordinate tail (farleft, farbot);
	return Vector(head, tail);
}
Polygon Polygon::bestpoly(double distanceRadius) {
	Polygon bestsim = *this;
	Polygon currsim = *this;
	double minerror = 10000;
	const double fullcircle = 360, accdeg = 0.5, acccen = 0.05;
	Vector boxx = box();
	for (double x = boxx.tail.X; x < boxx.head.X; x += acccen) {
		for (double y = boxx.tail.Y; y < boxx.head.Y; y += acccen) {
			Coordinate center (x, y);
		 	currsim = Polygon(distanceRadius, center, n);
			currsim.rotate (-fullcircle / (2*n));
			for (int i = 0; i < fullcircle / (accdeg * n); i++) {
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

double change(double angle, bool iftodeg) {
	const double multiplier = 180 / 3.141592653;
	if (iftodeg) return angle * multiplier;
	else return angle / multiplier;
}
void ngps (double distanceRadius, double errorRadius, int numExperiments, int n) {
	
	Polygon setup (distanceRadius, Coordinate (0,0), n);
	double trueHeading = setup.getheading();

	default_random_engine gen;
	uniform_real_distribution<double> dist(-errorRadius, errorRadius);
	
	double diffsqrd = 0, diff = 0;
	for (int count = 0; count < numExperiments; count++) {
		vector<double> shifts;
		for (int i = 0; i < 2*n; i++) shifts.push_back(dist(gen));
		Polygon GPS = setup.shift(shifts);
		double gpsHeading = (GPS.bestpoly(distanceRadius)).getheading();
		//cout << gpsHeading << endl;
		double difference = trueHeading - gpsHeading;
		diffsqrd += difference * difference;
		diff += difference;
	}
	double error = sqrt(diffsqrd / numExperiments);
	double bias = diff / numExperiments;
	double stdev = sqrt(sqrt(diffsqrd / numExperiments - bias * bias));
	cout << n << "\t" << error << "\t" << stdev << endl;
}