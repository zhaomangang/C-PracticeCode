#include <iostream>
using namespace std;


void BubbleSort(int* a,int n)
{
    //冒泡排序
    for(int i=0;i<n-1;i++)
    {
        for(int j = 0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}



void SelectSort(int* a,int n)
{
    int index = 0;
    for(int i=0;i<n;i++)
    {
        index = i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[index])
            {
                index = j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
}

void InsertionSort(int* a,int n)
{
    void Print(int* a,int n);
    for(int i=0;i<n;i++)
    {
        int temp = a[i];
        int j=i;
        for( ;j>0;j--)
        {
            if(temp<a[j-1])
            {
                a[j] = a[j-1];
            }else{
                break;
            }
        }
        a[j]=temp;
        Print(a,10);

    }
}


void Print(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
   // int a[4]={2,1,7,3};
    int a[10] = {4,2,6,8,0,9,1,3,5,7};
    //SelectSort(a,10);
   // BubbleSort(a,10);
    InsertionSort(a,10);
    Print(a,10);
    return 0;
}
