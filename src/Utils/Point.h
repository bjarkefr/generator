#ifndef POINT_H_
#define POINT_H_

namespace Utils
{
	using namespace std;

	class Point
	{
	public:
		int X, Y;
		Point(int x, int y):X(x), Y(y) {}
		Point operator+(const Point& p) const { return Point(X + p.X, Y + p.Y); }
		Point operator-(const Point& p) const { return Point(X - p.X, Y - p.Y); }
		string ToString() const { stringstream ss; ss << "(" << X << ", " << Y << ")"; return ss.str(); }
	};
}

#endif
