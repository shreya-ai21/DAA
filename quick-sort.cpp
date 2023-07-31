#include<iostream>
#include<windows.h>
using namespace std;

int Partition(int arr[],int l,int h)
{
    int pi=arr[l],i=l,j=h;
    while(l<h)
    {
        do{
            i++;
        }while(arr[i]<=pi);
        do{
            j++;
        }while(arr[j]>=pi);
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp1=arr[j];
    arr[j]=arr[l];
    arr[l]=temp1;
    return j;
}

void QuickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int j;
        j=Partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    int l=0;
    cout<<"Enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,l,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<'\t';
    }
}