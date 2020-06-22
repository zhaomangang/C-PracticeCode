#include <iostream>
#include <cstring>
using namespace std;

char *commonstring(char *str1,char *str2)
{
    char *shortstr = NULL;
    char *longstr = NULL;
    char *substr;

    if(NULL == str1 || NULL == str2)
    {
        return NULL;
    }

    if(strlen(str1) <= strlen(str2))
    {
        shortstr = str1;
        longstr = str2;
    }else {
        shortstr = str2;
        longstr = str1;
    }

    if(strstr(longstr,shortstr) != NULL)
    {
        return shortstr;
    }

    substr = new char[sizeof(char)*strlen(shortstr)+1];

    for(int i = strlen(shortstr)-1; i > 0; i--)
    {
        for(int j = 0; j<= strlen(shortstr)-i; j++)
        {
            memcpy(substr,&shortstr[j],i);
            substr[i] = '\0';
            if(strstr(longstr,substr)!=NULL)
                return substr;
        }
    }
    return NULL;
}

int main()
{
    char s1[12] = "aocdfe";
    char s2[12] = "pmcdfa";
    cout<<commonstring(s1,s2)<<endl;

    return 0;
}
