#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <random>
#include <numeric>


// g++ -o 10_sorted-data-algorithms-and-numeric-algorithms 10_sorted-data-algorithms-and-numeric-algorithms.cpp
// ./10_sorted-data-algorithms-and-numeric-algorithms
using namespace std;

int main()
{
/*
Sorted data algorithms
    - Algorithms that require data being pre-sorted
    - Binary search, merge, set operations
*/
//Note: Every sorted data algorithm has a generalized form with a same name.

    vector<int> vec{8, 9, 9, 9, 45, 87, 90}; //7 items
    //1. Binary search
    // Search Elements
    bool found = binary_search(vec.begin(), vec.end(), 9); // check if 9 is in vec
    //cout << found << endl;
    if (found)
    {
        cout << "Found !";
    }
    cout<<endl;

    vector<int> s{9, 45, 66};
    bool found_s = includes(vec.begin(), vec.end(), //range to search
                            s.begin(), s.end()); // range of search query
    //Return true if ALL ELEMENTS of s is included in vec
    // !!!!!!!Both vec and s MUST BE SORTED!!!
    cout << "is s{9, 45, 66} found in vec? --> " << found_s << endl;

    vector<int> s1{45, 87, 90};
    bool found_s1 = includes(vec.begin(), vec.end(), //range to search
                            s1.begin(), s1.end()); // range of search query
    
    cout << "is s{45, 87, 90} found in vec? --> " << found_s1 << endl;


    // Search Position
    //lower_bound() find the first position where 9 could be inserted and still keep the sorting
    auto itr_begin = lower_bound(vec.begin(), vec.end(), 9); //vec[1]
    int index_b = itr_begin - vec.begin();
    cout << index_b << endl;


    //upper_bound() find the last position where 9 could be inserted and still keep the sorting
    auto itr_end = upper_bound(vec.begin(), vec.end(), 9); //vec[4]
    int index_e = itr_end - vec.begin();
    cout << index_e << endl;

    // return both first and last position in pair
    pair<vector<int>::iterator, vector<int>::iterator> itr_range = equal_range(vec.begin(), vec.end(), 9);
    cout << "begin: "<< itr_range.first - vec.begin() << endl;
    cout << "end: "<< itr_range.second - vec.begin() << endl;


    //2. Merge
    vector<int> vec_m{8, 9, 9, 10}, vec_m2{7,9,10}, vec_mo;
    merge(vec_m.begin(), vec_m.end(), //input range #1
          vec_m2.begin(), vec_m2.end(), // input range #2
          back_inserter(vec_mo) // destination
        );
    // Both of vec_m and vec_m2 should be sorted (same for the set operation)
    // Nothing is dropped , all duplicates are kept.
    cout << "Test merge "<< endl;
    for (int i: vec_mo)
    {
        cout << i << " "; // 7 8 9 9 9 10 10
    }
    cout<<endl;


    vector<int> vec_im{1, 2 ,3 ,4, 1, 2, 3, 4, 5}; //Both part of vec_im are already sorted
    inplace_merge(vec_im.begin(), vec_im.begin() + 4, vec_im.end());
    //首先，容器con要由两个已经排序的部分组成{sorted_partA, sorted_partB}, con.begin() + N 此处N为4
    //需要指到 sorted_partB的起始位置， 可参考 rotate() 
    //vec_im {1, 1, 2, 2, 3, 3, 4, 4, 5} -one step of merge sort


    // 3. set operation
    //  - Both vec and vec3 should be sorted
    //  - The resulted data is also sorted

    //UNION 并集 A ∪ B
    vector<int> vec_s{8, 9, 9, 10};
    vector<int> vec_s1{7, 9, 10};
    vector<int> vec_so(5); 
    set_union(vec_s.begin(), vec_s.end(), //input range #1
              vec_s1.begin(), vec_s1.end(), // input range #2
              vec_so.begin()); //output
    cout << "set_union "<< endl;
    for (int i: vec_so)
    {
        cout << i << " "; //7 8 9 9 10
    }                    // if X is in both vec_s and vec_s1, only one X is kept in vec_so  
    cout<<endl;

    //INTERSECTION 交集 A ∩ B
    vector<int> vec_its{8, 9, 9, 10};
    vector<int> vec_its1{7, 9, 10};
    vector<int> vec_itso(5); 
    //取交集
    set_intersection(vec_its.begin(), vec_its.end(), //input range #1
                    vec_its1.begin(), vec_its1.end(), // input range #2
                    vec_itso.begin()); //output);
    cout << "set_intersection "<< endl;
    for (int i: vec_itso)
    {
        cout << i << " "; //vec_out {9, 10, 0,0,0}
    }                    // only the items that are in both vec_its and vec_its1 are seved in vec_itso
    cout<<endl;
    //cout << vec_itso.size() << " " << vec_itso.capacity() << endl;


    //SET_DIFFERENCE 差集 A - B 
    vector<int> vec_sd{8, 9, 9, 10}, vec_sd2{7, 9, 10}, vec_sdo, vec_sdo1;
    set_difference
    (vec_sd.begin(), vec_sd.end(), //Set input #1
     vec_sd2.begin(), vec_sd2.end(),//Set input #2
     back_inserter(vec_sdo) //set output
    );
    cout <<"set_difference: " << endl;
    for(int i: vec_sdo)
    {
        cout << i << " "; // 8 9
    }
    cout<<endl;



    //SET_SYMMETRIC_DIFFERENCE 对称差集 (A-B) ∪ (B - 1)
    set_symmetric_difference
    (vec_sd.begin(), vec_sd.end(), //Set input #1
     vec_sd2.begin(), vec_sd2.end(),//Set input #2
     back_inserter(vec_sdo1) //set output
    );
    cout <<"set_symmetric_difference: " << endl;
    for(int i: vec_sdo1)
    {
        cout << i << " "; // 7 8 9
    }
    cout<<endl;


    /*
    Numeric Algorithms (in #include <numeric>)
    - Accumulate, inner product, partial sum, adjacent difference
    */

    vector<int> vec_ac{1, 2 ,3, 4, 5};
    // 1. Accumulate
    int r1 = accumulate(vec_ac.begin(), vec_ac.end(), 10);
    // 10 + vec_ac[0] + vec_ac[1] + ... +

    int r2 = accumulate(vec_ac.begin(), vec_ac.end(), 0);
    //python sum(vec_ac)

    int r3 = accumulate(vec_ac.begin(), vec_ac.end(), 10, multiplies<int>());
    // 10 * vec_ac[0] * vec_ac[1] * ... *
    cout << "vec_ac{1, 2 ,3, 4, 5}" << endl;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;

    
    // 2. Inner Product
    vector<int> vec_ip = {9, 60, 70};
    vector<int> vec_ip1 = {9, 60, 70};

    int ip1 = inner_product(vec_ip.begin(), vec_ip.end(), // range #1
                            vec_ip1.begin(), //range #2
                            0); // init value
    // 0 + vec_ip[0] * vec_ip1[0] + vec_ip[1] * vec_ip1[1] + ... + 
    cout << "inner product of {9, 60, 70} and {9, 60, 70} " << endl;
    cout << "dot: " << ip1 << endl;
    
    
    vector<int> vec_ip2 = {1, 2, 3};
    vector<int> vec_ip3 = {1, 2, 3};

    //Inner Product complete form
    int ip2 = inner_product(vec_ip2.begin(), vec_ip2.end(), // range #1
                            vec_ip3.begin(), //range #2
                            10,// init value
                            multiplies<int>(), // 累积方式
                            plus<int>() // vec_ip2 vec_ip3 相同位置元素计算的组合方式
                        ); 
    // 10 + (vec_ip[0] + vec_ip1[0]) * (vec_ip[1] + vec_ip1[1]) * ... *
    //从init value 累积方式  vec_ip2 vec_ip3 相同位置元素计算的组合方式 可以看出， inner product
    //的实现方式 和 reduce 函数类似
    cout << "inner product of {9, 60, 70} and {9, 60, 70} " << endl;
    cout << "dot2: " << ip2 << endl; 


    // 3. Partial Sum
    /*
      partial_sum 的作用
        给定一个输入序列，它会输出：
        第 1 个元素：原序列第 1 项
        第 2 个元素：原序列前 2 项的和
        第 3 个元素：原序列前 3 项的和
        ……
    */
    vector<int> vec_ps{1, 2, 3}, vec_pso, vec_pso1;
    //vec_ps[0] =  vec_ps[0]
    //vec_ps[1] =  vec_ps[0] + vec_ps[1]
    //vec_ps[2] =  vec_ps[0] + vec_ps[1] + vec_ps[1]
    partial_sum(vec_ps.begin(), vec_ps.end(), //input
                back_inserter(vec_pso));//output
    cout << "partial_sum of {1, 2, 3} " << endl;
    for(int i: vec_pso)
    {
        cout << i << " "; //1 3 6
    }
    cout<<endl;

    //general form
    partial_sum(vec_ps.begin(), vec_ps.end(),
                back_inserter(vec_pso1),
                multiplies<int>()
                );
    cout << "partial_sum of {1, 2, 3} with predicate multiplies<in>() " << endl;
    for(int i: vec_pso1)
    {
        cout << i << " ";  //1 2 6
    }
    cout<<endl;

    //4. Adjacent Difference
    /*
      Adjacent Difference 的作用
        给定一个输入序列，它会输出：
        第 1 个元素：原序列第 1 项
        第 2 个元素：原序列第 2 项 - 原序列第 1 项
        第 3 个元素：原序列第 3 项 - 原序列第 2 项
        ……
    */
    vector<int> vec_ad{2, 3, 4}, vec_ado, vec_ado1;
    adjacent_difference(vec_ad.begin(), vec_ad.end(),
                        back_inserter(vec_ado)
                    );
    cout << "adjacent_difference of {2, 3, 4} " << endl;
    for(int i: vec_ado)
    {
        cout << i << " "; // 2 1 1
    }
    cout<<endl;  


    //general form
    adjacent_difference(vec_ad.begin(), vec_ad.end(),
                    back_inserter(vec_ado1),
                    plus<int>()
                );
    cout << "adjacent_difference of {2, 3, 4} , with predicate plus<int>()" << endl;
    for(int i: vec_ado1)
    {
        cout << i << " "; //2 5 7
    }
    cout<<endl;  
    





}






