#include <iostream>
#include <cstring>

using namespace std;

char* myStrrev1(const char* s)
{
    char *rev = new char[strlen(s)+1];
    char *start = rev;
    const char* end = s + strlen(s)-1;
    while (end >= s)
    {
        *rev = *end;
        end--;
        rev++;
    }
    *rev = '\0';
    return start;
}

char* myStrrev2(const char* s)
{
    char *rev = new char[strlen(s)+1];
    strcpy(rev,s);
    char* start = rev;
    char* end = rev + strlen(rev)-1;
    cout<<*start<<","<<*end<<endl;
    while(end > start)
    {
        char temp = *end;
        *end = *start;
        *start = temp;
        cout<<*end<<","<<*start<<endl;
        //cout<<end<<","<<start<<endl;
        end--;
        start++;
    }
    return rev;
}

int main()
{
    char s[16] = "i im a cat";
    cout<<myStrrev1(s)<<endl;
    cout<<s<<endl;
    cout<<myStrrev2(s)<<endl;

}
