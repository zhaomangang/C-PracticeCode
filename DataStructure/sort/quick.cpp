#include <iostream>
using namespace std;

void QuickSork(int array[],int start,int end)
{
    //快速排序
    int i = start;
    int j = end;
    if(i < j)
    {
        int temp = array[i];
        while(i < j)
        {
            //从右往左找
            while(i < j && temp < array[j])
            {
                j--;
            }
            if(temp > array[j])
            {
                array[i] = array[j];
            }
            //从左往右找
            while(i < j && temp > array[i])
            {
                i++;
            }
            if(temp < array[i])
            {
                array[j] = array[i];
            }
        }
        array[i] = temp;
        QuickSork(array,start,i-1); //递归左半部分
        QuickSork(array,i+1,end);    //右半部分
    }
}

int main()
{
    int array[10] = {5,6,9,3,1,0,8,7,2,4};
    QuickSork(array,0,9);
    for (int i = 0 ;i < 10; i++)
    {
        cout<<array[i]<<endl;
    }

    return 0;
}
