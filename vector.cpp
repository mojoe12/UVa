#include <iostream>
#include <cmath>
#include <vector>

class Vector {
public:
	Vector();
	Vector (double xi, double yi, double zi, bool ifrect);
	inline double getX ();
	inline double getY ();
	inline double getZ ();
	std::vector<double> getArray ();
	Vector nullVector ();

	const Vector& operator= (const Vector& vec2);
	const Vector& operator+ (const Vector& vec2);
	const Vector& operator- ();
	const Vector& operator- (const Vector& vec2);
	const Vector& operator* (double multiplier);
	const Vector& operator/ (double divisor);

	inline double DotProduct (const Vector& vec);
	inline double sumComponents ();
	Vector sqrComponents ();
	double sumSqrComponents ();
	double magnitude ();
	Vector unitVector ();
private:
	double x;
	double y;
	double z;
};

const Vector& operator* (double multiplier, const Vector& vec);

Vector::Vector ():
x(0),
y(0),
z(0) {
	;
}
// mag then p then phi
Vector::Vector (double xi, double yi, double zi, bool ifrect = true):
x( (ifrect) ? xi : xi * cos(yi) * sin(zi)),
y( (ifrect) ? yi : xi * sin(yi) * sin(zi)),
z( (ifrect) ? zi : xi * cos(zi)) {
	;
}

inline double Vector::getX () {
	return x;
}
inline double Vector::getY () {
	return y;
}
inline double Vector::getZ () {
	return z;
}
std::vector<double> Vector::getArray () {
	std::vector<double> v = {x, y, z};
	return v;
}
Vector Vector::nullVector () {
	Vector nullvec = Vector();
	return nullvec;
}



const Vector& Vector::operator= (const Vector& vec2) {
	x = vec2.x;
	y = vec2.y;
	z = vec2.z;
	return *this;
}
const Vector& Vector::operator+ (const Vector& vec2) {
	Vector newvec (x + vec2.x, y + vec2.y, z + vec2.z);
	return newvec;
}
const Vector& Vector::operator- () {
	Vector newvec (-x, -y, -z);
	return newvec;
}
const Vector& Vector::operator- (const Vector& vec2) {
	return *this + (-vec2);
}
const Vector& Vector::operator* (double multiplier) {
	Vector newvec (x * multiplier, y * multiplier, z * multiplier);
	return newvec;
}
const Vector& operator* (double multiplier, const Vector& vec) {
	return vec * multiplier;
}
const Vector& Vector::operator/ (double divisor) {
	return *this * (1/divisor);
}



inline double Vector::DotProduct (const Vector& vec) {
	return x * vec.x + y * vec.y + z * vec.z;
}
inline double Vector::sumComponents () {
	return x + y + z;
}
Vector Vector::sqrComponents () {
	Vector newvec = Vector (x*x, y*y, z*z);
	return newvec;
}
double Vector::sumSqrComponents () {
	return sqrComponents().sumComponents();
}
double Vector::magnitude () {
	return sqrt(sumSqrComponents());
}
Vector Vector::unitVector () {
	return *this / magnitude();
}
