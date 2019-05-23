#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace itertools
{
    template <typename T, typename Y>
    class product{ 
        public:
            const T t;
            const Y y;
			
			product<T,Y>(const T t0, const Y y0): t(t0), y(y0){} 

			auto begin() const {return iterator(t,y);}
				
			auto end() const {return iterator(t,y,false);}
		
			class iterator {
				 public:
					decltype(t.begin()) v;
					decltype(y.begin()) u;
					pair < decltype(y.begin()), decltype(y.end())> pairIt;
					
					iterator(){}
				
					iterator(const T &t,const Y &y){
						v = t.begin();
						u = y.begin();
						pairIt = make_pair(u,y.end());					
					}
					
					iterator(const T &t,const Y &y, bool b){
						v = t.end();
						u = y.end();     
						pairIt = make_pair(y.begin(),u);					
					}

					auto operator*() const {
						return make_pair(*v,*u);
					}

					iterator &operator++() {
							++u;
							if (!(u != pairIt.second)) {
							  ++v;
							  u = pairIt.first;
							}
						 return *this;
					   }

					bool operator!=(const iterator &iter) {
						if (v != iter.v && u != iter.u)
							return true;
					 else return false;

					}
				};


    };

    /*template<typename T, typename Y>product<T, Y> productIt(T t0, Y y0) {
        return productIt<T, Y>(t0, y0);
    }*/


}
