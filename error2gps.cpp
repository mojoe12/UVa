#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;

struct Coordinate {
	double X, Y;
};

Coordinate getCoord (double x, double y) {
	Coordinate Coord;
	Coord.X = x;
	Coord.Y = y;
	return Coord;
}

Coordinate move (Coordinate Coord, double deltax, double deltay) {
	return getCoord(Coord.X + deltax, Coord.Y + deltay);
}

double difference (double ang1, double ang2) {
	const double fullcircle = 360;
	if (ang1 < 0) ang1 += fullcircle;
	if (ang2 < 0) ang2 += fullcircle;
	return ang2 - ang1;
}

double getheading(Coordinate front, Coordinate back) {
	double linex = front.X - back.X, liney = front.Y - back.Y;
	double angRadians = atan2(liney, linex);
	const double multiplier = 180 / 3.141592653;
	return angRadians * multiplier;
}

/*double truncated_gaussian (default_random_engine generator, double mean, double std) {
	normal_distribution<double> dist (mean, std);
	double val = dist(generator);
	if (abs(mean - val) < std) return val;
	return truncated_gaussian (generator, mean, std);
}*/

int main(int argc, char *argv[]) {
	const double distanceRadius = 1.5; // distance between GPSes
	const double errorRadius = 1; // error radius
	Coordinate truefront = getCoord (-distanceRadius, 0 );
	Coordinate trueback = getCoord (distanceRadius, 0 );

	double trueHeading = getheading(truefront, trueback);

	const double numExperiments = 10000;
	
	default_random_engine gen;
	uniform_real_distribution<double> dist(-errorRadius, errorRadius);
	
	double sumoferror = 0;
	double sumofbias = 0;
	for (int count = 0; count < numExperiments; count++) {
		Coordinate gpsfront = move(truefront, dist(gen), dist(gen));
		Coordinate gpsback = move(trueback, dist(gen), dist(gen));

		double gpsHeading = getheading(gpsfront, gpsback);

		double diff = difference(trueHeading, gpsHeading);
		sumoferror += diff * diff;
		sumofbias += diff;
	}
	double error = sqrt(sumoferror / numExperiments);
	double bias = sumofbias / numExperiments;
	cout << error << " " << bias << endl;
}