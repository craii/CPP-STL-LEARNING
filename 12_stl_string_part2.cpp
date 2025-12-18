#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 12_stl_string_part2 12_stl_string_part2.cpp
// ./12_stl_string_part2
using namespace std;

int main()
{
    //String

    //Single Element Access
    string s1 = "Goodbye";
    char s1_2 = s1[2];
    s1[2] = 'x'; //Goxdby
    s1.at(2) = 'y'; //Goydby
    //s1.at(20) // throw exception out of range ---> boundry check
    //s1[20]  dangerous undefined behavior

    char f = s1.front(); //'G'
    char e = s1.back(); //'e'

    s1.push_back('z'); // "Goodbyez"; like vector, string have no method push_front()
    s1.pop_back(); // "Goodbye"; 

    // like stl container iterator
    string::iterator itrb = s1.begin(); //G
    string::iterator itre = s1.end(); // 
    cout << *itrb << " " << *(itre - 1) << endl ;

    string s2("Goodby");
    string s3(s2.begin(), s2.begin() + 3); //Goo
    cout<< "init a string with iterator: "<< s3 <<endl;

    //Range Access
    // assign, append, insert, replace
    string s4 = "Dragon Land";
    string s5, s6;
    s5.assign(s4); // s5 = s4;
    cout << "Range Access" << endl;
    cout << s5 << endl;

    s6.assign(s4, 2, 4);
    cout << s6 << endl;
    s6.assign("Wisdom");
    cout << s6 << endl;

    s6.assign("Wisdom", 3); //Wis
    // s6.assign(s4, 3); //error
    s6.assign(3, 'x'); //s6 "xxx"
    s6.assign({'a', 'b', 'c'}); //s6 "abc"

    s6.append(" def"); //s6 "abc"
    s6.insert(2, "mountain", 4); //s6: abmounc def
    cout << s6 << endl;

    s6.replace(2, 5, s4, 3, 3); //s6: abgon def
    cout << s6 << endl;

    //s6: abgon def /erase [1, 4] closed interval
    s6.erase(1, 4);
    cout << s6 << endl;


    string s7 = s4.substr(2, 4); //agon
    cout << s7 << endl;

    string s8 = "abd";
    const char *cs = s8.c_str(); //"abc\0" //不可修改
    cout<< "c_str cs:" << cs << endl;

    char *ms = s8.data(); //"abc\0" //可修改
    ms[0] = 'H';
    cout<< "data ms:" << cs << endl;

    string ss1("abc"), ss2("def");
    cout << "before swap, ss1 ss2: "<< ss1 << " " << ss2 << endl;
    ss1.swap(ss2);
    cout << "after swap, ss1 ss2: "<< ss1 << " " << ss2 << endl;
}