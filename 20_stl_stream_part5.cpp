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


// g++ -o 20_stl_stream_part5 20_stl_stream_part5.cpp
// ./20_stl_stream_part5
using namespace std;

int main()
{

//IO operation
//formatting data --stream
//communicating data to external devices --stream buffer

cout << 34;
streambuf* pbuf = cout.rdbuf();

ostream myCout(pbuf);
myCout << 34; //34 to stdout

myCout.setf(ios::showpos);
myCout.width(20);
myCout << 12 << endl; //       +12
cout << 12 << endl; //12


ofstream of("MyLog20.txt");
streambuf* origBuf = cout.rdbuf();
cout.rdbuf(of.rdbuf());
cout << "Hello" << endl; //MyLog20.txt has "Hello"
//Redirecting

cout.rdbuf(origBuf);
cout << "Goodbye" << endl; //stdout: Goodbye

//Stream buffer iterator
istreambuf_iterator<char> i(cin);
ostreambuf_iterator<char> o(cout);
while(*i !='x')
{
    *o = *i;
    ++o;
    ++i;
}

copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostream_iterator<char>(cout));

}