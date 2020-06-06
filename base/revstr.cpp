#include <iostream>
#include <cstdio>
using namespace std;


void RevStr(char *src)
{
    //先将字符串中每个单词的每个字母逆置 i ma nosam
    //再将整个字符串逆置 mason am i
    char *start = src;
    char *end = src;
    char *ptr = src;
    while(*ptr++ != '\0')
    {
        if(*ptr == ' ' || *ptr == '\0')
        {
            end = ptr-1;
            while(start < end)
            {
                char c = *start;
                *start = *end;
                *end = c;
                start++;
                end--;
            }
            start = ptr+1;
        }
    }
    cout<<src<<endl;
    end = ptr-2; 
    start = src;
    while(start < end)
    {
        char c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;
    }
    cout<<src<<endl;
}

int main()
{
    char s[] = "i am mason";
    cout<<s<<endl;
    RevStr(s);
    cout<<s<<endl;
    return 0;

}
