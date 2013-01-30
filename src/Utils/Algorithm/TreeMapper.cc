#include "../../../precompiled/all.h"
#include "../Point.h"
#include "../Area.h"
#include "TreeMapper.h"

using namespace Utils;
using namespace Utils::Algorithm;

using namespace std;
using namespace boost::adaptors;
using namespace boost::range;

TreeMapper::TreeMapper(const vector<Node>& nodes):nodes(nodes) {}

void TreeMapper::layoutrow(vector<int>& row)
{

}

int TreeMapper::width()
{
	return 0;
}

int TreeMapper::worst(vector<int>& row, int w)
{
	int s = accumulate(row.begin(), row.end(), 0);
	s = s * s;
	w = w * w;

	auto rng = transform(row, [=](int r) { return max((w * r) / s, s / (w * r)); } );
	vector<int> row2(rng.begin(), rng.end());

	auto mi = max_element(row2.begin(), row2.end());
	if(mi == row2.end())
		throw string("No elements!?");

	return *mi;
}

void TreeMapper::squarify(vector<int>& children, vector<int>& row, int w)
{
	int c = children.back();

	vector<int> new_row(row);
	new_row.push_back(c);

	if (worst(row, w) <= worst(new_row, w))
	{
		children.pop_back();
		squarify(children, new_row, w);
	}
	else
	{
		layoutrow(row);
		auto row = vector<int>();
		squarify(children, row, width());
	}
}

vector<Placement> TreeMapper::Map()
{
	auto range = transform(nodes, [](const Node& item) { return item.GetArea(); });
	vector<int> children(range.begin(), range.end());

	auto row = vector<int>();
	squarify(children, row, 100);

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
