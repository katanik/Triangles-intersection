#pragma once

namespace BykovaE
{
	const double EPSILON = 1e-11;

	class Vector;

	class Point
	{
		double x, y, z;

	public:

		Point(double x = 0, double y = 0, double z = 0);
		Point(const Vector&);
		~Point();

		Point move_to(const Vector&) const;
		friend double dist(const Point&, const Point&);

		friend class Vector;
	};


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


	class Vector
	{
		double x, y, z;

	public:

		Vector(double x, double y, double z);
		Vector(const Point&);
		Vector(const Segment&);
		Vector(const Point& p_begin, const Point& p_end);
		~Vector();

		Point get_point() const;
		double length() const;

		void operator+= (const Vector&);
		void operator-=(const Vector&);
		void operator*=(double);
		void operator/=(double);

		Vector operator*(double);
		Vector operator/(double);

		// this is the cross product
		friend Vector operator^ (const Vector&, const Vector&);

		//this is the dot product
		friend double operator* (const Vector&, const Vector&);

		friend class Point;
	};

	Vector operator+(const Vector&, const Vector&);
	Vector operator-(const Vector&, const Vector&);
}
