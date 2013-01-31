#include "../../../precompiled/all.h"
#include "../Point.h"
#include "../Area.h"
#include "TreeMapper.h"

#include <cstdio>

using namespace Utils;
using namespace Utils::Algorithm;

using namespace std;
using namespace boost::adaptors;

TreeMapper::TreeMapper(int width, int height, const vector<Node>& nodes):width((double)width),height((double)height),nodes(nodes)
{
	select_direction();
}

void TreeMapper::select_direction()
{
	current_length = width > height ? &height : &width;
	other_length = current_length == &width ? &height : &width;
}

void TreeMapper::layoutrow(vector<double>& row)
{
	double row_area = accumulate(row.begin(), row.end(), 0.);
	double width = row_area / *current_length;

	for(double box_area : row)
		printf("Box (%f, %f) @%f\n", width, box_area / width, box_area);

	*other_length -= width;
	select_direction();
	printf("Remaining area (%f, %f) @%f\n\n", width, height, width * height);
}

double TreeMapper::worst(vector<double>& row, double w)
{
	double s = accumulate(row.begin(), row.end(), 0.);
	s = s * s;
	w = w * w;

	auto rng = transform(row, [=](double r)->double { return max((w * r) / s, s / (w * r)); } );
	vector<int> row2(rng.begin(), rng.end()); // should not be required...

	auto mi = max_element(row2.begin(), row2.end());
	if(mi == row2.end())
		return numeric_limits<double>::max();

	return *mi;
}

void TreeMapper::squarify(vector<double>& children, vector<double>& row, double w)
{
	if(children.empty())
		return;

	int c = children.back();

	vector<double> new_row(row);
	new_row.push_back(c);

	printf("%f <= %f\n", worst(row, w), worst(new_row, w));

	if (worst(row, w) > worst(new_row, w))
	{
		children.pop_back();
		squarify(children, new_row, w);
	}
	else
	{
		layoutrow(row);
		auto row = vector<double>();
		squarify(children, row, *current_length);
	}
}

vector<Placement> TreeMapper::Map()
{
	auto range = transform(nodes, [](const Node& item) { return (double)item.GetArea(); });
	vector<double> children(range.begin(), range.end());

	auto row = vector<double>();
	squarify(children, row, *current_length);

	vector<Placement> placements;
	return placements;
}


//procedure squarify(list of real children, list of real row, real w)
//begin
//	real c = head(children);
//	if worst(row, w)  worst(row++[c], w) then
//		squarify(tail(children), row++[c], w)
//	else
//		layoutrow(row);
//		squarify(children, [], width());
//	fi
//end
