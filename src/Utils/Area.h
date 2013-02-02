#ifndef AREA_H_
#define AREA_H_

namespace Utils
{
	using namespace std;

	class Area
	{
		const Point topLeft, bottomRight;
	public:
		const Point& P1() const { return topLeft; }
		const Point& P2() const { return bottomRight; }
		Area(Point& topLeft, Point& bottomRight):topLeft(topLeft), bottomRight(bottomRight) {}
		int Size() const { auto t = bottomRight - topLeft; return t.X() * t.Y(); }
		Point Dim() const { return bottomRight - topLeft; }
		string ToString() const { stringstream ss; ss << "{" << topLeft.ToString() << ", " << bottomRight.ToString() << "}"; return ss.str(); }
	};
}

#endif
