#ifndef TREEMAPPER_H_
#define TREEMAPPER_H_

namespace Utils
{
	namespace Algorithm
	{
		class Node
		{
			int area;
		public:
			Node(int area):area(area) {}

			int GetArea() const
			{
				return area;
			}
		};

		class Placement
		{
			Area area;
		public:
			Placement(const Area& area):area(area) {}

			const Area& GetArea() const
			{
				return area;
			}
		};

		class TreeMapper
		{
			const std::vector<Node>& nodes;
			std::vector<Placement> placements;
			void layoutrow(vector<int>& row);
			int width();
			int worst(vector<int>& row, int w);
			void squarify(vector<int>& children, vector<int>& row, int w);
		public:
			TreeMapper(const std::vector<Node>& nodes);
			std::vector<Placement> Map();
		};
	}
}

#endif
