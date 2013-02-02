#include "../../precompiled/all.h"

#include "../Utils/Area.h"
#include "../Utils/D2Array.h"
#include "../Utils/Point.h"
#include "Room.h"
#include "Floorplan.h"

using namespace std;
using namespace Model;
using namespace Utils;

Floorplan::Floorplan(const Utils::Point& dimensions):data(D2Array<shared_ptr<Room>>(dimensions, 0)) {}

void Floorplan::Place(std::shared_ptr<Room> room)
{
	auto area = room->Location();
	for(auto y = area->P1().Y(); y != area->P2().Y(); ++y)
	{
		for(auto x = area->P1().X(); x != area->P2().X(); ++x)
		{
			printf("%i, %i\n", x, y);
			if(data[Point(x, y)] == 0)
				data[Point(x, y)] = room;
			else
				throw string("Error " + Point(x, y).ToString() + " already occupied!");
		}
	}
}

//wchar_t Floorplan::Render(const Point& p) const
//{
//	return '+';
//}
//
//wstring Floorplan::ToWString() const
//{
//	wstringstream ss;
//
//	for(auto y = 0; y < data.Height(); ++y)
//	{
//		for(auto x = 0; x < data.Width(); ++x)
//		{
//			Point p = Point(x, y);
//			auto d = data[p];
//			wchar_t c = '?';
//
//			if(d != 0)
//				c = Render(p);
//
//			ss << c;
//
//		}
//
//		ss << endl;
//	}
//
//	return ss.str();
//}

enum RenderChars { VERTICAL = '\xb3', TOPLEFT = '\xda', HORIZONTAL = '\xc4', TOPRIGHT = '\xbf', BOTTOMRIGHT = '\xd9', BOTTOMLEFT = '\xc0', DBVERTICAL = '\xba', DBHORIZONTAL = '\xcd', BOX = '\xfe' };

char Floorplan::Render(const Point& pos) const
{
	auto area = *(data[pos]->Location());
	char c = '?';

	if(area.P1().X() == pos.X() || area.P2().X() - 1 == pos.X())
		c = VERTICAL;
	if(area.P1().Y() == pos.Y() || area.P2().Y() - 1 == pos.Y())
		c = HORIZONTAL;
	if(area.P1().X() == pos.X() && area.P1().Y() == pos.Y())
		c = TOPLEFT;
	if(area.P1().Y() == pos.Y() && area.P2().X() - 1 == pos.X())
		c = TOPRIGHT;
	if(area.P2().X() - 1 == pos.X() && area.P2().Y() - 1 == pos.Y())
		c = BOTTOMRIGHT;
	if(area.P1().X() == pos.X() && area.P2().Y() - 1 == pos.Y())
		c = BOTTOMLEFT;

	if(area.P1().X() == area.P2().X() - 1)
		c = DBVERTICAL;
	if(area.P1().Y() == area.P2().Y() - 1)
		c = DBHORIZONTAL;
	if(area.P1().X() == area.P2().X() - 1 && area.P1().Y() == area.P2().Y() - 1)
		c = BOX;

	return c;
}

string Floorplan::ToString() const
{
	stringstream ss;

	for(auto y = 0; y < data.Height(); ++y)
	{
		for(auto x = 0; x < data.Width(); ++x)
		{
			Point p = Point(x, y);
			auto d = data[p];
			char c = '?';

			if(d != 0)
				c = Render(p);

			ss << c;
		}
		ss << endl;
	}

	return ss.str();
}
