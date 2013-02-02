#include "../precompiled/all.h"
#include "Utils/Point.h"
#include "Utils/Area.h"
#include "Utils/D2Array.h"
#include "Model/Room.h"
//#include "Utils/Algorithm/TreeMapper.h"
#include "Utils/Algorithm/TreeMapperInt.h"

using namespace std;
//using namespace boost;
using namespace Utils;
using namespace Utils::Algorithm;
using namespace Model;

typedef vector<std::shared_ptr<Room>> RoomList;

RoomList SetupRooms()
{
	RoomList rooms;
	for(int i = 0; i < 5; ++i)
	{
		std::shared_ptr<Room> room = std::shared_ptr<Room>(new Room(PRIVATE_ROOM, 9));
		rooms.push_back(room);
	}
	std::shared_ptr<Room> broom1 = std::shared_ptr<Room>(new Room(BATHROOM, 16));
	rooms.push_back(broom1);
	std::shared_ptr<Room> broom2 = std::shared_ptr<Room>(new Room(BATHROOM, 16));
	rooms.push_back(broom2);
	std::shared_ptr<Room> sroom = std::shared_ptr<Room>(new Room(STORAGE, 32));
	rooms.push_back(sroom);
	return rooms;
}

//void PlaceRooms(Graph& rooms, FloorPlan& plan)
//{
//
//}

//void PrintPlan(const FloorPlan& plan)
//{
//    for(int y = 0; y < plan.Height(); ++y)
//    {
//    	for(int x = 0; x < plan.Width(); ++x)
//    		cout << plan[Point(x, y)]->Template->GetSymbol();
//
//    	cout << endl;
//    }
//}

int main(int argc, char *argv[])
{
	try
	{
		//Room dummyRoom(DUMMY, 0);
		//RoomList rooms = SetupRooms();

		//Room room(STORAGE, 10);

		std::shared_ptr<vector<std::shared_ptr<Room>>> rooms = std::shared_ptr<vector<shared_ptr<Room>>>(new vector<std::shared_ptr<Room>>());
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 6)));
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 6)));
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 4)));
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 3)));
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 2)));
		rooms->push_back(std::shared_ptr<Room>(new Room(DUMMY, 2)));

		std::shared_ptr<vector<std::shared_ptr<Placeable>>> placeables(new vector<std::shared_ptr<Placeable>>(rooms->begin(), rooms->end()));

		TreeMapperInt mapper = TreeMapperInt(Point(6, 4), placeables);

		mapper.Map();
	}
	catch(string& e)
	{
		cout << "BFE: " << e << endl;
	}
}
