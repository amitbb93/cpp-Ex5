#pragma once
#include <iostream>
using namespace std;
namespace itertools{

	template<class T, class Y>
	
	class zip{
        const T t;
        const Y y;
	public:
		zip(){}
        zip(const T t0,const Y y0):t(t0),y(y0){};
        
		auto begin() const
		{
			return t.begin();
		}

		auto end() const
		{
		   return t.begin();
		}	
	
		class iterator
		{
			const T t1;
			const Y y1;
		public:
			iterator(const T t0, const Y y0) : t1(t0), y1(y0){}
			
			auto operator*() const {
                return make_pair(*t1,*y1);
            }
		};
};
}