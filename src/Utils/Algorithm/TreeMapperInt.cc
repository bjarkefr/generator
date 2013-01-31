#include "../../../precompiled/all.h"
#include "../Point.h"
#include "../Area.h"
#include "TreeMapperInt.h"

#include <cstdio>

using namespace Utils;
using namespace Utils::Algorithm2;

using namespace std;
using namespace boost::adaptors;

class AllocationSetExt : public AllocationSet
{
	shared_ptr<Allocation> smallest;
	shared_ptr<Allocation> largest;
	int total_area;

	void Setup(shared_ptr<Allocation> initial)
	{
		push_back(initial);
		smallest = largest = front();
		total_area = initial->GetArea();
	}

public:
	AllocationSetExt(shared_ptr<Allocation> initial)
	{
		Setup(initial);
	}

	void Reset(shared_ptr<Allocation> initial)
	{
		clear();
		Setup(initial);
	}

	void Add(shared_ptr<Allocation> allocation)
	{
		AllocationSet::push_back(allocation);
		int area = allocation->GetArea();

		if(smallest->GetArea() > area)
			smallest = back();

		if(largest->GetArea() < area)
			largest = back();

		total_area += area;
	}

	int GetTotalArea() const
	{
		return total_area;
	}

	shared_ptr<Allocation> GetLargest() const
	{
		return largest;
	}

	shared_ptr<Allocation> GetSmallest() const
	{
		return smallest;
	}
};

TreeMapperInt::TreeMapperInt(const Point& dimensions, shared_ptr<AllocationSet> candidates):width(dimensions.X),height(dimensions.Y),candidates(candidates)
{
	//select_direction();
}

int worst(const AllocationSetExt& set, int row_length) const
{
	set.GetTotalArea() / row_length;
}

shared_ptr<AllocationSet> TreeMapperInt::Map()
{
	int row_length = height;
	int row_area = 0;

	AllocationSetExt rowSet(candidates->front());

	for(auto alloc = ++candidates->begin(); alloc != candidates->end(); ++alloc)
	{
		int area = (*alloc)->GetArea();
		//if(area / row_length)
	}

	//AllocationSetExt set;
	//set.push_back((*candidates)[0]);
	return candidates;
}

//	if(children.empty())
//		return;
//
//	int c = children.back();
//
//	vector<double> new_row(row);
//	new_row.push_back(c);
//
//	printf("%f <= %f\n", worst(row, w), worst(new_row, w));
//
//	if (worst(row, w) > worst(new_row, w))
//	{
//		children.pop_back();
//		squarify(children, new_row, w);
//	}
//	else
//	{
//		layoutrow(row);
//		auto row = vector<double>();
//		squarify(children, row, *current_length);
//	}


//void TreeMapperInt::select_direction()
//{
//	current_length = width > height ? &height : &width;
//	other_length = current_length == &width ? &height : &width;
//}
//
//void TreeMapperInt::layoutrow(vector<double>& row)
//{
//	double row_area = accumulate(row.begin(), row.end(), 0.);
//	double width = row_area / *current_length;
//
//	for(double box_area : row)
//		printf("Box (%f, %f) @%f\n", width, box_area / width, box_area);
//
//	*other_length -= width;
//	select_direction();
//	printf("Remaining area (%f, %f) @%f\n\n", width, height, width * height);
//}
//
//double TreeMapperInt::worst(vector<double>& row, double w)
//{
//	double s = accumulate(row.begin(), row.end(), 0.);
//	s = s * s;
//	w = w * w;
//
//	auto rng = transform(row, [=](double r)->double { return max((w * r) / s, s / (w * r)); } );
//	vector<int> row2(rng.begin(), rng.end()); // should not be required...
//
//	auto mi = max_element(row2.begin(), row2.end());
//	if(mi == row2.end())
//		return numeric_limits<double>::max();
//
//	return *mi;
//}
//
//void TreeMapperInt::squarify(vector<double>& children, vector<double>& row, double w)
//{
//	if(children.empty())
//		return;
//
//	int c = children.back();
//
//	vector<double> new_row(row);
//	new_row.push_back(c);
//
//	printf("%f <= %f\n", worst(row, w), worst(new_row, w));
//
//	if (worst(row, w) > worst(new_row, w))
//	{
//		children.pop_back();
//		squarify(children, new_row, w);
//	}
//	else
//	{
//		layoutrow(row);
//		auto row = vector<double>();
//		squarify(children, row, *current_length);
//	}
//}
