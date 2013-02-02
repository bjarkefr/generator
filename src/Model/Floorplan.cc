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

string Floorplan::ToString() const
{
	stringstream ss;

	for(auto y = 0; y < data.Height(); ++y)
	{
		for(auto x = 0; x < data.Width(); ++x)
		{
			auto d = data[Point(x, y)];
			char c = '`';

			if(d != 0)
				c = d->GetSymbol();

			ss << c;

		}

		ss << endl;
	}

	return ss.str();
}
