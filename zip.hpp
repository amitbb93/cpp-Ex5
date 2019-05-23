#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace itertools
{
    template <typename T, typename Y>
    class zip{ 
        public:
            const T t;
            const Y y;
			
			zip<T,Y>(const T t0, const Y y0): t(t0), y(y0){} 
          
			auto begin() const {return iterator(t,y);}
			
			auto end() const {return iterator(t,y,false);}
			
            class iterator{ 
            public:
                decltype(t.begin()) v;
                decltype(y.begin()) u;
				iterator(){}
                
				iterator(const T &t,const Y &y){
					v = t.begin();
					u = y.begin();           
				}
				
				iterator(const T &t,const Y &y, bool b){
					v = t.end();
					u = y.end();           
				}
				
				bool operator==(const iterator &iter) const {return v == iter.v;}

                bool operator!=(const iterator &iter) const {return (u != iter.u);}
			   
				auto operator*() const {return make_pair(*v,*u);}
			   
                iterator& operator++()
                {
                    ++v;
                    ++u;
                    return *this;
                }
            };
        };    
		
		template<typename T, typename Y>
		ostream& operator<<(ostream& os, const pair<T, Y>& p){
			os << p.first << ","
			<< p.second<<" ";
			return os;
		}

};