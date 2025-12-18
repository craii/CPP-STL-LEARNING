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


// g++ -o 22_stl_stream_part7 22_stl_stream_part7.cpp
// ./22_stl_stream_part7
using namespace std;

//Create Stream-enabled Class
struct Dog
{
    int age_;
    string name_;

};

ostream& operator<<(ostream& sm, const Dog& d)
{
    sm << "My name is " << d.name_ <<" and my age is " << d.age_ << endl;
    return sm;
}

istream& operator>>(istream& sm, Dog& d)
{
    sm >> d.age_;
    sm >> d.name_;
    return sm;
}

int main()
{
    Dog d{2, "Bob"};
    cout << d;//My name is Bob and my age is 2


    cin >> d;
    cout << d;
    /*
        input: 20
        input: Alice
        My name is Alice and my age is 20 
    */
}