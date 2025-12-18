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


// g++ -o 19_stl_stream_part4 19_stl_stream_part4.cpp
// ./19_stl_stream_part4
using namespace std;


ostream& endl(ostream& sm)
{
    //overwrite endl
    sm.put('-');
    sm.put('\n');
    sm.flush();
    return sm;
}

// ostream& ostream::operator<<(ostream& (*func)(ostream&))
// {
//     return (*func)(*this);
// } //不允许



int main()
{

    cout << "Hello" << endl; //endl: '\n' and flush
    //Endl is Object? Built-in data type?  No it's a free function
    cout << "World" << endl;

    cout << ends;
    cout << flush;
    cin >> ws;

    cout << setw(8) << left << setfill('_') << 99 << endl;//99

    cout << hex << showbase <<14 << endl ; //0xe

}