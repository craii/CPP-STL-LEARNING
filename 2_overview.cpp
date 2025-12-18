#include <iostream>
#include <vector>
#include <algorithm>

// 编译运行命令
// g++ -o 2_overview 2_overview.cpp
// ./2_overview



using namespace std;

int main()
{


    vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); //vec: {4,1,8}
    vector<int>::iterator itr1 = vec.begin(); //左闭右开区间 [begin, end)
    vector<int>::iterator itr2 = vec.end();


    cout<< "iter1-->" << *itr1 << endl; //vec首位
    cout<< "iter2-->" << *itr2 << endl; //vec最后数据的下一位，是越界的，不安全，行为未定义

    // for (int i=0; i<n; i++){}对比其实一样
    for (vector<int>::iterator itr = itr1; itr !=itr2; ++itr)
    {
        cout<< *itr << " ";
    }

    cout<< "\n" << " ";

    sort(itr1, itr2); // from algorithm library

    for (vector<int>::iterator itr = itr1; itr !=itr2; ++itr)
    {
        cout<< *itr << " ";

    }

    // int a[] = {1,2,3,4};
    // for (int i: a){
    //     cout << i << endl;
    // }

    return 0;
}