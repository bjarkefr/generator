#include "../../../precompiled/all.h"
#include "../Point.h"
#include "../Area.h"
#include "TreeMapperInt.h"

#include <cstdio>

using namespace Utils;
using namespace Utils::Algorithm;

using namespace std;
using namespace boost::adaptors;

TreeMapperInt::TreeMapperInt(const Point& dimensions, shared_ptr<AllocationSet> candidates):width(dimensions.X()),height(dimensions.Y()),candidates(candidates)
{
}

int TreeMapperInt::LayoutRow(const AllocationSet& rowSet, int row_area, int* row_length, int* other_length)
{
	int row_width = row_area / *row_length;

	int acc_length = 0;
	for(auto alloc : rowSet)
	{
		int area_length = alloc->RequestedSize() / row_width;

		int x1 = *other_length - row_width;
		int x2 = *other_length;

		int y1 = acc_length;
		int y2 = acc_length + area_length;

		Point p1 = Point(x1, y1);
		Point p2 = Point(x2, y2);

		if(row_length == &width)
		{
			p1 = p1.Swap();
			p2 = p2.Swap();
		}

		acc_length += area_length;

		auto area = shared_ptr<Area>(new Area(p1, p2));

		alloc->Place(area);
		printf("Area (%i, %i) - (%i, %i) - ", p1.X(), p1.Y(), p2.X(), p2.Y());
		printf("size (%i x %i) = %i ~ %i\n", area->Dim().X(), area->Dim().Y(), area->Size(), alloc->RequestedSize());
	}

	printf("\n");
	return row_width;
}

static int penalty(int largest_area, int smallest_area, int row_length, int row_area)
{
	int s2 = row_area * row_area;
	int l2 = row_length * row_length;
	return max(l2 * largest_area / s2, s2 / (l2 * smallest_area));
}

static int penalty(int new_area, int row_length, int row_area)
{
	int s2 = row_area * row_area;
	int l2 = row_length * row_length;
	return max(l2 * new_area / s2, s2 / (l2 * new_area));
}

int* TreeMapperInt::SelectDirection()
{
	return width > height ? &height : &width;
}

int* TreeMapperInt::OtherDirection(int* direction)
{
	return direction == &width ? &height : &width;
}

void TreeMapperInt::Map()
{
	int *row_length = SelectDirection(), *other_length = OtherDirection(row_length);

	AllocationSet rowSet;
	int row_area = 0;
	int row_min_area = numeric_limits<int>::max();
	int row_max_area = numeric_limits<int>::min();

	for(auto alloc = candidates->begin(); alloc != candidates->end(); ++alloc)
	{
		int area = (*alloc)->RequestedSize();

		if(row_area != 0 && penalty(row_max_area, row_min_area, *row_length, row_area) < penalty(area, *row_length, row_area + area)) // Why recompute last times worst value each iteration...?
		{
			*other_length -= LayoutRow(rowSet, row_area, row_length, other_length);

			row_length = SelectDirection();
			other_length = OtherDirection(row_length);

			rowSet = AllocationSet();
			row_area = 0;
			row_min_area = numeric_limits<int>::max();
			row_max_area = numeric_limits<int>::min();
		}

		rowSet.push_back(*alloc);

		row_area += area;

		if(row_min_area > area)
			row_min_area = area;

		if(row_max_area < area)
			row_max_area = area;
	}
	*other_length -= LayoutRow(rowSet, row_area, row_length, other_length);
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
