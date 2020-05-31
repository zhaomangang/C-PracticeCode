#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char *my_strcpy(char *strDest,const char * strSrc)
{
    //自己写时没有考虑到空的情况
    if(strSrc == NULL)
        return NULL;
    int count = 0;
    const char *s = strSrc; 
    while(*s != '\0')
    {
        count++;
        s++;
    }
    s = NULL;
    //cout<<count<<endl;
    strDest = new char[count];
    char *p = strDest;
   

    while((*strDest++ = *strSrc++) != '\0');    //书上写法
    /*
    while(*strSrc != '\0')
    {
        *strDest = *strSrc;
       // cout<<*strDest<<endl;
       // cout<<*strSrc<<endl;
        strDest++;
        strSrc++;
    }
    *strDest = '\0';
    */
    
    //cout<<"strDest is : "<<strDest<<endl;
    return p;
}



int main()
{
    char str[30] = "this is a test str";
    cout<< str<<endl;
    char *copy_str = NULL;

    copy_str =  my_strcpy(copy_str,str);

    cout<<"str is : "<<str<<endl;
    cout<<"copy_str is : "<<copy_str<<endl;
    
    return 0;
}
