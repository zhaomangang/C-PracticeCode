#include <iostream>
#include <cstring>
using namespace std;

char* addBigInt(char* num1,char* num2)
{
    //1 2 3 4 5 
    //3 5 6
    char* s1 = num1;
    char* s2 = num2;
    num1 = num1 + strlen(num1) - 1;
    num2 = num2 + strlen(num2) - 1;
    cout << num1 <<"\t" << num2<<endl;
    int maxlen = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    char flag = '0';
    char* sum = new char[maxlen + 2];
    sum += maxlen + 2;
    *sum = '\0';
    sum--;
    while(1)
    {
        if( s1 > num1 )
        {
            while(s2 <= num2)
            {
                cout<<"line25"<<endl;
                *sum = ((*num2 + flag - '0' - '0') % 10) + '0';
                flag = ((*num2 + flag - '0' - '0') / 10) + '0';
                if(num2!=s2)
                    num2--;
                else 
                    break;
                sum--;
            }
            break;
        }
        if(s2 > num2)
        {
            while(s1 <= num1)
            {    
                cout<<"line 38"<<endl;
                *sum = ((*num1 + flag - '0' - '0') % 10) + '0';
                flag = ((*num1 + flag - '0' - '0') / 10) + '0';
                if(num1 != s1)
                    num1--;
                else 
                    break;
                sum--;
            }
            break;
        }
        cout <<"num1 = "<<*num1<<"\t"<<"num2 = "<<*num2<<endl;
        *sum = ((*num1 + *num2 + flag - '0' - '0' - '0') % 10) + '0';
        flag = ((*num1 + *num2 + flag - '0' - '0' - '0') / 10) + '0';
        cout<<*sum<<endl;
        if(num1!=s1 && num2 != s2)
        {
            num1--;
            num2--;
        }else {
            break;
        }
        sum--;
        //cout<<sum<<endl;
    }
    if (flag != '0')
    {
        sum--;
        *sum = flag;
        return sum;
    }
    return sum;
}

int main()
{
    char s1[12] = "11";
    char s2[12] = "82222";
    cout<<addBigInt(s1,s2)<<endl;
    return 0;

}
