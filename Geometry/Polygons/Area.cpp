// Clockwise: negative
// Counter-clockwise: positive

double triangle_signed_area(complex<double> a, complex<double> b, complex<double> c) {
	// return cross(b - a, c - b) / 2.0;
	return (conj(b - a) * (c - b)).imag() / 2.0;
}

// Polygon is sum of signed triangles
// => sum of: (for each edge) triangle(origin, edge.from, edge.to)


// BETTER APPROACH
// NOT SELF INTERSECTING
// for each edge: calculate the area between y=0 and the edge
// 				  add the sign according to the orientation
// 				  sum up all the areas
// 