#pragma once

#include "stdafx.h"
#include "triangle.h"

#include <iostream>

bool doIntersect(double t1[9], double t2[9])
{
	using namespace TrianglesIntersection;
	Triangle triangle1{ Point{ t1[0], t1[1], t1[2] }, Point{ t1[3], t1[4], t1[5] }, Point{ t1[6], t1[7], t1[8] } };
	Triangle triangle2{ Point{ t2[0], t2[1], t2[2] }, Point{ t2[3], t2[4], t2[5] }, Point{ t2[6], t2[7], t2[8] } };

	return is_intersection(triangle1, triangle2);
}

int main()
{
	double triangle1[9], triangle2[9];

	std::cout << "Enter the points coordinates for the first triangle: ";
	for (int i = 0; i < 9; ++i)
		std::cin >> triangle1[i];

	std::cout << "Enter the points coordinates for the second triangle: ";
	for (int i = 0; i < 9; ++i)
		std::cin >> triangle2[i];

	std::cout << doIntersect(triangle1, triangle2) ? "Yes" : "No";
}