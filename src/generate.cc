#include "../precompiled/all.h"
#include "Utils/Point.h"
#include "Utils/Area.h"
#include "Utils/D2Array.h"
#include "Utils/Algorithm/TreeMapper.h"

using namespace std;
using namespace boost;
using namespace Utils;
using namespace Utils::Algorithm;


enum ROOM_TYPE { PRIVATE_ROOM, PRIVATE_ROOM_STORAGE, STORAGE, BATHROOM, HALL, DUMMY};

const char* ROOM_TEXTS[] = { "Private", "Private storage", "Storage", "Bathroom", "Hall", "Dummy" };

const char ROOM_CHAR[] = { 'P', 'C', 'S', 'W', '.', ' ' };

class Room
{
public:
    ROOM_TYPE Type;
	int Size;

    string GetName() const
    {
		return string(ROOM_TEXTS[Type]);
    }

    char GetSymbol() const
    {
		return ROOM_CHAR[Type];
    }

    string ToString() const { stringstream ss; ss << GetName() << " S:" << Size; return ss.str(); }
};

//class Placement
//{
//public:
//    Placement(Room* _template, Area& allocation):Template(_template), Allocation(allocation) {}
//    Room* Template;
//    Area Allocation;
//    string ToString() const { stringstream ss; ss << Template->ToString() << " - " << Allocation.ToString(); return ss.str(); }
//};

//typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, Room> Graph;

typedef vector<std::shared_ptr<Room>> RoomList;

//typedef D2Array<Placement*> FloorPlan;
//typedef boost::multi_array<Placement*, 2> FloorPlan;
//typedef boost::array<FloorPlan::index, 2> PlanCoord;

RoomList SetupRooms()
{
	RoomList rooms;
	for(int i = 0; i < 5; ++i)
	{
		std::shared_ptr<Room> room = std::shared_ptr<Room>(new Room());
		room->Type = PRIVATE_ROOM;
		room->Size = 9;
		rooms.push_back(room);
	}
	std::shared_ptr<Room> broom1 = std::shared_ptr<Room>(new Room());
	broom1->Type = BATHROOM;
	broom1->Size = 16;
	rooms.push_back(broom1);
	std::shared_ptr<Room> broom2 = std::shared_ptr<Room>(new Room());
	broom2->Type = BATHROOM;
	broom2->Size = 16;
	rooms.push_back(broom2);
	std::shared_ptr<Room> sroom = std::shared_ptr<Room>(new Room());
	sroom->Type = STORAGE;
	sroom->Size = 32;
	rooms.push_back(sroom);
	return rooms;
}

//void SetupRooms(Graph& graph)
//{
//	auto h0 = add_vertex(graph);
//	graph[h0].Type = HALL;
//	for(int i = 0; i < 5; ++i)
//	{
//		auto r0 = add_vertex(graph);
//		graph[r0].Type = PRIVATE_ROOM;
//		auto r1 = add_vertex(graph);
//		graph[r1].Type = PRIVATE_ROOM_STORAGE;
//		add_edge(r0, r1, graph);
//		add_edge(h0, r0, graph);
//	}
//	auto b0 = add_vertex(graph);
//	graph[b0].Type = BATHROOM;
//	add_edge(h0, b0, graph);
//	auto b1 = add_vertex(graph);
//	graph[b1].Type = BATHROOM;
//	add_edge(h0, b1, graph);
//
//	auto s0 = add_vertex(graph);
//	add_edge(h0, s0, graph);
//}

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
		Room dummyRoom;
		dummyRoom.Type = DUMMY;
		dummyRoom.Size = 0;

		RoomList rooms = SetupRooms();

		//Point p1(0, 0), p2(10, 10);
		//Area area(p1, p2);
		//Placement dummyPlacement(&dummyRoom, area);

		//FloorPlan plan = FloorPlan(10, 10, &dummyPlacement);

		Room room;
		room.Type = STORAGE;
		room.Size = 10;

		Point p3(2,2), p4(2,4);
		Area a2(p3, p4);
		//Placement place2(&room, a2);

		vector<Node> nodes;
		nodes.push_back(Node(1));
		nodes.push_back(Node(2));
		nodes.push_back(Node(2));
		nodes.push_back(Node(3));
		nodes.push_back(Node(4));
		nodes.push_back(Node(6));
		nodes.push_back(Node(6));

		TreeMapper mapper = TreeMapper(6, 4, nodes);

		mapper.Map();

		//plan[Point(3,2)] = &place2;

		//cout << plan[Point(3,2)]->ToString() << endl;

		//PrintPlan(plan);

		//dummyPlacement.Template = &dummyRoom;

	//	for(auto i = plan.data(); i != plan.data() + plan.num_elements(); ++i)
	//	{
	//		*i = &dummyPlacement;
	//	    cout << (*i)->Allocation.Size().ToString() << endl; // = &dummyPlacement;
	//	}
	
	/*	Point p(1, 2), p2(3, 4);
		cout << Area(p, p2).ToString() << endl;
		cout << Area(p, p2).Size().ToString() << endl;*/
	
		//cout << *(graph[v0].GetName()) << endl;
	}
	catch(string& e)
	{
		cout << "BFE: " << e << endl;
	}
}
