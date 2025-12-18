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
#include <random>


// g++ -o 9_algorithms-sorting 9_algorithms-sorting.cpp
// ./9_algorithms-sorting
using namespace std;

bool lsb_less(int x, int y)
{
    return (x%10)<(y%10);
}


bool lessThan10(int i)
{

    return i<10;
}

int main()
{
    /*
    Sorting in STL
    
    Sorting algorithm requires random access iterators:
    vector, deque, container array, native array
    
    */
    vector<int> vec{9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};
    sort(vec.begin(), vec.end()); // sort with operator <
    cout << "default sort" << endl;
    for(int i: vec)
    {
        cout << i << " ";
    }
    cout << endl;
    // vec : 1 2 3 4  5 8 9 9 10 45 90



    sort(vec.begin(), vec.end(), lsb_less);
    cout << "lsb sort" << endl;
    for(int i: vec)
    {
        cout << i << " ";
    }
    cout << endl;
    // vec : 10 90 1 2 3 4 【5 45】 8 9 9 
    // vec : 10 90 1 2 3 4 【45 5】 8 9 9  an outdated compiler may get result like this


    //Sometime we don't need complete sorting


    // Problem #1 Finding top 5 students according to their test scores

    //- Partial sort
    vector<int> scores{9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7};
    //partial_sort(scores.begin(), scores.begin() + N, ....); N个符合条件的元素找到之后，结束排序，后面不在管
    partial_sort(scores.begin(), scores.begin() + 5, scores.end(), greater<int>());
    cout << "partial_sort " << endl;
    for(int i: scores)
    {
        cout << i << " ";
    }
    cout << endl;
    // scores: 90 87 70 69 69 8 9 45 60 55 7


    //- Overloaded
    vector<int> scores1{9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7};
    partial_sort(scores1.begin(), scores1.begin() + 5, scores1.end()); //if no predecate is provided, less<T>() will be used
    cout << "partial_sort overloaded" << endl;
    for(int i: scores1)
    {
        cout << i << " ";
    }
    cout << endl;
    // scores1: 7 8 9 45 55 87 90 70 69 69 60


    // Problem #2: Finding top 5 students according to their score, but I don't 
    //care about their order
    vector<int> scores2{9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7};
    nth_element(scores2.begin(), scores2.begin() + 5, scores2.end(), greater<int>());
    cout << "nth_element: " << endl;
    for(int i: scores2)
    {
        cout << i << " ";
    }
    cout << endl;
    //scores2: 69 87 70 90 69 60 45 8 9 55 7


    // Problem #3: Move the students whose score is less than 10 to the front
    vector<int> scores3{9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7};
    
    partition(scores3.begin(), scores3.end(), lessThan10);
    cout << "partition: " << endl;
    for(int i: scores3)
    {
        cout << i << " ";
    }
    cout << endl;
    //scores3: 9 7 8 70 45 87 90 69 69 55 60


    // To preserve the original order within each partition
    vector<int> scores4{9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7};
    stable_partition(scores4.begin(), scores4.end(), lessThan10);
    cout << "partition: " << endl;
    for(int i: scores4)
    {
        cout << i << " ";
    }
    cout << endl;
    //scores4: 9 8 7 60 70 45 87 90 69 69 55 

    // Heap Algorithms
    //
    // Heap:
    // 1. First element is always the largest
    // 2. Add/remove take O(log(n)) time

    vector<int> vec_h{9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};
    make_heap(vec_h.begin(), vec_h.end());
    cout << "make heap vec_h: " << endl;
    for(int i: vec_h)
    {
        cout << i << " ";
    }
    cout<<endl;
    // 90 45 10 9 8 3 9 4 2 5 1

    // Remove the largest element:
    pop_heap(vec_h.begin(), vec_h.end());// 1. swap vec[0] with last item vec[size - 1]
                                         // 2. Heapify [vec.begin(), vec.end() - 1]
    cout << "pop_heap: " << endl;
    for(int i: vec_h)
    {
        cout << i << " ";
    }
    cout<<endl;
    // 45 9 10 4 8 3 9 1 2 5 90

    vec_h.pop_back(); //Remove the last item ( in this case : 90)
    for(int i: vec_h)
    {
        cout << i << " ";
    }
    cout<<endl;
    //45 9 10 4 8 3 9 1 2 5


    // Add new element:
    vec_h.push_back(100); //45 9 10 4 8 3 9 1 2 5
    cout << "add new element to vec_h :" <<endl;
    for(int i: vec_h)
    {
        cout << i << " ";
    }
    cout<<endl;

    push_heap(vec_h.begin(), vec_h.end()); //heapify the last item in vec
    for(int i: vec_h)
    {
        cout << i << " ";
    }
    cout<<endl;


    //Heap Sorting:
    //Note: sort_heap can be applied to a heap only
    //如果要加predicate，那么make_heap/sort_heap的predicate必须一致  
    vector<int> vec_h1{9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};
    make_heap(vec_h1.begin(), vec_h1.end());

    sort_heap(vec_h1.begin(), vec_h1.end());
    cout << "Heap Sorting:" <<endl;
    for(int i: vec_h1)
    {
        cout << i << " ";
    }
    cout<<endl;
    //1 2 3 4 5 8 9 9 10 45 90

    


}