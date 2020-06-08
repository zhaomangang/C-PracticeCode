#include <iostream>
#include <cstring>
using namespace std;


bool IsRevStr(char* str)
{
    char* str_end = str+strlen(str)-1;
   // cout<<*str_end;
    while(str <= str_end)
    {
        cout<<*str<<*str_end<<endl;
        if(*str != *str_end)
        {
            return false;
        }
        str++;
        str_end--;
    }
    return true;
}

int main()
{
    char str1[20] = "masonnosam";
    char str2[20] = "zhaomangang";
    char str3[20] = "zhaoahz";
    cout<<str1<<" "<<IsRevStr(str1)<<endl; 
    cout<<str2<<" "<<IsRevStr(str2)<<endl;
    cout<<str3<<" "<<IsRevStr(str3)<<endl;
    return 0;
}
