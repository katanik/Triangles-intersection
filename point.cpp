#include "ads.h"
#include <cmath>

namespace TrianglesIntersection
{

	Point::Point(double x, double y, double z) : x(x), y(y), z(z)
	{
	}
	
	Point::Point(const Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Point::~Point()
	{
	}

	Point Point::move_to(const Vector& v) const
	{
		return static_cast<Point>(Vector(*this) + v);
	}

	double dist(const Point& p1, const Point& p2)
	{
		return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
	}

}
