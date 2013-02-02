#ifndef ROOM_H_
#define ROOM_H_
#include "../Utils/Algorithm/Placeable.h"

namespace Model
{
	enum ROOM_TYPE { PRIVATE_ROOM, PRIVATE_ROOM_STORAGE, STORAGE, BATHROOM, HALL, DUMMY};

	class Room : public Utils::Algorithm::Placeable
	{
		std::shared_ptr<Utils::Area> location;
	public:
	    ROOM_TYPE Type;
		int Size;

		Room(ROOM_TYPE type, int size):Placeable(),location(0),Type(type),Size(size) {}

	    std::string GetName() const;

	    char GetSymbol() const;

	    int RequestedSize() const
	    {
	    	return Size;
	    }

	    std::shared_ptr<Utils::Area> Location() const
	    {
	    	return location;
	    }

	    void Place(std::shared_ptr<Utils::Area> location);

	    std::string ToString() const;
	};
}

#endif
