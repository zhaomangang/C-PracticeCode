#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;


string numToStr(int num)
{
    vector<int > nums;
    int count = 0;
    char flag = ' ';
    if(num<0)
    {
        num = -num;
        flag = '-';
        count++;    //提前为符号预留位置
    }
    while(num>0)
    {
        nums.push_back(num%10);
        num = num / 10;
        count++;
    }
    char *str = new char[count];
    int j = 0;
    if(flag == '-')
    {
        str[j] = flag;
        j++;
    }
    for(int i = nums.size()-1;i>=0;i--,j++)
    {
        char temp = nums.at(i) + 48;
        cout<<temp<<endl;
        str[j] = temp;
        
    }
    string cpp_str;
    cpp_str.append(str);
    cout<<str<<endl;
    cout<<cpp_str<<endl;
    return cpp_str;
    
}



/*
 *使用库stdlib函数
 *
 * */

int main()
{

    
    int num_int = 435;
    double num_double = 435.10f;
    char str_int[30];
    char str_double[30];

    /**
     *linux系统中无库函数itoa因此用snprintf代替，其中：
     *参数1：输出到哪个字符串 参数2：最长转换多少 参数3：要转换的数字
     *
     * ***/
    snprintf(str_int,30,"%d",num_int);
 //   itoa(num_int,str_int,10);
    /*
     *gcvt()将浮点型数字转换为字符串，取四舍五入。其中：
     *8表示精确位数
     *
     * */ 
    gcvt(num_double,8,str_double);
    
    cout<<str_int<<endl;
    cout<<str_double<<endl;
    cout<<"my func test :\n";
    cout<<numToStr(23456);
    cout<<numToStr(-78954);
    return 0;
}

