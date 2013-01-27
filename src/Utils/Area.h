#ifndef AREA_H_
#define AREA_H_

namespace Utils
{
	using namespace std;

	class Area
	{
		Point topLeft, bottomRight;
	public:
		Area(Point& topLeft, Point& bottomRight):topLeft(topLeft), bottomRight(bottomRight) {}
		Point Size() const { return bottomRight - topLeft; }
		string ToString() const { stringstream ss; ss << "{" << topLeft.ToString() << ", " << bottomRight.ToString() << "}"; return ss.str(); }
	};
}

#endif
