#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinate {
	double X, Y;
	Coordinate() {};
	Coordinate (double x, double y) {
		X = x, Y = y;
	}
};

struct Vector {
	Coordinate head, tail;
	Vector () {};
	Vector (Coordinate headi, Coordinate taili) {
		head = headi, tail = taili;
	}
};

struct Square {
	Coordinate top, rig, bot, lef;
	Square () {};
	Square (Coordinate topi, Coordinate rigi, Coordinate boti, Coordinate lefi) {
		top = topi, rig = rigi, bot = boti, lef = lefi;
	}
};


Coordinate move (Coordinate Coord, double deltax, double deltay);
Vector createVec (double distanceRadius);
Square createSquare (double distanceRadius, Coordinate center);
double difference (Square s1, Square s2);
Vector shift (Vector setup, default_random_engine gen, uniform_real_distribution<double> dist);
Square shift (Square setup, vector<double> shifts);
Coordinate rotate (Vector vec, double angle);
Square rotate (Square setup, Coordinate center, double angle);
double vecAngle (Vector vec);
double distance (Vector vec);
double change(double angle, bool iftodeg);
double getheading(Vector setup);
double getheading1(Square setup);
double getheading2(Square setup);
double getheading3(Square setup);
void twogps(double distanceRadius, double errorRadius, int numExperiments);
void fourgps (double distanceRadius, double errorRadius, int numExperiments);

int main(int argc, char *argv[]) {
	double distanceRadius = .5, errorRadius = 1;
	int numExperiments = 1000;
	fourgps(distanceRadius, errorRadius, numExperiments);
	
}

Coordinate move (Coordinate Coord, double deltax, double deltay) {
	return Coordinate (Coord.X + deltax, Coord.Y + deltay);
}

Vector createVec (double distanceRadius) {
	Coordinate front = Coordinate (-distanceRadius, 0);
	Coordinate back = Coordinate (distanceRadius, 0);
	return Vector (front, back);
}

Square createSquare (double distanceRadius, Coordinate center) {
	Coordinate top = move(center, 0, distanceRadius);
	Coordinate rig = move(center, distanceRadius, 0);
	Coordinate bot = move(center, 0, -distanceRadius);
	Coordinate lef = move(center, -distanceRadius, 0);
	return Square(top, rig, bot, lef);
}

double difference (Square s1, Square s2) {
	double diff = 0;
	diff += distance(Vector (s1.rig, s2.rig));
	diff += distance(Vector (s1.lef, s2.lef));
	diff += distance(Vector (s1.bot, s2.bot));
	diff += distance(Vector (s1.top, s2.top));
	return diff;
}

Vector shift (Vector setup, vector<double> shifts) {
	Coordinate gpsfront = move(setup.head, shifts[0], shifts[1]);
	Coordinate gpsback = move(setup.tail, shifts[2], shifts[3]);
	return Vector(gpsfront, gpsback);
}

Square shift (Square setup, vector<double> shifts) {
	Coordinate gpstop = move(setup.top, shifts[0], shifts[1]);
	Coordinate gpsrig = move(setup.rig, shifts[2], shifts[3]);
	Coordinate gpsbot = move(setup.bot, shifts[4], shifts[5]);
	Coordinate gpslef = move(setup.lef, shifts[6], shifts[7]);
	return Square(gpstop, gpsrig, gpsbot, gpslef);
}

Coordinate rotate (Vector vec, double angle) {
	angle = change(angle, false);
	Coordinate rot = vec.head;
	rot = move(rot, -vec.tail.X, -vec.tail.Y);
 	double newx = rot.X * cos(angle) - rot.Y * sin(angle);
	double newy = rot.X * sin(angle) + rot.Y * cos(angle);
	rot = Coordinate (newx, newy);
	rot = move (rot, vec.tail.X, vec.tail.Y);
	return rot;
}

Square rotate (Square setup, Coordinate center, double angle) {
	Square turned;
	turned.rig = rotate(Vector (setup.rig, center), angle);
	turned.lef = rotate(Vector (setup.lef, center), angle);
	turned.bot = rotate(Vector (setup.bot, center), angle);
	turned.top = rotate(Vector (setup.top, center), angle);
	return turned;
}

Vector box (Square setup) {
	double farleft = 0, fartop = 0, farright = 0, farbot = 0;
	farleft = min(setup.lef.X, min(setup.top.X, min (setup.bot.X, setup.rig.X)));
	farright = max(setup.lef.X, max(setup.top.X, max (setup.bot.X, setup.rig.X)));
	farbot = min(setup.lef.Y, min(setup.top.Y, min (setup.bot.Y, setup.rig.Y)));
	fartop = max(setup.lef.Y, max(setup.top.Y, max (setup.bot.Y, setup.rig.Y)));
	double xdist = farright - farleft, ydist = fartop - farbot;
	farleft += xdist / 4.0;
	farright -= xdist / 4.0;
	farbot += ydist / 4.0;
	fartop -= ydist / 4.0;
	Coordinate head (farright, fartop);
	Coordinate tail (farleft, farbot);
	return Vector(head, tail);
}

double vecAngle (Vector vec) {
	return atan2(vec.head.Y - vec.tail.Y, vec.head.X - vec.tail.X);
}

double distance(Vector vec) {
	double dist = (vec.head.X - vec.tail.X) * (vec.head.X - vec.tail.X);
	dist += (vec.head.Y - vec.tail.Y) * (vec.head.Y - vec.tail.Y);
	return dist;
}

double change(double angle, bool iftodeg) {
	const double multiplier = 180 / 3.141592653;
	if (iftodeg) return angle * multiplier;
	else return angle / multiplier;
}

double getheading(Vector setup) {
	double angRadians = vecAngle(setup);
	const double fullcircle = 2 * 3.1415926;
	if (angRadians < 0) angRadians += fullcircle;
	return change(angRadians, true);
}

double getheading(Square setup) {
	// method 1
	Vector hori = Vector(setup.lef, setup.rig);
	Vector vert = Vector(setup.top, setup.bot);
	double sumheading = 0;
	sumheading += getheading(hori);
	sumheading += getheading(vert) + 90;
	return sumheading / 2.0;
}

double getheading1(Square setup) {
	// method 2
	Vector hori = Vector(setup.lef, setup.rig);
	Vector vert = Vector(setup.top, setup.bot);
	Vector NE = Vector(setup.top, setup.rig);
	Vector SE = Vector(setup.rig, setup.bot);
	Vector SW = Vector(setup.lef, setup.bot);
	Vector NW = Vector(setup.top, setup.lef);
	
	double sumheading = 0;
	sumheading += getheading(hori);
	sumheading += getheading(vert) + 90;
	sumheading += getheading(NE) + 45;
	sumheading += getheading(SE) + 135;
	sumheading += getheading(SW) + 45;
	sumheading += getheading(NW) + 135;

	return sumheading / 6.0;
}

Square bestsquare(Square setup, double distanceRadius) {
	Square bestsim = setup;
	Square currsim = bestsim;
	double minerror = 10000;
	const double fullcircle = 360, accdeg = 0.5, acccen = 0.05;
	Vector boxx = box(setup);
	for (double x = boxx.tail.X; x < boxx.head.X; x += acccen) {
		for (double y = boxx.tail.Y; y < boxx.head.Y; y += acccen) {
			Coordinate center (x, y);
		 	currsim = createSquare(distanceRadius, center);
			currsim = rotate (currsim, center, - fullcircle / 8);
			for (int i = 0; i < fullcircle / (accdeg * 4); i++) {
				if (difference(currsim, setup) < minerror) {
					minerror = difference(currsim, setup);
					bestsim = currsim;
				}
				currsim = rotate(currsim, center, accdeg);
			}
		}
	}
	return bestsim;
}

void twogps(double distanceRadius, double errorRadius, int numExperiments) { 

	Vector setup = createVec(distanceRadius);
	double trueHeading = getheading(setup);

	default_random_engine gen;
	uniform_real_distribution<double> dist(-errorRadius, errorRadius);

	double sumoferror = 0, sumofbias = 0;
	for (int count = 0; count < numExperiments; count++) {
		vector<double> shifts (4);
		for (int i = 0; i < 4; i++) shifts[i] = dist(gen);
		Vector GPS = shift(setup, shifts);
		double gpsHeading = getheading(GPS);
		double diff = trueHeading - gpsHeading;
		sumoferror += diff * diff;
		sumofbias += diff;
	}
	double error = sqrt(sumoferror / numExperiments);
	double bias = sumofbias / numExperiments;
	cout << error << " " << bias << endl;
}

void fourgps (double distanceRadius, double errorRadius, int numExperiments) {
	
	Square setup = createSquare(distanceRadius, Coordinate (0,0));
	double trueHeading = getheading1(setup);

	default_random_engine gen;
	uniform_real_distribution<double> dist(-errorRadius, errorRadius);
	
	double sumoferror = 0, sumofbias = 0;
	
	for (int count = 0; count < numExperiments; count++) {
		vector<double> shifts (8);
		for (int i = 0; i < 8; i++) shifts[i] = dist(gen);
		Square GPS = shift(setup, shifts);
		double gpsHeading = getheading(bestsquare(GPS, distanceRadius));

		double diff = trueHeading - gpsHeading;
		sumoferror += diff * diff;
		sumofbias += diff;
	}
	double error = sqrt(sumoferror / numExperiments);
	double bias = sumofbias / numExperiments;
	cout << error << " " << bias << endl;
}