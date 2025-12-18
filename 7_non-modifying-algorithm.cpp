#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <map>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>


// g++ -o 7_non-modifying-algorithm 7_non-modifying-algorithm.cpp
// ./7_non-modifying-algorithm 
using namespace std;



bool lessThan10(int x){return x<10;}


int main()
{
    /*
    STL Algorithm Walkthrough
        Non-modifying Algorithms
        count, min and max, compare, linear search, attribute 
    */

    vector<int> vec{1, 2, 3, 4, 5, 10, 11, 12};
    auto num = count_if(vec.begin(), vec.end(), [](int x){return x<10;});

    cout << "count vec: "<< num << endl; //5


    vector<int> vec1{9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7   , 45, 87, 90, 91};// , 45, 87, 90, 91 后续补充以便后续代码明显区分
    vector<int> vec2{9, 60, 70, 8, 45, 87};
    vector<int>::iterator itr, itr1, itr2;
    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;

    //C++ 03: some algorithms can be found in tr1 or boost
    //1. COUNTING
    int n = count(vec1.begin(), vec1.end(), 69); //2
    int m = count_if(vec1.begin(), vec1.end(), [](int x){return x<10;});//3
    cout<<"count 69s in vec1 : " << n << endl;
    cout<<"count nums less than 10 in vec1 : " << m << endl;

    //2.MIN AND MAX
    itr = max_element(vec1.begin()+2, vec1.end());//90
    // it returns first max value iterator
    //cout << *itr << endl; //90
    itr1 = max_element(vec1.begin(), vec1.end(), [](int x, int y){return (x%10) < (y%10);}); //9
    cout << *itr1 << endl; //9
    //Most algorithms have a simple form and a generalized form

    itr2 = min_element(vec1.begin(), vec1.end()); //7
    cout<<"min in vec1 : " << *itr2 << endl;

    pair_of_itr = minmax_element(vec1.begin(), vec1.end(), [](int x, int y){return (x%10) < (y%10);});
    // return a pair instance, which containers first of min and second of max
    cout<<"min in vec1 : " << *(pair_of_itr.first) << " max in vec1 :" << *(pair_of_itr.second) <<endl;

    //3. LINEAR SEARCH (used when data is not sorted)
    // return the first match
    vector<int>::iterator f_itr, f_itr1, f_itr2, s_itr1, s_itr2, s_itr3;
    f_itr = find(vec1.begin(), vec1.end(), 55);
    cout << *f_itr << endl; // iterator points to the first match

    f_itr1 = find_if(vec1.begin(), vec1.end(), [](int x){return x>80;});

    f_itr2 = find_if_not(vec1.begin(), vec1.end(), [](int x){return x>80;});

    s_itr1 = search_n(vec1.begin(), vec1.end(), 2, 69);// consecutive 2 item of 69返回连续2个69的起始地址
    // 返回连续n个元素m的起始地址
    //generalized form: search_n()
    cout << "sequence starts at: "<< *s_itr1 << endl; 

    //search subrange //在vec1中搜索是否存在子序列sub,如果存在，则返回首个匹配序列的起始地址
    //vector<int> vec1{9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7   , 45, 87, 90, 91}; // , 45, 87, 90,91 后续补充以便明显区分
    vector<int> sub{45, 87, 90};
    s_itr2 = search(vec1.begin(), vec1.end(), sub.begin(), sub.end()); //search first subrange
    s_itr3 = find_end(vec1.begin(), vec1.end(), sub.begin(), sub.end());//search last subrange
    cout << "search first range "<< *(s_itr2 - 1) << endl; //首个子序列起始地址的前一位
    cout << "search last range "<< *(s_itr3 - 1 ) << endl; //最后子序列起始地址的前一位

    //search any_of
    vector<int> items{87, 69};
    vector<int>::iterator itr_of1, itr_of2, itr_of3, itr_of4;
    itr_of1 = find_first_of(vec1.begin(), vec1.end(), items.begin(), items.end());
            //Search any one of the item in items
    cout << "find items" << *itr_of1 << endl; // return the first capable items address

    itr_of2 = find_first_of(vec1.begin(), vec1.end(), items.begin(), items.end(), 
                [](int x, int y){ return x==y*4 ;});  //x来自vec1, y来自items，x==y*4 ：判断vec1中某个元素是否恰好等于items中某个元素的4倍
            //Search any one of the item in items that satisfy: x==y*4
    cout << "find items satisfy condition : " << *itr_of2 << endl; // return the first capable items address

    //search adjacent
    itr_of3 = adjacent_find(vec1.begin(), vec1.end());//find 2 adjacent items that are the same

    itr_of4 = adjacent_find(vec1.begin(), vec1.end(),
                            [](int x, int y){return x==y-1;});
        //find 2 adjacent items that satisfy: x==y*4; x为首个元素， y为x下一个元素

    cout << "find adjacent same items :" << *itr_of3 << endl; //69
    cout << "find adjacent same items satisfy condition x==y-1 :" << *itr_of4 << endl; //90


    //4. COMPARING RANGES
    vector<int> vec_e1{1,2,3,4}, vec_e2{1,2,3,4}, vec_e3{3,2,1,4};

    //判断vec_e1和vec_e2是否一致(元素一致，顺序一直)
    if (equal(vec_e1.begin(), vec_e1.end(), vec_e2.begin()))
    {
        cout << "vec and vec2 are same" << endl;
    }

    //判断vec_e1和vec_e2是否一致(元素一致，顺序不一致)
    if (is_permutation(vec_e1.begin(), vec_e1.end(), vec_e3.begin()))
    {
        cout << "vec_e1 and vec_e3 have the same items, but in different order .\n";
    }

    vector<int> vec_e4{1,2,3,4,5,6,7,8,9}, vec_e5{1,2,3,4,10,5,6,7,8,9};
    pair_of_itr = mismatch(vec_e4.begin(), vec_e4.end(), vec_e5.begin());
    //找到两个容器中首此出现不一致的位置，并标记出来，
    // find the first diffence
    //pair_of_itr.first is an iterator of vec_e4
    //pair_of_itr.second is an iterator of vec_e5
    cout << "output of pair_of_itr, first :"<< *(pair_of_itr).first << "---second " << *(pair_of_itr).second << endl;

    //lexicographical comparison: one-by-one comparion with "LESS THAN"
    //vec_e1{1,2,3,4},  vec_e3{3,2,1,4};
    bool result = lexicographical_compare(vec_e1.begin(), vec_e1.end(), vec_e3.begin(), vec_e3.end());
    // {1,2,3,4} < {1,2,4,3} 'cause 4>3
    // {1,2,3,4} > {1,2,2,3} 'cause 3>2
    // {1,2,3,4} < {3,2,1,4} 'cause 3>1
    // {1, 2} < {1, 2, 3}  'cause 3 > null
    if (result){
        cout << "FIRST IS Less than SECOND" << endl;
    }
    else
    {
        cout << "FIRST IS Greater than SECOND" << endl;
    }

    //generalized forms:
    // equal(), is_permutation(), mismatch(), lexigraphical_compare()


    //5. CHECK ATTRIBUTES
    //IS_SORTED
    bool r1 = is_sorted(vec_e1.begin(), vec_e1.end()); // check if vec is sorted : true 1
    bool r2 = is_sorted(vec_e3.begin(), vec_e3.end()); // check if vec is sorted : false 0

    cout << "is_sorted()" << r1 << " " << r2 << endl;


    //IS_SORTED_UNTIL 
    //vec_e5{1,2,3,4,10,5,6,7,8,9} --> 10
    vector<int>::iterator itr_sorted = is_sorted_until(vec_e5.begin(), vec_e5.end());
    //itr_sorted points to first place to where elements are no longer sorted
    //generalize forms: is_sorted(), is_sorted_until()
    cout << "is_sorted_untill " << *itr_sorted << endl; // 5 , 1~10都是升序

    vector<int> v1{1,1,1,3,3,3}, v2{76,1, 2, 81, 87, 100}, v3{1,1,1,3,3,3,3};
    bool is_parted_v1 = is_partitioned(v1.begin(), v1.end(), [](int x){ return x<2;});
    // 1 1 1 3 3 3
    // F F F T T T   ← predicate(x) = (x > 2) 
    //               //这种序列是不行的，不能是从F -> T， 必须从T->F
    // 1 1 1 3 3 3
    // T T T F F F   ← predicate(x) = (x < 2) 
    //               //这种序列 OK，不能是从F -> T， 必须从T->F
    //需要注意lambda函数的写法，确保符前(半[不一定要精准一半])部分保持为true，后半部分为false
    cout << is_parted_v1 << endl;
    bool is_parted_v2 = is_partitioned(v3.begin(), v3.end(), [](int x){ return x<2;});
    cout << is_parted_v2 << endl;

    //IS_HEAP
    // USED VEC: v2{76,1, 2, 81, 87, 100}
    bool i_heap = is_heap(v2.begin(), v2.end()); //check is vec is a heap
    cout << "the selected vector is heap? -->"<< i_heap << endl;

    vector<int>::iterator itr_heap = is_heap_until(v2.begin(), v2.end()); 
    cout << "the selected vector is no longer heap untill? -->"<< *itr_heap << endl; //find the first place where it 
                                                                                    //is no longer a heap
    //generalized forms: is_heap(), is_heap_until()

    

}