#include "ads.h"
#include <cmath>

namespace TrianglesIntersection
{

	Vector::Vector(double x, double y, double z) : x(x), y(y), z(z)
	{
	}

	Vector::Vector(const Point& p) : x(p.x), y(p.y), z(p.z)
	{
	}

	Vector::Vector(const Segment& s) : Vector(s.get_begin(), s.get_end())
	{
	}

	Vector::Vector(const Point& p_begin, const Point& p_end)
	{
		x = p_end.x - p_begin.x;
		y = p_end.y - p_begin.y;
		z = p_end.z - p_begin.z;
	}

	Vector::~Vector()
	{
	}

	double Vector::length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	Point Vector::get_point() const
	{
		return Point(x, y, z);
	}

	void Vector::operator+=(const Vector& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	void Vector::operator-=(const Vector& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	void Vector::operator*=(double c)
	{
		x *= c;
		y *= c;
		z *= c;
	}

	void Vector::operator/=(double c)
	{
		x /= c;
		y /= c;
		z /= c;
	}

	Vector Vector::operator*(double c)
	{
		Vector v(*this);
		v *= c;
		return v;
	}

	Vector Vector::operator/(double c)
	{
		Vector v(*this);
		v /= c;
		return v;
	}

	Vector operator^(const Vector& v1, const Vector& v2)
	{
		return Vector(v1.y*v2.z - v2.y*v1.z, -v1.x*v2.z + v2.x*v1.z, v1.x*v2.y - v2.x*v1.y);
	}

	double operator* (const Vector& v1, const Vector& v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}
	
	Vector operator+(const Vector& v1, const Vector& v2)
	{
		Vector v(v1);
		v += v2;
		return v;
	}

	Vector operator-(const Vector& v1, const Vector& v2)
	{
		Vector v(v1);
		v -= v2;
		return v;
	}

}
