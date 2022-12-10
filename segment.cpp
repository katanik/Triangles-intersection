#include "ads.h"
#include <cmath>
#include <algorithm>

namespace TrianglesIntersection
{

	Segment::Segment(const Point& p1, const Point& p2) : p_begin(p1), p_end(p2)
	{
	}

	Segment::~Segment()
	{
	}

	bool Segment::is_degenerate() const
	{
		return length() < EPSILON;
	}

	double Segment::length() const
	{
		return dist(p_begin, p_end);
	}

	Point Segment::get_begin() const
	{
		return p_begin;
	}

	Point Segment::get_end() const
	{
		return p_end;
	}

	Point Segment::get_inside_point(double ratio) const
	{
		return static_cast<Point>((Vector(p_begin)*ratio) + (Vector(p_end)*(1. - ratio)));

	}

	bool Segment::is_inside(const Point& p) const
	{
		return dist(p, p_begin) + dist(p, p_end) - length() < EPSILON;
	}

	bool Segment::is_intersection(const Segment& s) const
	{
		if (s.length() < EPSILON)
			return is_inside(s.p_begin);
		if (length() < EPSILON)
			return s.is_inside(p_begin);

		Vector v1(*this);
		Vector v2(s);
		Vector v3(s.p_begin, p_begin);

		if ((v1^v2).length() < EPSILON)
			return ((v3^v1).length() < EPSILON &&
			std::max(std::max(dist(p_begin, s.p_begin), dist(p_begin, s.p_end)),
			std::max(dist(p_end, s.p_begin), dist(p_end, s.p_end))) <= s.length() + length() + EPSILON);

		double ratio = (v3 ^ v1).length() / (v2^v1).length();

		Point p_intersection1 = s.get_begin().move_to(v2*ratio);
		Point p_intersection2 = s.get_begin().move_to(v2*(-ratio));

		return is_inside(p_intersection1) && s.is_inside(p_intersection1)
			|| is_inside(p_intersection2) && s.is_inside(p_intersection2);
	}
}
