#ifndef POINT_H_
#define POINT_H_

namespace Utils
{
	using namespace std;

	class Point //Immutable
	{
		int x, y;
	public:
		const int& X() const { return x; }
		const int& Y() const { return y; }
		Point(int x, int y):x(x), y(y) {}
		Point Swap() { return Point(x, y); }
		Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
		Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
		string ToString() const { stringstream ss; ss << "(" << x << ", " << y << ")"; return ss.str(); }
	};
}

#endif
