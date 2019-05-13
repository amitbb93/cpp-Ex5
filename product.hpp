#pragma once
#include <iostream>
using namespace std;
namespace itertools{

	template<class T, class Y>
	
	class product{
        T t;
        Y y;
	public:
		product(){}
        product(T t0,Y y0):t(t0),y(y0){};
        
		auto begin()
		{
			return t.begin();
		}

		auto end()
		{
		   return t.begin();
		}	
		
		class iterator
		{
			T t1;
			Y y1;
		public:
			iterator(T t0, Y y0) : t1(t0), y1(y0){}
		};
				
	};
};