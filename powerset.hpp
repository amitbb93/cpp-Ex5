#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned int uint;
namespace itertools
{
    template <typename T>
    class powerset
    {
	public: 
        const T t; 
        
		powerset(const T iter) : t(iter) {} 

		auto begin() const {return iterator(t);}
				
		auto end() const {return iterator(t,false);}
		
        class iterator
        { 
        public:   
			decltype(t.begin()) y1;
			decltype(t.begin()) y2;		
            uint sizeMin, sizeMax;     


			iterator();
			
            iterator(const T &y3){
                y1 = y3.begin();
				y2 = y3.end();
				sizeMax = 0;
				sizeMin = checkSize(); 
            }
			
			iterator(const T &y3, bool b){ 
                y1 = y3.end();
				y2 = y3.end();
				sizeMax = 0;
                sizeMin = checkSize();
            }
			
			uint checkSize(){
				uint z1 = 0;
				decltype(y1) y0;
				y0 = y1;
				while (y0 != y2)
                { 
                    ++z1;
                    ++y0;
                }
				return pow(2, z1);
			}

            bool operator!=(const iterator &iter) const { //CHECK SIMPLE WAY
                return ((sizeMin - sizeMax) != (iter.sizeMin - iter.sizeMax - 1));
            }

            iterator &operator++(){ 
                ++sizeMax;
                return *this;
            }
			
			auto operator*() const
			{
				decltype(y1) y0;
				y0 = y1;				
				vector<typename remove_const<typename remove_reference<decltype(*y1)>::type>::type> temp;
				for (uint i = sizeMax; i != 0 && y0 != y2; i=i/2)
				{ 
					uint r = i % 2;
					if (r == 1)temp.emplace_back(*y0);
					++y0;
				}
					return temp;
			}
        };
    }; 

    template <typename T>
    ostream &operator<<(ostream &os, vector<T> &iter)
    {
		auto temp = iter.begin();
		if(iter.begin() == iter.end()){
			os << "{";
			os << "}";
			return os;
		}
		else{
			os << "{";
			os << *temp;
			++temp;
		}
        while (temp != iter.end()){ 
            os << ',' << *temp;
            ++temp;
        }
        os << "}"; 
        return os;
    }
}; 