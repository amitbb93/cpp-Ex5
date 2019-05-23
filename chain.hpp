#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
    template <typename T, typename Y>
    class chain{
        public:
            const T t;
            const Y y;
			
			chain(){}
			
			chain<T,Y>(const T t0,const Y y0): t(t0), y(y0){} 

            auto begin() const {return iterator(t,y);}

			auto end() const {return iterator(t,y,false);}
			
            class iterator{
				public:				
					decltype(t.begin()) v;
					decltype(y.begin()) u;
					short flag;
					
					iterator(){}
					
					iterator(const T &t,const Y &y) {
						v = t.begin();
						u = y.begin();
						flag = 1; 
					}
					iterator(const T &t,const Y &y, bool b) {
						v = t.end();
						u = y.end();
						flag = 1; 
					}
					
					iterator& operator++() {
						switch(flag){					
							case 1:{++v;break;}
							default:{++u;break;}
						}
						return *this;
					}

					auto operator* () const{   
						switch(flag){
							case 1:return *v;
							case 0:return *u;
						}
						return *u;
					}

					bool operator!=(const iterator &iter)  {
						if (!(v != iter.v)){if(flag == 1)flag = 0;}
						switch(flag){					
							case 1:return (v != iter.v);
							default:return (u != iter.u);
						}
					}
            }; 
        };    
}; 

