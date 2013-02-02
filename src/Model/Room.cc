#include "../../precompiled/all.h"
#include "Room.h"

const char* ROOM_TEXTS[] = { "Private", "Private storage", "Storage", "Bathroom", "Hall", "Dummy" };

const char ROOM_CHAR[] = { '\xB0', 'C', 'S', 'W', '.', ' ' };

using namespace Model;
using namespace std;
using namespace Utils;

char Room::GetSymbol() const
{
	return ROOM_CHAR[Type];
}

string Room::GetName() const
{
	return string(ROOM_TEXTS[Type]);
}

void Room::Place(std::shared_ptr<Area> location)
{
	this->location = location;
}

string Room::ToString() const
{
	stringstream ss;
	ss << GetName() << " S:" << Size;
	return ss.str();
}
