#include "SmartPointer.hpp"
#include <iostream>
using namespace std;

template<class T>
class Singelton
{
    static Singelton<T>* instance;
    static mutex m;
    T data;
    Singelton(T data):data(data){cout<<"ctor "<<data<<endl;}

public:
//template<class T>
    T operator* ()
    {
        return data;
    }
    void testname()
    {
        cout<<"hello";
        
    }
    public:
    static Singelton<T>* getInstance(T);
};

template<class T>
Singelton<T>* Singelton<T>::instance = NULL;

template<class T>
mutex Singelton<T>::m;


template<class T>
Singelton<T>* Singelton<T>::getInstance(T data){
    m.lock();
    if(instance == NULL)
    {
        instance = new Singelton(data);
    }

    m.unlock();


    return instance;
}


int main()
{
    cout<<"hello  prakash 1125";
  Singelton<int> *ptr = Singelton<int>::getInstance(56);


     Singelton<int> *ptr1 = Singelton<int>::getInstance(516);
    cout <<endl<<"dereferenced value "<< **ptr;
{

    SmartPointer<int> sp(new int(15));

    cout<<endl<<" sp "<<*sp<<endl;
    sp.PrintValue();

    SmartPointer<int> s1;
   // s1 = std::move(sp);

    
}



  ptr1->testname();

   // cout<< *ptr1 <<"  "  <<*ptr;

    return 0;

}

