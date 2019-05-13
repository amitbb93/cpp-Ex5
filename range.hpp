#pragma once
#include <iostream>
using namespace std;
namespace itertools{
	
	template<typename T>
	
	class rangeClass{
    public:
		T t1, t2;
        rangeClass(){}
        rangeClass(T& t3, T& t4):t1(t3),t2(t4){};


        class iterator {
		public:        
			T t;
            iterator(){}
            iterator(T t0):t(t0){};
			
			bool operator==(const T &t0) const {
                return t == t0;
            }
			
			bool operator!=(const iterator &t0) const {
                return t != t0.t;
            }

            const iterator operator++(int i) {
                iterator temp = *this;
                t = t++;
                return temp;
            }

            iterator &operator++() {
                t++;
                return *this;
            }

            T operator*() const {
                return t;
            }
		
		};

		auto begin()
		{
			return iterator{t1};
		}

		auto end()
		{
		   return iterator{t2};
		}	

    };

    template<typename T> rangeClass <T> range(T t1, T t2) {
        return rangeClass<T>(t1, t2);

    }
};