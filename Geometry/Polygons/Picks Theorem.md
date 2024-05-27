A polygon without self-intersections is called lattice if all its vertices have integer coordinates in some 2D grid. Pick's theorem provides a way to compute the area of this polygon through the number of vertices that are lying on the boundary and the number of vertices that lie strictly inside the polygon.

Formula¶
Given a certain lattice polygon with non-zero area.

We denote its area by  
$S$ , the number of points with integer coordinates lying strictly inside the polygon by  
$I$  and the number of points lying on polygon sides by  
$B$ .

Then, the Pick's formula states:

$$S=I+\frac{B}{2}-1$$ 
In particular, if the values of  
$I$  and  
$B$  for a polygon are given, the area can be calculated in  
$O(1)$  without even knowing the vertices.

This formula was discovered and proven by Austrian mathematician Georg Alexander Pick in 1899.
