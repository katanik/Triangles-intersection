#include "triangle.h"
#include <algorithm>

namespace TrianglesIntersection
{

	Triangle::Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3)
	{
	}

	Triangle::~Triangle()
	{
	}

	double Triangle::area() const
	{
		return (Vector(p1, p2) ^ Vector(p1, p3)).length()*0.5;
	}

	bool Triangle::is_degenerate() const
	{
		return area() < EPSILON;
	}

	bool Triangle::is_inside(const Point& p) const
	{
		Triangle t1{ p1, p2, p };
		Triangle t2{ p2, p3, p };
		Triangle t3{ p3, p1, p };
		return (t1.area() + t2.area() + t3.area()) - area() < EPSILON;
	}

	std::vector<Segment> Triangle::get_segments() const
	{
		std::vector <Point>  points{ p1, p2, p3, p1 };
		std::vector<Segment> segments;
		for (int i = 0; i < 3; ++i)
		{
			segments.push_back(Segment{ points[i], points[i + 1] });
		}
		return segments;
	}

	bool Triangle::is_intersection(const Segment& segment) const
	{
		if (segment.is_degenerate())
			return is_inside(segment.get_begin());

		Vector v(segment);
		Vector normal = Vector(p1, p2) ^ Vector(p1, p3);

		if (fabs(normal*v) < EPSILON)
		{
			if (fabs(normal*Vector(p1, segment.get_end())) >= EPSILON)
				return false;

			for (auto s : get_segments())
			{
				if (s.is_intersection(segment))
					return true;
			}
			return is_inside(segment.get_begin()) || is_inside(segment.get_end());
		}

		double ratio = (normal * Vector(p1, segment.get_end())) / (normal*v);

		if (ratio<0 || ratio>1)
			return false;

		Point p_intersection = segment.get_inside_point(ratio);
		return is_inside(p_intersection);
	}

	bool Triangle::is_intersection(const Triangle& t) const
	{
		for (auto s : t.get_segments())
		{
			if (is_intersection(s))
				return true;
		}
		return false;
	}

	Segment Triangle::get_max_segment() const
	{
		std::vector<Segment> v = get_segments();
		return *max_element(v.begin(), v.end(), 
			[](const Segment& s1, const Segment& s2)
		{
			return s1.length() < s2.length();
		});
	}

	bool is_intersection(const Triangle& t1, const Triangle& t2)
	{
		if (!t1.is_degenerate())
		{
			if (t1.is_intersection(t2))
				return true;
			if (!t2.is_degenerate())
				return t2.is_intersection(t1);				
		}

		if (!t2.is_degenerate() && t2.is_intersection(t1))
			return true;

		return t1.get_max_segment().is_intersection(t2.get_max_segment());
	}
}
