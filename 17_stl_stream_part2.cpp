#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <complex>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstdlib>


// g++ -o 17_stl_stream_part2 17_stl_stream_part2.cpp
// ./17_stl_stream_part2
using namespace std;

int main()
{
        //覆写
     {
        ofstream of("MyLog17.txt", ios::out | ios::app); 
        //create a new file for write, if the file didn't exist, ios::out | ios::app : openmode read and write
        of << "Experience is the mother of wisdom" << endl;
        of << 234 << " " << 2.3 << endl;
        of << bitset<8>(14) << endl; //00001110
        of << complex<int>(2, 3) << endl; // (2, 3)
    } // RAII close file

     


    //追加写
    {
        ofstream of("MyLog17.txt", ofstream::app); //追加模式 <==> with open("MyLog18.txt", "a") as of
        of << "Honesty is the best policy." << endl;
    }


    //指定点写
    {
        ofstream of("MyLog17.txt", ofstream::in | ofstream::out);
        of.seekp(10, ios::beg); // move the output pointer 10 chars after begining
        of << "12345"; //OVERWRITE 5 chars
        of.seekp(-5, ios::end); //Move the output pointer 5 chars before end
        of << "Nothing ventured, nothing gained." << endl;
        of.seekp(-5, ios::cur); //Move the output pointer 5 chars before current position
    }

    system("start ./MyLog17.txt"); //打开生成的txt文档


    ifstream inf("MyLog17.txt");
    //inf.exceptions(ios::badbit | ios::failbit);
    int i;
    // char i; //good, because the file starts with a char
    inf >> i; // read one word: the first word is not int so this will result in an error
    //error status: goodbit, badbit, failbit, eofbit
    // inf.good(): Everything is OK (goodbit == 1)
    // inf.bad(): Non-recoverable error (badbit == 1)
    // inf.fail(): failed stream operation.(failbit == 1 badbit == 1)
    // inf.eof(): End of file (eofbit==1)
    cout << i << endl;
    cout << "inf.good(): " << inf.good() << endl; 
    cout << "inf.bad(): " << inf.bad() << endl;
    cout << "inf.fail(): " << inf.fail() << endl;
    cout << "inf.eof(): " << inf.eof() << endl;

    inf.clear();//clear all the error status ==> clear(ios::goodbit)
    inf.clear(ios::badbit);// sets a new value to the error flag , as bad() ⊂ fail() 
                          // so if bad() happens, fail() happens too

    cout << "new: " << endl;
    cout << "inf.good(): " << inf.good() << endl;
    cout << "inf.bad(): " << inf.bad() << endl;
    cout << "inf.fail(): " << inf.fail() << endl;
    cout << "inf.eof(): " << inf.eof() << endl;

    auto x = inf.rdstate(); // Read the current status flag


    //实现方法保证goodbit, failbit等的位长度相等比如可能是 0001， 0010，可以保证是4位但哪个表示goodbit不确定
    inf.clear( inf.rdstate() & ~ios::failbit); // clear only the failbit

    if (inf) //Equivalent to: if (!inf.fail())
    {
        cout << "Read successfully"<< endl;
    }

    if (inf >> i)
    {
        cout << "Read successfully"<< endl;
    }

    
    //Handle the errors with exceptions
    inf.exceptions(ios::badbit | ios::failbit); //setting the exception mask
    //When badbit or failbit set to 1, exception of ios::failure will be thrown
    //when eofbit set to 1, no exception will be thrown

 
    inf.exceptions(ios::goodbit); //means no exception will be generated 

}