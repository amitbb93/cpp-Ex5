#pragma once
#include <iostream>
using namespace std;
namespace itertools{

	template<class T>
	
	class powerset{
        const T t;
	public:
		powerset(){}
        powerset(const T t0):t(t0){};
        
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
		public:
			iterator(const T t0) : t1(t0){}
		};		
	};
};