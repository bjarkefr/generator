#ifndef D2ARRAY_H_
#define D2ARRAY_H_

namespace Utils
{
	template<class T> class D2Array
	{
		const int h, w;
		T* data;

		void CheckBounds(const Point& p) const
		{
			if(p.Y() < 0 || p.Y() >= h)
				throw std::string("Badness 10000");
			if(p.X() < 0 || p.X() >= w)
				throw std::string("Badness 10000");
		}

		T& Ref(const Point& p) const
		{
			CheckBounds(p);
			return data[p.Y() * w + p.X()];
		}

	public:
		D2Array(const Point& dimensions, const T& init):h(dimensions.Y()), w(dimensions.X()), data(new T[dimensions.X() * dimensions.Y()])
		{
			for(int i = 0; i < h * w; ++i)
				data[i] = init;
		}

		int Width() const { return w; }
		int Height() const { return h; }

		const T& operator[](const Point& p) const
		{
			return Ref(p);
		}

		T& operator[](const Point& p)
		{
			return Ref(p);
		}

		~D2Array()
		{
			delete[] data;
		}
	};
}

#endif
