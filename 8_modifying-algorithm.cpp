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


// g++ -o 8_modifying-algorithm 8_modifying-algorithm.cpp
// ./8_modifying-algorithm
using namespace std;



bool lessThan10(int x){return x<10;}


int main()
{
    /*
    STL Algorithm Walkthrough
        modifying Algorithms -- changes the element value
        copy, move, transform, swap, fill, replace, remove
    */

    vector<int> vec{9, 60, 70, 8, 45, 87, 90};
    vector<int> vec2(11);
    vector<int>::iterator itr1, itr2;
    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;


    //1. COPY
    //COPY
    copy(vec.begin(), vec.end(), // source
         vec2.begin()); //destination

    cout << "check items in vec and vec2" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "vec: "<< vec.at(i) << "----" << " vec2: " << vec2.at(i) << endl;
    }

    //COPY IF
    vector<int> vec3(11);
    copy_if(vec.begin(), vec.end(), // source
            vec3.begin(),//destination
            [](int x){ return x>80;}
            ); 

    cout << "check copy if" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "vec: "<< vec.at(i) << "----" << " vec2: " << vec3.at(i) << endl;
    }
    // vec2:{87, 90, 0,0,0,0,0,0,0,0}

    //copy n
    vector<int> vec4(11);
    cout << "check copy n" << endl;
    copy_n(vec.begin(), 4, vec4.begin());

    cout << "check copy n" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "vec: "<< vec.at(i) << "----" << " vec2: " << vec4.at(i) << endl;
    }
    // vec2:{9, 60, 70, 8,0,0,0,0,0,0,0}

    //copy backward
    vector<int> vec5(11);
    cout << "check copy backward" << endl;
    copy_n(vec.begin(), 4, vec5.begin());

    cout << "check copy backward" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "vec: "<< vec.at(i) << "----" << " vec2: " << vec5.at(i) << endl;
    }
    // vec2:{0,0,0,0,9,60,70,8,45,87,90}

    //2. MOVE
    vector<string> vec6{"apple", "orange", "pear", "grape"}; 
    vector<string> vec7(6);

    move(vec6.begin(), vec6.end(), vec7.begin());
    //vec6 -- > {"", "", "", "",}
    //vec7  --> {"apple", "orange", "pear", "grape", "", ""};
    // if move semantics are defined for the element type, elements are moved over,
    // otherwise they are copied over with copy constructor, just like copy()

    vector<string> vec8(6);
    move_backward(vec6.begin(), vec6.end(), vec8.end());
    //vec8  --> {"", "", "apple", "orange", "pear", "grape"};


    //3 .TRANSFORM

    vector<int> vec_i1{9, 60, 70, 8, 45, 87, 90}, vec_i2{9, 60, 70, 8, 45, 87, 90}, vec_i3(11), vec_i4(11);
    transform(vec_i1.begin(), //source
              vec_i1.end(), //source
              vec_i3.begin(),//destination
              [](int x){return x-1;} //operation
            );

    transform(vec_i1.begin(), vec_i1.end(),//source #1
            vec_i2.begin(), //source #2
            vec_i4.begin(),//destination
            [](int x, int y){return x+y;} //operation x from #1 y from #2
        );

    cout << "check tranformed vec_i3" << endl;
    for(int i: vec_i3)
    {
        cout << i << endl;
    }

    cout << "check tranformed vec_i4" << endl;
    for(int i: vec_i4)
    {
        cout << i << endl;
    }

    //4. SWAP - TWO WAY COPYING
    swap_ranges(vec_i1.begin(), vec_i1.end(),//target1
                 vec_i3.begin()); //target2

    
    //5. FILL
    vector<int> vec_f(5), vec_f1(5), vec_f2(5), vec_f3(5);
    fill(vec_f.begin(), vec_f.end(), 9);
    fill_n(vec_f1.begin(), 3, 9);

    generate(vec_f2.begin(), vec_f2.end(), rand);

    generate_n(vec_f3.begin(), 3, rand);

    cout << "check fill" << endl;
    for(int i :vec_f)
    {
        cout << i << endl;
    }

    cout << "check fill_n" << endl;
    for(int i :vec_f1)
    {
        cout << i << endl;
    }

    cout << "check generate" << endl;
    for(int i :vec_f2)
    {
        cout << i << endl;
    }

    cout << "check generate_" << endl;
    for(int i :vec_f3)
    {
        cout << i << endl;
    }


    //6. REPLACE
    vector<int> vec_r{1,2,3,4,5,6}, vec_r2{1,1,1,6,6,6}, vec_r3(6), vec_r4(6);
    replace(vec_r.begin(), vec_r.end(),//data range
            6, //old value condition
            9);// new value

    replace_if(vec_r2.begin(), vec_r2.end(),//data range
               [](int x){return x>5;}, //old value condition predicate
               9);// new value


    replace_copy(vec_r.begin(), vec_r.end(),//source data range
                vec_r3.begin(),//destination
                6,//old value condition
                7// new value
            );

    replace_copy_if(vec_r.begin(), vec_r.end(),//data range
                    vec_r4.begin(),//destination
                    [](int x){return x>3;}, // old value condition predicate
                    7// new value
                    );

    cout << "check replace" << endl;
    for(int i :vec_r)
    {
        cout << i << endl;
    }

    cout << "check replace_if" << endl;
    for(int i :vec_r2)
    {
        cout << i << endl;
    }

    cout << "check replace_copy" << endl;
    for(int i :vec_r3)
    {
        cout << i << endl;
    }
   
    cout << "check replace_copy_if" << endl;
    for(int i :vec_r4)
    {
        cout << i << endl;
    }

    //7. REMOVE
    //狗屎 it's the most stupid shit i've ever seen it stl till now
    // 傻逼remove操作后，container里面会只剩下没有被删除的【有效】数据，然后返回一个iterator【itr】，指向有效数据的后一位
    //所以 container.begin() ~ itr 之间就是【有效数据】： {原数据} - {被删除的数据}
    // 你他妈都modify了就不能直接修改原有container的begin()和end()?
    vector<int> vec_rm{80,3,1,2,3,4,5,6}, valid_vec;
    vector<int>::iterator itr_rm= remove(vec_rm.begin(), vec_rm.end(), 3); // remove all 3
    cout << "check remove, itr_pointer" << *itr_rm << *(itr_rm -1) << *(itr_rm -2) << endl;
    
    int x = itr_rm - vec_rm.end();

    // 尝试获取数据COPY
    cout << "valid range of ver_rm: copy" <<endl;
    copy(vec_rm.begin(), itr_rm,
         back_inserter(valid_vec));
    for(int i: valid_vec)
    {
        cout << i << endl;
    } // 80 1 2 4 5 6



    auto itr_rm1 = remove_if(valid_vec.begin(), valid_vec.end(), 
                                              [](int x){return x > 5;}); // remove all > 5
    valid_vec.erase(itr_rm1, valid_vec.end());

    // 尝试获取数据 ERASE
    cout << "valid range of ver_rm: erase" <<endl;
    for(int i: valid_vec)
    {
        cout << i << endl;
    } //1 2 4 5


    //remove_copy
    vector<int> vec_rc{1, 2, 3, 10, 12, 15, 20}, vec_rc2;
    cout <<"length of vec_rc: " << vec_rc.end() - vec_rc.begin() << endl;
    remove_copy_if(vec_rc.begin(), vec_rc.end(), //source
                back_inserter(vec_rc2),//destination
                [](int x){ return x>=15;} // predicate
            );
    //如果是remove_copy()，则[](int x){ return x>=15 必须换成具体的数字

    cout << "check remove_copy" <<endl;
    for(int i: vec_rc2)
    {
        cout << i <<endl;
    }

    //UNIQUE()
    // remove consecutive equal
    vector<int> vec_u{1,2,3,3,5,6,7,7,8,9,9,9};
    auto uni_itr = unique(vec_u.begin(), vec_u.end());
    cout << "check unique" <<endl;
    vec_u.erase(uni_itr, vec_u.end());
    for(int i: vec_u)
    {
        cout << i <<endl;
    }


    //UNIQUE WITH PREDICATE
    vector<int> vec_u1{1,2,3,3,5,6,7,7,8,9,9,9};
    auto uni_itr1 = unique(vec_u1.begin(), vec_u1.end(), [](int f, int s){return (f>5)&&(f==s);});
    //[](int f, int s){return (f>5)&&(s>5)&&(f==s);} &&(s>5)似乎可省略
    cout << "check unique condition " <<endl;
    vec_u1.erase(uni_itr1, vec_u1.end());
    for(int i: vec_u1)
    {
        cout << i <<endl;
    }

    //UNIQUE COPY
    vector<int> vec_u2{1,2,3,3,5,6,7,7,8,9,9,9}, vec_u3;
    auto uni_itr2 = unique_copy(vec_u2.begin(), vec_u2.end(), 
                                back_inserter(vec_u3),
                                [](int f, int s){return (f<5)&&(f==s);}); // 小于5且重复的会被删掉其中一个


    cout << "check unique_copy in vec_u3" <<endl;

    for(int i: vec_u3)
    {
        cout << i << " "; //1 2 3 5 6 7 7 8 9 9 9
    }


    /*
    Order-Changing Algorithms:
    -reverse, rotate, permute, shuffle

    They changes the order of elements in container, but not necessarily the elements themselves
    */

    vector<int> rev_vec{9, 60, 70, 8, 45, 87, 90}, rev_vec2(7);
    // 1. Reverse
    reverse(rev_vec.begin(), rev_vec.end());
    cout << "check Reverse " << endl;
    for(int i : rev_vec)
    {
        cout << i << " "; //90 87 45 8 70 60 9
    }
    cout<<endl;
    // reverse(rev_vec.begin() + 1, rev_vec.end() -1); // out put: 9 87 45 8 70 60 90


    reverse_copy(rev_vec.begin() + 1, rev_vec.end() - 1,
                 rev_vec2.begin());
    cout << "check Reverse_copy " << endl;
    for(int i : rev_vec2)
    {
        cout << i << " "; //60 70 8 45 87 0 0
    }
    cout<<endl;

    // 2. Rotate
    // don't know what's it for
    // 假设 vec = {partA, vec.begin() + n, partB}, 在rotate之后变为
    // vec = {vec.begin() + n，partB, partA}, 
    vector<int> rev_vec3{9, 60, 70, 8, 45, 87, 90}, rev_vec4(7);
    rotate(rev_vec3.begin(), rev_vec3.begin()+3, rev_vec3.end());
    cout << "check ROTATE " << endl;
    for(int i : rev_vec3)
    {
        cout << i << " "; 
        //9 60 70 8  45 87 90
        //8 45 87 90 9  60 70
    }
    cout<<endl;

    //rotate copy
    rotate_copy(rev_vec3.begin(), rev_vec3.begin()+3, rev_vec3.end(), //source
                        rev_vec4.begin()); //destination
    cout << "check ROTATE COPY " << endl;
    for(int i : rev_vec4)
    {
        cout << i << " "; 
        //8 45 87 90 9  60 70
        //90 9 60 70 8  45 87 
    }
    cout<<endl;

    //3. Permute
    //排列组合相关vec {1，2，3，4} 调用 next_permutation 会按【字典序的下一个排列】重排vec成下一个合法的组合 ；
    // prev_permutation 会重排vec成上一个合法的组合， 重拍成功会返回true, 否则（或者遍历完所有组合时）返回false；
    // 当需要遍历所有可能且不重复的组合时，可以使用

    // next_permutation
    vector<int> vec_permute{1, 2, 3, 4};

    cout << "vector before next permute" << endl;
    for (int i: vec_permute)
    {
        cout << i << " "; //1 2 3 4
    }
    cout << endl;

    bool bnp = next_permutation(vec_permute.begin(), vec_permute.end()); // 排成下一个字典序
    cout << "vector after next permute" << endl;
    for (int i: vec_permute)
    {
        cout << i << " "; //1 2 4 3
    }
    cout << endl;


    //prev_permutation
    bool bpp = prev_permutation(vec_permute.begin(), vec_permute.end()); // 排成上一个字典序

    cout << "vector after prev_permutation" << endl;
    for (int i: vec_permute)
    {
        cout << i << " "; //1 2 3 4
    }
    cout << endl;

    // sort(vec_permute.begin(), vec_permute.end()); // start permutation from the least arrangement
    // cout << "check next permute" << endl;
    // do {
    //     // 使用 vec_permute 做些操作
    //     for (int i: vec_permute)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // } while (next_permutation(vec_permute.begin(), vec_permute.end()));

    //4. Shuffle
    // - Rearrange the elements randomly
    // (swap each element with a randomly selected element)

    vector<int> vec_shuffle{1, 2, 3, 4, 5, 6};


    //Do NOT use this!!! the number is fixed!!!
    //shuffle(vec_shuffle.begin(), vec_shuffle.end(), default_random_engine());

    //?????ARE YOU OK?????????
    std::random_device rd;  
    std::mt19937 g(rd()); 
    shuffle(vec_shuffle.begin(), vec_shuffle.end(), g);
    // are you ok?????????????

    cout << "check the shuffle" << endl;
    for (int i: vec_shuffle)
    {
        cout << i << " "; //1 2 3 4
    }
    cout << endl;

    

}