#pragma once
#include <iostream>
using namespace std;
namespace itertools{

	template<class T>
	
	class powerset{
        T t;
	public:
		powerset(){}
        powerset(T t0):t(t0){};
        
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
		public:
			iterator(T t0) : t1(t0){}
		};		
	};
};