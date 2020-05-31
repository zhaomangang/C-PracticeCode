
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void *myMemcpy(void *memTo, const void *memFrom, size_t size)
{
    if(memTo == NULL || memFrom == NULL)
        return NULL;
    char *memToTemp =(char *)memTo;
    char *memFromTemp = (char *)memFrom;
    for(int i = 0; i < size; i++)
    {
       *memToTemp++ = *memFromTemp++;
    }
    return memTo;
}

int main()
{
    char s[] = "this is a test memory";
    char s_copy[30];
    myMemcpy(s_copy,s,strlen(s)+1);
    
    cout<<"memory is:"<<s<<endl;
    cout<<"memory copy is:"<<s_copy<<endl;
    
    return 0;
}
