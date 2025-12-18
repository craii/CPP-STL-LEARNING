#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 14_stl_string_part4 14_stl_string_part4.cpp
// ./14_stl_string_part4
using namespace std;

int main()
{

    //Non-member function

    //string s1 = "If a job is worth doing, it's worth doing well";
    string s1;
    //cout << s1 << endl;
    cin >> s1;
    getline(cin, s1); // defaul delimeter of "\n"
    getline(cin, s1, ';'); // delimeter is ';'


    //convert a number into a string
    s1 = to_string(9);
    s1 = to_string(2.3e7);
    s1 = to_string(0xa4); // 164
    s1 = to_string(034); // 28


    //conver string into a number
    s1 = "190";
    int i = stoi(s1);
    //stol, stod, stof, etc

    // stringstream
    // lexical_cast()



}  



