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

// g++ -o 6_functors 6_functors.cpp
// ./6_functors

using namespace std;

/*

Function Objects (Functors)

Example:

*/


class X
{
    public:
        int a;
        X(int i):a(i){}
        void operator()(string str)
        {
            cout << "Calling functor X with parameter: " << str << endl;

        }

        explicit operator string () const 
        { 
            
            
            return "<class X: i= " + to_string(a) + " >";
        } //type conversion function

};


void add(int i)
{
    cout << i+2 << endl;
}


template<int val>
void addVal(int i)
{
    cout << val + i << endl;
}


/*
FUNCTOR TO ADD VALUE
*/

class AddValue
{
    int val;
    public:
        AddValue(int j):val(j){}
        void operator () (int i)
        {
            cout << i + val << endl;
        }
};


// Functor to compare last significant bit
//这是不能生效的,需要转成functor
//
bool lsb_less(int x, int y)
{
    return (x%10)<(y%10);
}

// Functor to compare last significant bit
//
class Lsb_less
{
    public:
    bool operator ()(int x, int y) const
    {
        return (x%10)<(y%10);
    }
};


class NeedCopy
{
    public:
        bool operator()(int x) const
        {
            return (x>20)||(x<5);
        }
};


int main()
{
    X foo(8);
    foo("Hi"); //Calling functor X with parameter Hi

    X oa(9);

    string a = static_cast<string>(oa);

    cout << a << endl;


    vector<int> vec{2, 3, 4, 5};

    for_each(vec.begin(), vec.end(), add); //{4, 5, 6, 7} 这里不能动态地修改add函数增加的值

    const int x = 4;
    cout << "addVal" << endl; 
    for_each(vec.begin(), vec.end(), addVal<x>); //{6, 7, 8, 9} 这里通过模板，可以动态修改增加的值addVal<x>

    cout << "AddValue" << endl; 
    for_each(vec.begin(), vec.end(), AddValue(x)); //{6, 7, 8, 9} 这里通过Functor，可以动态修改增加的值AddValue(x)

    /*
    Build-in Functors

    less greater greater_equal less_equal not_equal_to 
    logical_and logical_not logical_or
    multiplies minus plus divide modulus negate
    */

    cout << "Build-in Functors" << endl; 
    int y = multiplies<int>()(3, 4);
    if (not_equal_to<int>()(y, 10))
    {
        cout << y << endl;
    }
   

    /*
    Parameter Binding
    */
   set<int> mset{2, 3, 4, 5};
   vector<int> mvec;
        

    // 过于老的写法了，改用lambda
    //Multiply myset's elements by 10 and save in vec
    //     transform(mset.begin(), mset.end(), //source
    //               back_inserter(vec),//destination
    //               bind(multiplies<int>(), placeholders::_1, 10) //functor 舍弃此处
    // );
    // 过于老的写法了，改用lambda


    //Multiply myset's elements by 10 and save in vec
    // 舍弃上方的写法，改用lambda
    cout << "Transform" << endl;
    transform(mset.begin(), mset.end(), //source
              back_inserter(mvec),//destination
            //   [](int x){return x * 10;}//functor 可行
              [](int x){return multiplies<int>()(x, 10);}//functor 可行但本章主要将functor，采用此种写法
    ); // mvec {20, 30, 40, 50}

    for (int i: mvec)
    {
        cout << i << endl; //20, 30, 40, 50
    }
    
    //ptr_fun
    /*在 C++98 时，STL 算法（如 for_each, transform, sort） 
    可以接受 函数对象 (functor)，但对“普通函数指针”的支持不完善。
    ptr_fun(myfunc) 会把它包成一个 functor 类型,以便使用transform
    */

    /*
    Why do we need functor in STL
    */
    set<int> myset1{3, 1, 25, 7, 12}; //myset: {1, 3, 7, 12, 25}

    //same as
    set<int, less<int> > myset2{3, 1, 25, 7, 12};
    cout << "myset:  " << endl;
    for(int i: myset2)
    {
        cout<< i << endl;
    }

    //set<int, Lsb_less> 其中的Lsb_less是用来给set比较函数functor,根据个set中的位数比较个位数大小
    set<int, Lsb_less> yourset{3, 1, 25, 7, 12};
    cout << "yourset :" << endl;
    for(int i: yourset)
    {
        cout<< i << endl;
    }


    /*
    Predicate
    A functor or function that:
    1. Returns a boolean
    2. Does not modify data
    */

    /*
    PREDICATE IS USED FOR COMPARISON OR CONDITION CHECK
    */

    vector<int> result_vector;
    //functor version
    transform(myset1.begin(), myset1.end(),
              back_inserter(result_vector), 
              NeedCopy() //predicate
            );

    // lambda version
    // transform(myset1.begin(), myset1.end(),
    //         back_inserter(result_vector), 
    //         [](int x){return (x>20)||(x<5);}
    //     );

    //myset1{3, 1, 25, 7, 12}
    //      {1, 1, 0, 0, 1}
    cout << "result_vector transform" << endl;
    for(int i: result_vector)
    {
        cout << i << endl;
    }
    // 




    return 0;
}
/*
Benefits of functor:
1. Smart function: capabilities beyond operator()
    It can remember state.
2. It can have its own type.


*/