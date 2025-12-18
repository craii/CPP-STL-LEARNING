#include <set>
#include <map>
#include <iostream>

//g++ -o 4_associative_container 4_associative_container.cpp
//./4_associative_container
using namespace std;

int main()
{

    //SET (集合)
    /*- no duplicates
     * 1. fast search : O(log(n))
     * 2. Traversing is slow (compared to vector and deque)
     * 3. No random access, no [] operator
     * 4. set/multiset: value of the elements cannot be modified
    */

    set<int> myset{3, 1}; //myset {1, 3}
    myset.insert(7);  //myset {1, 3, 7} O(log(n))
    // myset.insert(2); myset {1, 2, 3, 7}
    set<int>::iterator it; 
    it = myset.find(7); // O(log(n)) it points to 7;
    //sequence containers don't even have find() member function

    cout << "loop the set" << endl; 
    for(set<int>::iterator itr=myset.begin(); itr != myset.end(); ++itr)
    {

        cout << *itr << endl;

    }
    cout << "loop the set end" << endl; 
    pair<set<int>::iterator, bool> ret; 
    //insert方法要求pair对象，用来存两个内容，iterator 和 bool；
    //如果插入成功，返回一个set<int>::iterator，告诉你新插入的值itr，以及true
    //如果插入失败，返回一个set<int>::iterator，告诉你已存在的值itr，以及false
    //插入失败则
    ret = myset.insert(3); //no new element inserted
    cout << "ret itr: " << *ret.first << endl;
    cout << "ret bool: " << ret.second << endl;

    if (ret.second == false)
    {
        it = ret.first; //"it" now points to element 3
    }

    myset.insert(it, 9); //myset: {1,3,7,9} O(log(n) => O(1))你不能指定值的插入位置，set根据值的大小自动排序，并决定各个值的位置
                        //it points to 3
    myset.erase(it); //myset: {1, 7, 9}

    myset.erase(7); //myset: {1, 9}
    // Note: none of the sequence containers provide this kind of erase



    cout << "******SET SESSION BEGINS******" << endl;
    
    cout << "******SET SESSION ENDS******" << endl;
    cout << "******                   ******" << endl;
    
    //MULTISET (集合)
    // multiset is a set that allows duplicated items
    // insertion to a multiset is always successful
    //set/multiset: value of the elements cannot be modified
    multiset<int> myset2{2, 2, 3, 4, 4, 5};
    cout << "loop the multiset" << endl; 
    for (int i : myset2)
    {
         cout << i << endl;
    }


    //MAP
    // - No duplicated key;
    // map/multimap;
    //--keys cannot be modified
    // type of *it pair<const char, int>
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(make_pair('z', 200));

    cout << "loop the map" << endl; 
    for(map<char, int>::iterator itr=mymap.begin(); itr != mymap.end(); ++itr)
    {
        // .  （成员访问） 优先级比 *（解引用） 更高
        //所以必须是(*itr).first，不能是 *itr.first
        cout << (*itr).first << " => " << (*itr).second << endl;

    }


    map<char, int>::iterator it1 = mymap.begin();
    mymap.insert(it1, pair<char, int>('b', 300)); 
    //it's a hint but does'nt work,排序还是按照key的大小来排序的 
    //it 参数的意思是 “我猜这个新元素应该插到 it1 附近，你可以用这个信息优化查找。”
    //如果 hint 正确，插入可以达到 O(1)
    //如果 hint 错误，插入会退化到 O(log n)

    cout << "loop the map AGAIN" << endl; 
    for(map<char, int>::iterator itr=mymap.begin(); itr != mymap.end(); ++itr)
    {
        cout << (*itr).first << " => " << (*itr).second << endl;
    }

    //MULTIMAP
    // - ALLOW duplicated key;
    // map/multimap;
    //--keys cannot be modified
    // type of *it pair<const char, int>
    multimap<char, int> mymap2;

    //associative containers: set, multiset, map, multimap
    //
    // what does Associative mean

    return 0;
}