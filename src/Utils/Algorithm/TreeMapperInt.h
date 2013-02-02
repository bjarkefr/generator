#ifndef TREEMAPPERINT_H_
#define TREEMAPPERINT_H_
#include "Placeable.h"

namespace Utils
{
	namespace Algorithm
	{
		typedef std::vector<std::shared_ptr<Placeable>> AllocationSet;

		class TreeMapperInt
		{
			int width;
			int height;
			std::shared_ptr<AllocationSet> candidates;
			int* SelectDirection();
			int* OtherDirection(int* direction);
			int LayoutRow(const AllocationSet& rowSet, int row_area, int* row_length, int* other_length);
		public:
			TreeMapperInt(const Point& dimensions, std::shared_ptr<AllocationSet> candidates);
			void Map();
		};
	}
}

#endif
