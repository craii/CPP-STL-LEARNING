#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>


//g++ -o 3_sequence_containers 3_sequence_containers.cpp
//./3_sequence_containers
using namespace std;


int main()
{
    // VECTOR （单向项链）
    /* Properties of Vector:
     * 1. fast insert/remove at the end; O(1)
     * 2. slow insert/remove at the begining or in the middle; O(n)
     * 3. slow search: O(n);
     */

    cout << "******VECTOR SESSION BEGINS******" << endl;
    vector<int> vec{4, 1, 8};

    cout << vec[2] <<" "; //无边界检查
    cout << vec.at(2) << endl; //有边界检查；越界会报错


    cout << "size version for loop" << endl;
    for (int i=0; i < vec.size(); i++)
    {
        //cout << vec[i] << endl;
        cout << vec.at(i) << endl;
    }

    cout << "iterator version for loop" << endl; //所有容器都推荐如此迭代，而且这种方法通常较其他迭代方法快
    for (vector<int>::iterator itr=vec.begin(); itr != vec.end(); ++itr)
    {
        cout << *itr << endl;
    }

    cout << "vector version for loop (c++ 11)" << endl;
    for(auto it: vec)
    {
        cout<< it << endl;
    }


    //Vector 在内存中是连续的，它占用一段连续的内存
    int* p = &vec[0];
    //指针读取
    cout << "read by pointer" << endl;
    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << *(p + 2) << endl;

    //common member function of all containers;
    //vec{4,1,8}
    if (vec.empty()) //判断是否是空的
    {
        cout << "vector is empty\n";
    } 
    else
    {
        cout << "vector is NOT empty\n";
    }

    //输出vec大小
    cout << "vec's size is : "<< vec.size() << endl;

    //vector的构造函数提供快速复制vec的方法
    vector<int> vec2(vec); // copy the data of vec{4,1,8} to vec2
    cout << "copy data from vec1 to vec2\n";
    for(vector<int>::iterator itr=vec2.begin(); itr != vec2.end(); ++itr)
    {
        cout << *itr << endl;
    }

    vec.clear();
    if (vec.empty())
    {
        cout << "success!! VEC1 is empty\n";
    }

    vec2.swap(vec); //vec2 is empty now and vec gets 3 items {4,1,8}
    if (vec2.empty())
    {
        cout << "success!! VEC2 is empty\n";
    }

    cout << "******VECTOR SESSION ENDS******" << endl;
    cout << "******                   ******" << endl;
    cout << "******DEQUE SESSION BEGINS******" << endl;

    //DEQUE (双向向量)
    /*deque properties
     * 1. deque can grow both at the begining or the end, double size growable
     * 2. fast insert/remove at the end and begining; O(1)
     * 3. slow insert/remove in the middle; O(n)
     * 4. slow search: O(n);
     */
    deque<int> deq{4, 6, 7};
    deq.push_front(2); //{2, 4, 6, 7}
    deq.push_back(3); //{2, 4, 6, 7,3}

    cout << deq[1] << endl;
    cout << deq[0] << endl;

    cout << "******DEQUE SESSION ENDS******" << endl;

    cout << "******                   ******" << endl;
    cout << "******LIST SESSION BEGINS******" << endl;
    
    //LIST（双向列表）
    /*LIST properties
     * aka double linked list
     * 1. fast insert/remove at any place:O(1)
     * 2. slow search:O(n)
     * 3. no random access, no [] operator. 
     */
    
    list<int> mylist{5, 2, 9};
    mylist.push_back(6); // {5, 2, 9, 6}
    mylist.push_front(4);// {4, 5, 2, 9, 6}


    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -->2 注意这里的2不是下标，而是list中第一个值为2的元素的 “指针”
    mylist.insert(itr, 8); // mylist: {4, 5, 8, 2, 9, 6}
                          //O(1), faster than vector/deque
    itr++;//itr -->9
    cout << "itr now is :" << *itr << endl;

    mylist.erase(itr);

    cout << "print remained item it mylist\n";
    for(list<int>::iterator itr=mylist.begin(); itr != mylist.end(); ++itr)
    {
        cout << *itr << endl;
    }

    list<int> mylist1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    list<int>::iterator itr_insert = find(mylist1.begin(), mylist1.end(), 3);
    // list<int>::iterator itr_s = find(mylist.begin(), mylist.end(), 0);
    // list<int>::iterator itr_e = find(mylist.begin(), mylist.end(), mylist.);
    
    
    mylist1.splice(itr_insert, mylist, mylist.begin(), mylist.end());
    /*mylist1.splice(itr_insert, mylist, itr1，itr2);
     *splice将mylist中itr1到itr2（这里是，mylist.begin()和 mylist.end()）的所有数据插到 
     *mylist1的 itr_insert的位置，后面再跟上mylist1从itr_insert代mylist1.end()的所有数据 
    */
    cout << "print MYLIST1" << endl;
    for (auto i: mylist1)
    {
        cout<< i << " ";
    }
    //1 2 4 5 8 2 6 3 4 5 6 7 8 9 10 bu 1 2 3 4, 5, 8, 2, 9, 6
    cout << "******LIST SESSION ENDS******" << endl;




    cout << "******                   ******" << endl;
    cout << "******ARRAY SESSION BEGINS******" << endl;
    
    //FORWARD LIST 
    /*FORWARD LIST properties
     *double linked list（单向列表）
     * 1. fast insert/remove at any place:O(1)
     * 2. slow search:O(n)
     * 3. no random access, no [] operator. 
     */

    forward_list<int> test{9,9,9};
    cout << "forward_list items" << endl;
    for(int i: test)
    {
        cout << i << endl;
    }

    
    //ARRAY
    //int a[3] = {3, 4, 5};
    array<int, 3> a = {3, 4, 5};
    array<int, 3> b = {1, 2, 3};
    // a.begin();
    // a.end();
   
    cout << " a.size() :" <<  a.size() << endl;

    a.swap(b);

    for (int i: a){
        cout << i << endl;
    }

    for (int i: b){
        cout << i << endl;
    }
    

    cout << "******ARRAY SESSION ENDS******" << endl;

    return 0;
}