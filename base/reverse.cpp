#include <iostream>
#include <stack>
#include <cassert>
#include <cstring>
using namespace std;

const char* reverse(const char* s1,const char* token)
{
    stack<char> stack1;
    const char* ptoken = token,*head = s1,*rear = s1;
    assert(s1 && token);
    while(*head != '\0')
    {
        while(*head != '\0' && *ptoken == *head)
        {
            ptoken++;
            head++;
        }
        if(*ptoken == '\0')
        {
            const char *p;
            for( p = head-1;p>=rear;p-- )
            {
                stack1.push(*p);
            }
            ptoken = token;
            rear = head;
        }else {
            stack1.push(*rear++);
            head = rear;
            ptoken = token;
        }
    }
    char *pReturn = new char[strlen(s1)+1];
    int i = 0;
    while(!stack1.empty())
    {
        pReturn[i++] = stack1.top();
        stack1.pop();
    }
    pReturn[i] = '\0';
    return pReturn;
}


int main()
{
    char s[30] = "my name is mason";
    char p[10] = "name";
    cout<<reverse(s,p)<<endl;
    return 0;
}
