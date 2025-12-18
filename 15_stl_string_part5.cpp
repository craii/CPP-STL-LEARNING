#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 15_stl_string_part5 15_stl_string_part5.cpp
// ./15_stl_string_part5
using namespace std;

int main()
{

    //String and algorithms
    string s1 = "Variety is the spice of life.";
    int num = count(s1.begin(), s1.end(), 'e'); //4
    int num1 = count_if(s1.begin(), s1.end(), 
                        [](char c){return (c <= 'e') &&(c>='a');}
                    ); // 6
    cout << num << "-----" << num1 <<endl;
    string s2 = "Goodness is better than beauty";
    string::iterator itr = search_n(s2.begin(), s2.begin() + 20, 2, 's'); // 在前20个字符中查找 2个 连续的s
    cout << *(itr - 1) <<endl;

    s2.erase(itr, itr + 5);
    cout << s2 << endl; //Goodne better than beauty

    s2.insert(itr, 3, 'x');
    cout << s2 << endl; //Goodnexxx better than beauty
    
    //replace
    //s2.replace(itr1, itr2, n, 'c');
    //将s2的 itr1和itr2之间的字符，替换为 n 个 字符c 
    s2.replace(itr, itr+3, 3, 'y');
    cout << s2 << endl; //Goodneyyy better than beauty
    // s2.replace(itr, itr+3, 2, 'o');
    // cout << s2 << endl; //Goodneoo better than beauty
    // s2.replace(itr, itr+3, 10, 'A');
    // cout << s2 << endl; //Goodneoo better than beauty

    is_permutation(s1.begin(), s1.end(), s2.begin()); //判断两个序列（这里是s1, s2）是否是排列（置换）关系

    replace(s2.begin(), s2.end(), 'e', ' ');
    cout << s2 << endl; //Goodn yyy b tt r than b auty

    string s3;
    transform(s1.begin(), s1.end(), //source
              back_inserter(s3),//dest
              [](char c){
                if (c < 'n'){return 'a';}
                else{return 'z';}
              }
            );
    cout << s3 << endl; //aazaazzaazazaaazzaaaazaaaaaaa

    string s4 = "abcdefg";
    rotate(s4.begin(), s4.begin()+3, s4.end()); //defgabc
    cout << s4 << endl; //defgabc

    //other type
    // string s;
    // u16string s9;
    // u32string s8;
    // wstring s0;



}  



