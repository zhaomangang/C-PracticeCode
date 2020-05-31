#include <iostream>
#include <string>

using namespace std;

int myStrlen(const char* str)
{
    if(str == NULL)
        return 0;
    int count = 0;
    while(*str!='\0')
    {
        count++;
        str++;
    }
    return count;
}

int myStrlenBook(const char* str)
{
    const char *begin = str;
    while(*str++ != '\0');

    return (str - begin - 1);
}

int main()
{
    char str[30] = "zhaomangang";
    cout<<myStrlen(str)<<endl;
    cout<<myStrlenBook(str)<<endl;
}
