#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <complex>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 16_stl_stream_part1 16_stl_stream_part1.cpp
// ./16_stl_stream_part1
using namespace std;

int main()
{
    //C++ Input/Output Library -- Stream
    cout << "Hello" << endl;
    // cout: a global object of ostream (typedef basic_ostream<char> ostream)
    //  << : ostream& ostream::operator<< (string v)
    // endl: '\n' + flush

    //what's stream? Serial IO Interface to external devices(file, stdin/stdout, network, etc)
    string s("Hello");
    s[3] = 't'; // random access
    cout << s << endl;

    {
        ofstream of("MyLog.txt"); //create a new file for write, if the file didn't exist
        of << "Experience is the mother of wisdom" << endl;
        of << 234 << " " << 2.3 << endl;
        of << bitset<8>(14) << endl; //00001110
        of << complex<int>(2, 3) << endl; // (2, 3)
    } // RAII

    //IO Operation:
    //formatting the data  <------> communicating the data with external devices

    //Software Engineer Principle: Low coupling
    

}






