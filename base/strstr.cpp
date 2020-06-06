#include <iostream>
using namespace std;




int strstr(const char* src, const char* sub)
{
    if(src == NULL || sub == NULL)
        return -1;
    int pos = 0;
    while(*src != '\0')
    {
        if(*src == *sub)
        {
            const char *s = src;
            while(*sub != '\0')
            {
                if(*sub != *s)
                {
                    break;
                }else if(*(sub+1) == '\0')
                {
                        return pos;
                    
                }
                sub++;
                s++;
            }
           // src++;
           // pos++;

        }
        src++;
        pos++;
    }
    return -1;
}

int main()
{
    char s[] = "masonzhao";
    cout<<s<<endl;
    cout<<"nzh "<<strstr(s,"nzh")<<endl;
    cout<<"zhp "<<strstr(s,"zhp")<<endl;
    return 0;
}


