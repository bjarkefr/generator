#ifndef FLOORPLAN_H_
#define FLOORPLAN_H_

namespace Model
{
	class Floorplan
	{
		Utils::D2Array<std::shared_ptr<Room>> data;
	public:
		Floorplan(const Utils::Point& dimensions);
		void Place(std::shared_ptr<Room> room);
		std::string ToString() const;
	};
}

#endif

