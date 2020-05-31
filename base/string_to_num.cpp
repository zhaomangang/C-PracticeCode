#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int strToNum(char *str) 
{
    int num = 0;
    int flag = 1;
 //   int count = 0;
 //   vector<int >nums;
    for(int i=0; str[i]!='\0'; i++){
        if(i==0 && (str[0] == '-' || str[0] == '+')) {
            if(str[0] == '-')
                flag = -1;
            continue;
        }
        num = num*10 + (str[i] - '0');
        // cout<<str[i] - '0'<<endl;
 //      nums.push_back(str[i]-'0');
 //       count++;
    }
/*
    for(vector<int >::iterator it = nums.begin(); it != nums.end(); ++it ) {
       // cout<<*it<<endl;
        num += (*it) * pow(10,count-1);
        cout<<num<<endl;
        count--;
    }
    num *= flag;
*/
    num *= flag;
    return num;

}



int main()
{

    cout<<"test 45678:  "<<strToNum("45678")<<endl;
    cout<<"test -459802: "<<strToNum("-459802")<<endl;

    return 0;
}
