#include <iostream>
using namespace std;


void RevStr(char *src)
{
    char *p = src;
    int count = 0;
    while(*p++ != '\0')
    {
        count++;
    }
    cout<<count<<endl;
    p = src;
    char *temp = new char[count + 1];
    char *b_temp = temp;
    char *flag = src;
    while(*p++ != '\0')
    {
        if(*p == ' ')
        {
            char *f = p;
            p--;
            while(*p != *flag)
            {
                *temp = *p;
                temp++;
                p--;
            }
            *temp = *p;
            temp++;
            flag = f;
            p = f;
            cout<<b_temp<<endl;
        }
    }
    *temp = '\0';
    cout<<"btemp is "<<b_temp<<endl;
    while(*b_temp != '\0')
    {
        *src++ = *b_temp++;
    }
}


int main()
{
    char s[] = "i am mason";
    cout<<s<<endl;
    RevStr(s);
    cout<<s<<endl;
    return 0;

}
