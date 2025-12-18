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

using namespace std;

// g++ -o 5_unordered_associative_container 5_unordered_associative_container.cpp
// ./5_unordered_associative_container


void print_unordered_map(const unordered_map<char, string>& m, char key)
{
    //cout << m['s'] << endl; // will NOT compile;因为右值操作['S'] 会被编译器认为想要修改
    auto itr = m.find(key);
    if (itr != m.end())
    {
        cout << "unordered_map key is " << (*itr).first << endl;
        cout << "unordered_map value is " << (*itr).second << endl;
    }
}


void Myfunction(const int int_element)
{
    cout << int_element << endl;
}

bool isOdd(int i)
{
    return i % 2;
}


int main()
{
    //UNORDER_SET
    /*

    */
    cout << "******UNORDER_SET SESSION BEGINS******" << endl;
    unordered_set<string> myset{"red", "green", "blue"};
    unordered_set<string>::iterator itr = myset.find("green"); //O(1)
    if (itr != myset.end()) //important check
    {
        cout << *itr << endl;
    }
    myset.insert("yellow"); //O(1)

    //从其他stl容器插入
    vector<string> vec = {"purple", "pink"};
    myset.insert(vec.begin(), vec.end());

    list<string> mylist{"yellow", "cyan"}; 
    myset.insert(mylist.begin(), mylist.end());

    // for (string s: myset)
    // {
    //     cout << s << endl;
    // }

    // Hash table specific APIs
    cout << "load_factor = " << myset.load_factor() << endl;
    string x = "red";
    cout << x << " is in bucket #" << myset.bucket(x) << endl;
    cout << "Total bucket #" << myset.bucket_count() << endl;
    /*
    bucket_count()	当前哈希表有多少个桶
    bucket(key)	某个 key 落在哪个桶
    load_factor()	= size() / bucket_count() // < 1 为好
    max_load_factor()	超过这个值会 rehash
    rehash(n)	强制调整桶到 n 个以上
    reserve(n)	保证可以容纳 n 个元素（更自动化的 rehash）
    
    */

    //unordered multiset: unordered set that allows duplicated elements
    //unordered map: unordered set of pairs
    //unordered multimap: unordered map that allows duplicated keys

    //hash collision => performance degrade
    cout << "******UNORDER_SET SESSION ENDS******" << endl;
    cout << "******                   ******" << endl;


    //UNORDERED MAP
    /*
     *  Associative Array
     *  - map and unordered map
    */
   unordered_map<char, string> day{{'S', "Sunday"}, {'M', "Monday"}};
   cout << day['s'] << endl;
   cout << day.at('s') << endl;

   vector<int> vec2 = {1, 2, 3};
   //vec[5] = 5 ; // compile error; 

   day['W'] = "Wednesday"; // insert {'W',"Wednesday"} 

   pair<char, string> Fri('F', "Friday");
   day.insert(Fri);

   day.insert(make_pair('M', "MONDAY"));//Fail to modify, it's an unorder_map
   day['M'] = "MONDAY"; //succeed to modify

   for (unordered_map<char, string>::iterator itr=day.begin(); itr != day.end(); ++itr)
   {

    cout << (*itr).first << endl;
    cout << (*itr).second << endl;

   }

   print_unordered_map(day, 'W');
   // Note about Associative Array;
   // 1. search time: unordered map, O(1), map O(log(n));
   // 2. unordered map may degrade to O(n);
   // can't use multimap and unordered_multimap, they don't have [] operator;
   /*
   Container Adaptor
   - provide a restricted interface to meet special needs
   - implemented with fundamental container classes
   1. stack: LIFO, push(), pop(), top()
   2. queue: FIFO, push(), pop(), front(), back()
   3 priority queue: first item always has the greatest priority, push(), pop(), top()
   */

   /*
   Another way to categorizing containers:
   1. Array based containers: vector, deque;
   2. Node base containers: list + associative containers + unordered containers

   Array based containers invalidates pointers
   -- native pointers, iterators, reference
   */
   
   vector<int> vec3{1, 2, 3, 4};
   int* p = &vec3[2]; // p points to 3

   cout <<"*P " << *p << endl;
   cout << "vec[0] "<< vec3[0] <<endl;

   vec3.insert(vec3.begin(), 0);

   cout <<"*P " << *p << endl; //2 OR??? 未定义行为，无论插到前面还是尾部，都有可能出发reallocation
   cout << "vec[0] "<< vec3[0]<<endl;

   /*
   Iterators
   1. Random Access Iterator: vector, deque, array
   */
    // vector<int>::iterator itr_vec;
    // itr_vec = itr_vec + 5;
    // itr_vec = itr_vec - 5;


    // 2. Bidirectional Iterator: list, set/multiset, map/multimap
    // list<int>::iterator itr_list;
    // ++itr_list;
    // --itr_list;

    // 3. Forward Iterator: forward_list
    //    forward_list<int>::iterator  itr_forward;
    //    ++itr_forward;

    //Unordered containers provide "at least" forward iterator.
    // 4. Input Iterator: read and process values while iterating forward
    // int x = *itr;

    // 5. Output Iterator: output values while iterating forward.
    // *itr = 100;


    //Every container has a iterator and a const_iterator
    set<int>::iterator itr_m;
    set<int>::const_iterator itr_c; //read_only access to container elements

    set<int> myset_s{2, 4, 5, 1, 9};
    for (itr_c=myset_s.begin(); itr_c!=myset_s.end(); ++itr_c)
    {
        cout << *itr_c << endl;
        //*itr_c = 3;
    }


    // for each loop
    cout << "for each loop" << endl;
    for_each(myset_s.cbegin(), myset_s.cend(), Myfunction); //only in standard higher than c++ 11


    //Iterator Function
    // advance(itr, 5);
    // distance(itr1, itr2);

    /* Iterator Adapter (Predefined Iterator)
     * - A special, more powerful iterator
     * 1. Insert iterator
     * 2. Stream iterator
     * 3. Reverse iterator
     * 4. Move iterator (C++ 11)
     */

    //Insert iterator
    //用于将数据插入vec的某处，类似list<typenanme>的splice函数
    vector<int> vec11{4, 5};
    vector<int> vec22{12, 14, 16, 18};
    vector<int>::iterator v_iter = find(vec22.begin(), vec22.end(), 16);
    insert_iterator< vector<int> > i_itr(vec22, v_iter);
    copy(vec11.begin(), vec11.end(),  // source
         i_itr); // destination
         //vec22 {12, 14, 4, 5, 16, 18};
    //Other insert iterators:: back_iterator, front_insert_iterator

    //Stream iterator
    vector<string> vec44;
    // copy( istream_iterator<string>(cin),  //从标准输入读取类型 T 的对象，逐个读，
    //     istream_iterator<string>(),  //一直读到直到 EOF
    //     back_inserter(vec44));  //插入到vec44尾部

    // // 输入完成后按 Ctrl+Z 继续运行下方代码


    // copy( vec44.begin(),  //从vec44开始，
    //       vec44.end(),  //读到结尾，
    //       ostream_iterator<string>(cout, " ")); //把读到的元素写入标准输出留，每写一个元素就加一个空格

    //make it terse弄简短一些
    unique_copy( istream_iterator<string>(cin),  //从标准输入读取类型 T 的对象，逐个读，
        istream_iterator<string>(),  //一直读到直到 EOF
         ostream_iterator<string>(cout, " "));  //把读到的元素写入标准输出留，每写一个元素就加一个空格

    // 输入完成后按 enter 和 Ctrl+Z 继续运行下方代码


    // Reverse Iterator
    vector<int> vec_r{4, 5, 6, 7};
    reverse_iterator<vector<int>::iterator> itr_r;
    for(itr_r=vec_r.rbegin(); itr_r != vec_r.rend(); itr_r++)
    {
        cout << *itr_r << endl; // out: 7 6 , 5 ,4
    }

    /*
    Algorithms
    - mostly loops
    */
   vector<int> vec_l{4, 2, 5, 1, 3, 9};
   vector<int>::iterator itr_l = min_element(vec_l.begin(), vec_l.end()); // itr_l -> 1

   //Note 1: Algorithm always process ranges in a half-open way:[begin, end)
   sort(vec_l.begin(), itr_l); //vec: {2, 4, 5, 1, 3, 9}
   
   reverse(itr_l, vec_l.end()); // vec: {2, 4, 5, 9, 3 ,1}

   //Note 2:
   vector<int> vec_result(3);
   copy(itr_l, vec_l.end(), //source
        vec_result.begin()); //destination
        //vec_r needs to have at least space for 3 elements.

    // Note 3：
    vector<int> vec_r1;
    copy(itr_l, vec_l.end(), back_inserter(vec_r1)); //Inserting instead of overwriting
    //back_insert_iterator Not efficient
    //vec_r1
    cout << "vec_r1 vec_r1" << endl;
    for(int i: vec_r1)
    {
        cout << i << endl; // 9 3 1
    }

     vector<int> vec_r2;
     vec_r2.insert(vec_r2.end(), itr_l, vec_l.end()); //Efficient and safe
     cout << "vec_r2 vec_r2, more Efficient and safe  " << endl;
    for(int i: vec_r2)
    {
        cout << i << endl; // 9 3 1
    }

    // Note 4：
    vector<int> vec_test{2, 4, 5, 9, 2};
    vector<int>::iterator itr_find_odd = find_if(vec_test.begin(), vec_test.end(), isOdd);
    cout << "ODD :" << *itr_find_odd << endl; // itr_find_odd --> 5

    //Note 5: Algorithm with native c++ array
    int arr[4] = {6, 3, 7, 4};
    sort(arr, arr+4);
    cout <<"native array" << endl;
    for(int i: arr)
    {

        cout << i << endl;

    }


    return 0;
}