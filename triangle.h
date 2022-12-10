#pragma once

#include "ads.h"

#include <vector>

namespace TrianglesIntersection
{
	class Triangle
	{
		Point p1, p2, p3;

	public:

		Triangle(Point p1 = Point(), Point p2 = Point(), Point p3 = Point());
		~Triangle();

		double area() const;
		bool is_degenerate() const;
		std::vector<Segment> get_segments() const;
		Segment get_max_segment() const;
		bool is_inside(const Point&) const;
		bool is_intersection(const Segment&) const; 
		bool is_intersection(const Triangle&) const;
		friend bool is_intersection(const Triangle&, const Triangle&);
	};

}
