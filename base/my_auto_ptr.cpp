#include <iostream>
using namespace std;

class People{
private:
    string name;
public:
    People(string name){
        cout<<"构造函数"<<endl;
        this->name = name;
    }

    const string GetName() {
        return this->name;
    }
    
    ~People() {
        cout<<"析构函数"<<endl;
    }

};

template <class T>
class MyAutoPtr {
public:
    MyAutoPtr(T* ptr) {
        this->ptr = ptr;
    }
    T* operator ->() {
        return this->ptr;
    } 
    T& operator *() {
        return *(this->ptr);
    }

    ~MyAutoPtr() {
        if(this->ptr != NULL) {
            delete this->ptr;
            this->ptr = NULL;
        }
    }



private:
    T* ptr;
};


int main()
{
    MyAutoPtr<People> ptr(new People("mason"));

    cout<<(*ptr).GetName();
    cout<<ptr->GetName();
    return 0;
}
