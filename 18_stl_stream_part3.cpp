#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <complex>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstdlib>


// g++ -o 18_stl_stream_part3 18_stl_stream_part3.cpp
// ./18_stl_stream_part3
using namespace std;

int main()
{
      
//formatting
//COUT
cout << 34 << endl; //34

cout.setf(ios::oct, ios::basefield); //this will set the standard out format to be oct number

cout << 34 << endl; //42 

cout.setf(ios::showbase); //显示进制
cout << 34 << endl; //042 

cout.setf(ios::hex, ios::basefield);
cout << 34 << endl; //0x22 

cout.unsetf(ios::showbase); //不显示进制
cout << 34 << endl; //22 

cout.width(10); //设置输出宽度,默认右对齐
cout.setf(ios::dec, ios::basefield);
cout << 26 << endl;

cout.setf(ios::left, ios::adjustfield);  // 设置左对齐
cout << 26 << endl;

//Floating point value
cout.setf(ios::scientific, ios::floatfield);
cout << 340.1 << endl; //3.401000e+02

cout.setf(ios::fixed, ios::floatfield);
cout << 340.1 << endl; //340.100000


cout.precision(3);
cout << 340.1 << endl; //340.100

//CIN
cin.setf(ios::hex, ios::basefield);
int i;
cin >> i ; // enter 12
cout << "i= " << i << endl; // i== 18

//flag
ios::fmtflags f = cout.flags(); // f用来 保存当前的输出格式参数
cout.flags(ios::oct | ios::showbase);//保存需要的格式

cout.flags(f);//恢复输出格式
{
// Member functions for unformatted IO
//input
ifstream inf1("MyLog17.txt");
char buf[80];
inf1.get(buf, 80); //read up to 80 chars and save into buf
inf1.getline(buf, 80); //read up to 80 chars or until '\n'
inf1.read(buf, 20); //read 20 chars
char c20[21];
inf1.read(c20, 20);
cout << " c20: \n";
for(char c: c20)
{
    cout << c << " ";
}
inf1.ignore(3); //忽略前3个字符
inf1.peek(); //看一眼下一个字符，但不读
inf1.unget(); //return a char back to the stream    inf.putback('z')//手动把 'z' 塞回流里，让下一个 get() 读到 'z'
inf1.get();
inf1.gcount(); //return the number of chars being read by last unformatted read
/*
inf1.gcount();
作用：
返回 上一次“非格式化读取”实际读了多少个字符
⚠️ 只对以下函数有意义：
get
getline
read
ignore
📌 对 peek() 无效
*/

//output
ofstream of("MyLog18.txt");
of.put('c');
of.write(buf, 6); //write first 6
}

system("start ./MyLog18.txt");


}