#include <iostream>
#include <bits/stdc++.h>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;
#include "badkan.hpp"
#define COMMA ,
template<typename Iterable>
string toString(const Iterable& iterable){
 stringstream ostr;
 for(decltype(*(iterable.begin())) i: iterable){
   ostr << i << ",";
 }     
 return ostr.str();
} 
int main() {
	
	
	

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
		

auto range1=range(1,9);
auto range2=range(1.1,7.1);
auto range3=range('c','h');
auto chain1= chain(string("lihi"),string("amit"));
auto chain2= chain(range('a','c'), string("amitbibi"));
auto chain3= chain(range('c','d'), range('d','f'));
auto zip1=zip(range(0,5), string("hello"));
auto zip2=zip(range('a','f'), string("lihib"));
auto zip3=zip(zip1,zip2);
auto zip4=zip(range(7,13), range('a','g'));
auto zip5=zip(chain(range(1,5), range(5,10)), string("abcdefghi"));
auto zip6=zip(range(23,29),string("amitbb"));
auto product1 = product(chain(range(1,2),range(2,4)),range('a','c'));
auto product2 = product(range(1,2), string("amit"));
auto product3 = product(string("lihi"), string("b"));
auto powerset1 = powerset(range(1,4));
auto powerset2 = powerset(range('a','d'));
auto powerset3 = powerset(chain(range('a','c'),range('1','2')));

auto iterator1=range1.begin();
auto iterator2=range2.begin();
auto iterator3=range3.begin();
auto iterator4=chain1.begin();
auto iterator5=chain2.begin();
auto iterator6=chain3.begin();
auto iterator7=zip1.begin();
auto iterator8=zip2.begin();
auto iterator9=zip3.begin();
auto iterator10=zip4.begin();
auto iterator11=zip5.begin();
auto iterator12=zip6.begin();
auto iterator13 = product1.begin();
auto iterator14 = product2.begin();
auto iterator15 = product3.begin();
auto iterator16 = powerset1.begin();
auto iterator17 = powerset2.begin();
auto iterator18 = powerset3.begin();

string result1="";
string result2="";
string result3="";
string result4="";
string result5="";
string result6="";
std::stringstream result7, result8, result9, result10, result11, result12, result13, result14, result15, result16, result17, result18;


for(int i: range1) result1 += to_string(i);
for(double i: range2) result2 += to_string(i);
for(char i: range3)result3 += to_string(i);
for(char i : chain1)result4+=i;
for(char i : chain2)result5+=i;
for(char i : chain3)result6+=i;
for (auto i : zip1)result7 << i << " ";
for (auto i : zip2)result8 << i << " ";
for (auto i : zip3)result9 << i << " ";
for (auto i : zip4)result10 << i << " ";
for (auto i : zip5)result11 << i << " ";
for (auto i : zip6)result12 << i << " ";
for (auto i : product1)result13 << i << " ";
for (auto i : product2)result14 << i << " ";
for (auto i : product3)result15 << i << " ";
for (auto i : powerset1)result16 << i << " ";
for (auto i : powerset2)result17 << i << " ";
for (auto i : powerset3)result18 << i << " ";


string answer=toString(result1);
string answer1=toString(result2);
string answer2=toString(result3);
string answer3=toString(result4);
string answer4=toString(result5);
string answer5=toString(result6);

cout<<"result3: "<<answer1<<endl;
cout<<"result2: "<<answer2<<endl;
testcase.setname("range result ")
.CHECK_EQUAL ( answer=="12345678", true)
.CHECK_EQUAL ( answer1=="1.12.13.14.15.16.1", true)
.CHECK_EQUAL ( answer2=="cdefg", true)
;
testcase.setname("chain results  ")
.CHECK_EQUAL ( result4=="lihiamit", true )
.CHECK_EQUAL ( result5=="abamitbibi", true )
.CHECK_EQUAL ( result6=="cde", true )
;
testcase.setname("zip results  ")
.CHECK_OUTPUT ( result7.str(), "0,h  1,e  2,l  3,l  4,o  ")
.CHECK_OUTPUT ( result8.str(),"al bi ch di eb")
.CHECK_OUTPUT ( result9.str(),"0hal 1ebi 2lch 3ldi 4oeb ")
.CHECK_OUTPUT ( result10.str(),"7,a  8,b  9,c  10,d  11,e  12,f ")
.CHECK_OUTPUT ( result11.str(),"1,a 2,b 3,c 4,d 5,e 6,f 7,g 8,h 9,i")
.CHECK_OUTPUT ( result12.str(),"23,a 24,m 25,i 26,t 27,b 28,b ")
;
testcase.setname("product results  ")
.CHECK_OUTPUT ( result13.str(),"12a 13a 12b 13b ")
.CHECK_OUTPUT ( result14.str(),"1a 1m 1i 1t ")
.CHECK_OUTPUT ( result15.str(),"lb ib hb ib ")
;
testcase.setname("powerset results  ")
.CHECK_OUTPUT ( result16.str()," {} {1} {2} {1,2} {1,2,3}")
.CHECK_OUTPUT ( result17.str()," {} {a} {b} {a,b} {a,b,c} ")
.CHECK_OUTPUT ( result18.str(),"{} {a} {b} {1} {a,b} {a,1} {b,1} {a,b,1} ")
;
/* //won't work shoud work on it
for(auto i  : zip1) result7=result7+to_string(i.first)+i.second+" ";
for(auto i  : zip2) result8=result8+to_string(i.first)+i.second+" ";
for(auto i  : zip4) result9=result9+to_string(i.first)+i.second+" ";
for(auto i  : zip5) result10=result10+to_string(i.first)+i.second+" ";
for(auto i  : zip6) result11=result11+to_string(i.first)+i.second+" ";
for(auto i  : product1)result12=result12+to_string(i.first)+i.second+" ";
for(auto i  : product2)result13=result13+to_string(i.first)+i.second+" ";
for(auto i  : product3)result14=result14+to_string(i.first)+i.second+" ";
*/

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: "  << grade << endl;
    return 0;
}