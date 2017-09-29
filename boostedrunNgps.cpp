#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

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
		Polygon(long double, Coordinate);
		Polygon(vector<Coordinate>);
		void rotate (long double angle);
		long double difference(Polygon);
		long double getheading();
		Vector box();
		Polygon bestpoly (long double);
};

long double angleMode(long double, bool);
long double shopAngle(long double);

long double averageHeading (vector<Coordinate>&);
long double methodHeading (vector<Coordinate>&, long double = .00001182);

void run4gps (vector<Coordinate>&, long double = .00001182, string = "", string = "", int = 0);
bool getInput (vector<Coordinate>&);

int main(int argc, char *argv[]) {
	
	/*
	generally understood convention is
	argc = 11 -- always check for this
	(0,1) =
	(2,3) = 
	8 = 
	9 = 
	10 =
	
	*/
	
	// check argc
	
	const long double distanceRadius = .00001182;
	int n = 4;
	
	/*vector<Coordinate> points (4);
	for (int i = 1; i < 8; i += 2) {
		double x = stod((string)argv[i]), y = stod((string)argv[i+1]);
		if (x 
		Coordinate point (x, y);
		points[i/4] = point);
	}*/
	vector<Coordinate> points (4);
	while (getInput(points)) {
		run4gps(points, distanceRadius);
	}
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
	return angleMode(angRadians, true);
}
void Vector::rotate (long double angle) {
	angle = angleMode(angle, false);
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
Polygon::Polygon (long double distanceRadius, Coordinate centeri) {
	center = centeri;
	positions = vector<Coordinate> (4);
	const long double fullcircle = 360;
	Vector curr (Coordinate (center.X, center.Y + distanceRadius), center); // top
	positions[0] = curr.head;
	for (int i = 1; i < 4; i++) {
		curr.rotate(fullcircle / n);
		positions[i] = curr.head;
	}
}
Polygon::Polygon (vector<Coordinate> points) {
	center = points[0];
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
	long double farleft = 90, fartop = -90, farright = -90, farbot = 90; // this is ridiculous 
	for (int i = 0; i < n; i++) {
		farleft = min(positions[i].X, farleft);
		farright = max(positions[i].X, farright);
		farbot = min(positions[i].Y, farbot);
		fartop = max(positions[i].Y, fartop);
	}
	
	long double xdist = farright - farleft;
	farleft += xdist / 4.0; 		// push closer to average
	farright -= xdist / 4.0;
	
	long double ydist = fartop - farbot;
	farbot += ydist / 4.0;
	fartop -= ydist / 4.0;
	
	Coordinate head (farright, fartop); // just for storing in a vector
	Coordinate tail (farleft, farbot);
	return Vector(head, tail);
}
Polygon Polygon::bestpoly(long double distanceRadius) {
	Polygon bestsim = *this;
	Polygon currsim = *this;
	long double minerror = 10000;
	const long double fullcircle = 360, accdeg = .5, acccen = 0.0000001;
	Vector boxx = box();
	for (long double x = boxx.tail.X; x < boxx.head.X; x += acccen) {
		for (long double y = boxx.tail.Y; y < boxx.head.Y; y += acccen) {
			Coordinate center (x, y);
		 	currsim = Polygon(distanceRadius, center);
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

long double angleMode(long double angle, bool iftodeg) {
	const long double multiplier = 180 / 3.141592653;
	if (iftodeg) return angle * multiplier;
	else return angle / multiplier;
}

long double shopAngle (long double angle) {
									   // angle is from positive x axis
	long double heading = 90 - angle; // standard heading convention
	if (heading < 0) heading += 360;  // essentially absolute value
	return heading;
}

void run4gps (vector<Coordinate>& points, long double distanceRadius, string filename, string time, int prec) {
	if (filename.length()) {
		ofstream fout (filename, std::ios::app); // appends
		fout << fixed << setprecision(prec);
		fout << time << '\t';
		fout << averageHeading(points) << '\t';
		fout << methodHeading(points) << endl;
	}
	else {
		cout << fixed << setprecision(prec);
		cout << time << '\t';
		cout << averageHeading(points) << '\t';
		cout << methodHeading(points) << endl;
	}
}

long double averageHeading (vector<Coordinate>& points) {
	Vector vert (points[2], points[0]); 		 // vertical means bow and stern
	Vector hori (points[3], points[1]); 		 // port and starboard
	long double hhead = hori.getheading() - 90; // to average them
	long double angle = (vert.getheading() + hhead) / 2; 
	long double heading = shopAngle(angle);
	return heading;
}

long double methodHeading (vector<Coordinate>& points, long double distanceRadius) {
	// can use following method for dR if necessary
	Vector vert (points[2], points[0]); 		 // vertical means bow and stern
	Vector hori (points[3], points[1]); 		 // port and starboard
	distanceRadius = (sqrt(vert.distance()) + sqrt(hori.distance())) / 4;
	
	Polygon newpoly (points);
	Polygon bestpol = newpoly.bestpoly(distanceRadius);
	long double angle = bestpol.getheading();
	long double heading = shopAngle(angle);
	return heading;
}

bool getInput(vector<Coordinate>& points) {
	for (int i = 0; i < points.size(); i++) {
		if (!(cin >> points[i].X >> points[i].Y)) return false;
	}
	return true;
}