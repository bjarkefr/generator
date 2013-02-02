#ifndef TREEMAPPERINT_H_
#define TREEMAPPERINT_H_

namespace Utils
{
	namespace Algorithm
	{
		class Allocation
		{
			int area;
			std::shared_ptr<Area> location;
		public:
			Allocation(int area):area(area),location(0) {}

			int GetSize() const
			{
				return area;
			}

			std::shared_ptr<Area> GetLocation() const
			{
				return location;
			}

			void Place(std::shared_ptr<Area> location)
			{
				this->location = location;
			}
		};

//		class AllocationSet
//		{
//			int area;
//			std::vector<std::shared_ptr<Allocation>> allocations;
//		public:
//			AllocationSet():area(0),allocations() {}
//
//			void AddAllocation(std::shared_ptr<Allocation> allocation)
//			{
//				allocations.push_back(allocation);
//				area += allocation->GetArea();
//			}
//
//
//
//			const int GetTotalArea() const
//			{
//				return area;
//			}
//		};

		typedef std::vector<std::shared_ptr<Allocation>> AllocationSet;

		class TreeMapperInt
		{
			int width;
			int height;
			std::shared_ptr<AllocationSet> candidates;
			int* SelectDirection();
			int* OtherDirection(int* direction);
			int LayoutRow(const AllocationSet& rowSet, int row_area, int* row_length, int* other_length);
			//int worst(vector<double>& row, double w);
			//void squarify(vector<double>& children, vector<double>& row, double w);
		public:
			TreeMapperInt(const Point& dimensions, std::shared_ptr<AllocationSet> candidates);
			void Map();
		};
	}
}

#endif
