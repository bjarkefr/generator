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
			double width;
			double height;
			const std::vector<Node>& nodes;
			double *current_length;
			double *other_length;
			std::vector<Placement> placements;
			void select_direction();
			void layoutrow(vector<double>& row);
			double worst(vector<double>& row, double w);
			void squarify(vector<double>& children, vector<double>& row, double w);
		public:
			TreeMapper(int w, int h, const std::vector<Node>& nodes);
			std::vector<Placement> Map();
		};
	}
}

#endif
