#include <iostream>
using namespace std;

template<class T>
class SmartPointer
{
    T* ptr;

    public:
    SmartPointer():ptr(nullptr){
        cout<<endl<<" default ctor";
    }
    SmartPointer(T *ptr):ptr(ptr)
    {
        cout<<endl<<" one arg ctor";
    }

    void PrintValue()
    {
        cout<<__func__<<*ptr<<endl;
    }
   SmartPointer(const SmartPointer&) = delete;

    SmartPointer& operator=(const SmartPointer&& ptr) 
    {
        if(this->ptr == nullptr)
        this->ptr = new T(*ptr);

       // ptr.~SmartPointer();

        return *this;

    };
    
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    T* get()
    {
        return ptr;
    }
    T& getValue()
    {
        return *ptr;
    }

    ~SmartPointer()
    {
        cout<<endl<<"dtor ";
        if(ptr != nullptr)
        delete ptr;
    }
   
};

