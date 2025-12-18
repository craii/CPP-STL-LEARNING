#include <iostream>

// 编译运行命令
// g++ -o 1_stl_template 1_stl_template.cpp
// ./1_stl_template

using namespace std;

template<typename T>
T square(const T a)
{
    T result = a * a;
    return result;
}

template<typename T>
class BoVector
{
    T arr[1000];
    int size;
    public:
        BoVector():size(0){}
        ~BoVector(){cout<<"Goodbye!!!"<<endl;}
        void push(T x){arr[size]=x; size++;}
        
        T get(int i) const{return arr[i];}

        int getSize() const{return size;}
        void print() const 
        {
            for(int i=0;i<size; i++)
            {
                cout<< arr[i] <<endl;
            }
        }
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, const BoVector<T>& rhs2){
    BoVector<T> ret;
    for(int i=0; i<rhs1.getSize(); i++)
    {
        ret.push(rhs1.get(i) * rhs2.get(i));
    }
    return ret;
}

class Animal
{
    public:
        Animal(){cout<<"hello Animal"<<endl;}
        ~Animal(){cout<<"goodbye Animal"<<endl;}
};


int main(int argc, char **argv)
{

    cout<< square(8) << endl;
    cout<< square(9.9) << endl;
    BoVector<int> bv;
    bv.push(2);
    bv.push(12);
    bv.push(23);
    bv.push(34);
    bv.print();
    cout<< bv.getSize() <<endl;
    cout<< bv.get(3) <<endl;

    cout << "Print squared bv:" << endl;
    bv = square(bv);
    bv.print();

    Animal *animal = new Animal();
    delete animal;
    BoVector<float> *bv = new BoVector<float>;

}