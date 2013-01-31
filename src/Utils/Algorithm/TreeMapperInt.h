#ifndef TREEMAPPERINT_H_
#define TREEMAPPERINT_H_

namespace Utils
{
	namespace Algorithm2
	{
		class Allocation
		{
			int area;
			std::shared_ptr<Area> placement;
		public:
			Allocation(int area):area(area),placement(0) {}

			int GetArea() const
			{
				return area;
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
			std::shared_ptr<AllocationSet> allocated;
			std::shared_ptr<AllocationSet> candidates;
			int *current_length;
			int *other_length;
			//void select_direction();
			//void layoutrow(vector<double>& row);
			//double worst(vector<double>& row, double w);
			//void squarify(vector<double>& children, vector<double>& row, double w);
		public:
			TreeMapperInt(const Point& dimensions, std::shared_ptr<AllocationSet> candidates);
			std::shared_ptr<AllocationSet> Map();
		};
	}
}

#endif
