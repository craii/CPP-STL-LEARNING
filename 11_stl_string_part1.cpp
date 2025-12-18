#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 11_stl_string_part1 11_stl_string_part1.cpp
// ./11_stl_string_part1
using namespace std;

int main()
{
    //Constructors
    string s1("Hello"); //also string s1(somestr.begin(), somestr.begin() + 3); 

    string s2("Hello", 3); //s2: Hel 第一个函数如果是【字符串】，那么第2个参数的数字是 end position
    string s3(s1, 2); //s3: llo 第一个函数如果是【字符串变量】，那么第2个参数的数字是 start position

    string s4(s1, 2, 2); //s4 ll 第一个函数如果是【字符串变量】，那么第2个参数的数字是 start position, 第3个参数是size，
    string s5(5, 'a'); //s5: "aaaaa"
    string s6({'a', 'b', 'c'}); //s6: "abc"

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    string sg = "goodbye";
    cout << "size:" << sg.size() << endl;
    cout << "length:" << sg.length() << endl;// synonymous, both returns 7
    cout << "capacity:" << sg.capacity() << endl; //size of storage space currently allocated to s1
    
    sg.reserve(100); // this will allocate 100 characters of space to string sg
    cout << "capacity after reserve(100) operation:" << sg.capacity() << endl;

    sg.reserve(5); // 因为
    cout << "capacity after reserve(5) operation, capacity " << sg.capacity() << endl;
    cout << "size after reserve(5) operation, size " << sg.size() << endl;

    sg.shrink_to_fit(); // shrink the capacity to hold the contents不一定会生效，库可能会选择忽略此操作而进行自主优化
    cout << "capacity after shrink_to_fit() operation, capacity " << sg.capacity() << endl;

    sg.resize(9);
    cout << "resize sg " << sg.size() << endl;
    cout<<""<<sg<<""<< "|"<<endl;

    sg.resize(12, 'x'); //sg: goodbye\0\0xxx 用x补足sg到指定size 12
    cout<<""<<sg<<""<<endl;

    sg.resize(3);
    cout<<""<<sg<<""<<endl;

}