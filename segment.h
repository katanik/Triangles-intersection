#pragma once

#include "point.h"

namespace BykovaE
{
	class Segment
	{
		Point p_begin, p_end;
	public:
		Segment(const Point& p1, const Point& p2);
		~Segment();

		bool is_degenerate() const;
		double length() const;
		Point get_begin() const;
		Point get_end() const;
		 
		Point get_inside_point(double) const;

		bool is_inside(const Point&) const;
		bool is_intersection(const Segment&) const;
	};

}
