#ifndef FLOORPLAN_H_
#define FLOORPLAN_H_

namespace Model
{
	class Floorplan
	{
		Utils::D2Array<std::shared_ptr<Room>> data;
		char Render(const Utils::Point& pos) const;
//		wchar_t Render(const Utils::Point& p) const;
	public:
		Floorplan(const Utils::Point& dimensions);
		void Place(std::shared_ptr<Room> room);
		std::string ToString() const;
//		std::wstring ToWString() const;
	};
}

#endif

