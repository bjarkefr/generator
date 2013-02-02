#ifndef PLACEABLE_H_
#define PLACEABLE_H_
#include "../Area.h"

namespace Utils
{
	namespace Algorithm
	{
			class Placeable
			{
			public:
				virtual int RequestedSize() const = 0;
				virtual void Place(std::shared_ptr<Utils::Area> location) = 0;
				virtual ~Placeable() {};
			};
	}
}

#endif
