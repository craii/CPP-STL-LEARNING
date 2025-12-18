#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 13_stl_string_part3 13_stl_string_part3.cpp
// ./13_stl_string_part3
using namespace std;

int main()
{
    // Member function Algorithms: copy, find, compare

    string s1 = "abcdefg";
    char buf[20];
    buf[19] = 'j';

    size_t actual_len = s1.copy(buf, 3); // copy 3 characters from s1 to buf (从头部插入)
    //std::string::copy 有可能复制不到 count(这里是 3) 个字符，所以 返回值actual_len是必要的
    cout << "len of actual copied: " << actual_len << endl;
    for(int i=0; i<sizeof(buf); i++)
    {
        cout << buf[i] << endl; //会正常显示 a b c [不确定的垃圾数据] j
    }

    char buf1[20];
    size_t actual_len1 = s1.copy(buf1, 4, 2); // copy(target char *p, size, start position)

    cout << "fix copy size and start index " << actual_len << endl;
    for(int i=0; i<sizeof(buf1); i++)
    {
        cout << buf1[i] << endl; //会正常显示 a b c [不确定的垃圾数据] j
    }

    string s2 = "If a job is worth doing, it's worth doing well";
    size_t found = s2.find("doing"); // found == 17
    cout << "found index" << endl;
    cout << s2[found] << endl; //d

    found = s2.find("doing", 20); //found == 35 从 下标20开始找
    cout << "found from certain index, here from 20 " << endl;
    cout << s2[found - 2] << endl; //h

    found = s2.find("doing well", 0); // found 35
    found = s2.find("doing well", 0, 5); // found 35 // 从s2的开始(index==0)开始找"doing well"的前5个字符


    //str1.find_first_of(str2), 从str1中找到第一个出现在str2中的【character】的下标x (str1[x]) 
    // 注意 find_first 和 find_first_of 在语义上的差别即可轻易理解
    found = s2.find_first_of("doing"); //found ==6 
    found = s2.find_first_of("doing", 10); //found == 12 从下标10开始开始查找
    found = s2.find_first_of("doing", 10, 1); //found ==12 从下标10开始开始查找, 仅找第一个参数“doing”的第一个字符d

    //参考上方注释
    found = s2.find_last_of("doing"); // found = 39
    found = s2.find_first_not_of("doing"); // found = 0
    found = s2.find_last_of("doing"); // found = 44

    string s3 = "If a job is worth doing, it's worth doing well";
    int is_eq = s2.compare(s3); // return positive if (s2  > s3), negetive if (s2  < s3); 0 if (s2  == s3),
    //完全相等 用 == ， 排序比较用 compare
    // if (s2 > s3){} // if s2.compare(s3) > 0



}

