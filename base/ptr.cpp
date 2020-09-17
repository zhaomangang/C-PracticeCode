#include <iostream>
using namespace std;

int main()
{
    int *pt;
    pt = (int*) 0xB8000000;
    cout<<pt<<"\n"<<*pt<<endl;

    
    return 0;
}
