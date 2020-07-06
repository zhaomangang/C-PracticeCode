#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char *transformation(char *str)
{
    int len = strlen(str);
    char *buf = new char[len+1];

    char *p = str;
    char *q = p + 1;
    int count = 1;
    while(*q)
    {
        if(*p == *q)
        {
            cout<<*p<<"\t"<<*q<<endl;
            count++;
            p++;
            q++;
        }else {
//            itoa(count,buf,10);
            sprintf(buf,"%d",count);
            cout << buf <<endl ;
            int nbits = strlen(buf);
            strcat(buf,q);
            *q = 0;
            strcat(str,buf);
            q += nbits;
            p = q;
            q = q+1;
            count = 1;
            cout<<str<<endl;
        }
    }
   //bin itoa(count,buf,10);
    sprintf(buf,"%d",count);
    cout<<buf<<endl;
    strcat(str,buf);

    delete []buf;
    buf = NULL;
    return str;
}


int main()
{

    char str[100] = "aaaaatsb";
    cout<<str<<"\n";
    cout<<transformation(str)<<endl;
    return 0;
}
