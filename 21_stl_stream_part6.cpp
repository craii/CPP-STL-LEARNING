#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <complex>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <iomanip>


// g++ -o 21_stl_stream_part6 21_stl_stream_part6.cpp
// ./21_stl_stream_part6
using namespace std;

int main()
{
//String Stream
    stringstream ss; //Stream without IO operation
    //read/write of string
    ss << 89 << "  Hex:  " << hex << 89 << "  Oct:  "<< oct << 89;
    cout << ss.str() << endl;

    int a,b,c;
    string s1;
    ss >> hex >> a; //formatted input works token by token. spaces, tabs, newlines
    //a == 137
    cout << "a: "<< a <<endl;

    ss >> s1; //s1:"Hex:"
    cout << "s1: "<< s1 <<endl;

    ss >> dec >> b; //b==59
    cout << "b: "<< b <<endl;

    ss.ignore(6);
    
    ss >> oct >> c; //c==89
     cout << "c: "<< c <<endl;
    //ostringstream -- formatted output
    //istringstream -- formatted input

}