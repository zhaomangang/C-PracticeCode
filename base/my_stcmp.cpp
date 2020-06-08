#include <iostream>
#include <cstring>
using namespace std;

int MyStcmp(char* str1, char* str2)
{
    //相等返回0
    //str1 > str2返回1
    //str1 < str2返回-1
    for(;*str1 == *str2 ; ++str1,++str2)
    {
        if(*str1 == '\0')
        {
            return 0;
        }
    }
    return ((*(unsigned char*)str1 < *(unsigned char*)str2)?-1:0);
}

int main()
{
    char s[10] = "12345";
    char s1[10] = "123";
    char s2[10] = "123456";
    char s3[10] = "12347";
    char s4[10] = "123445";
    cout<<strcmp(s,s1)<<endl;
    cout<<s1<<" "<<MyStcmp(s,s1)<<" "<<strcmp(s,s1)<<endl;
    cout<<s2<<" "<<MyStcmp(s,s2)<<" "<<strcmp(s,s2)<<endl;
    cout<<s3<<" "<<MyStcmp(s,s3)<<" "<<strcmp(s,s3)<<endl;
    cout<<s4<<" "<<MyStcmp(s,s4)<<" "<<strcmp(s,s4)<<endl;

}
