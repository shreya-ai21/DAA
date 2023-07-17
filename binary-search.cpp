#include <iostream>
using namespace std;
int binarysearch(int a[],int n, int key)
{
    int l=0,h=n,mid,res=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==key)
        {
            res=1;
            return res;
        }
        else if(mid<key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return res;
}

int main()
{
    int n,key,i,j,temp,res;
    int a[100], *p;
    p=a;
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"Enter the elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"Enter the element to be searched:";
    cin>>key;
    res=binarysearch(a,n-1,key);
    if(res==0)
    {
        cout<<"Element not found.";
    }
    else
    {
        cout<<"Element found.";
    }
}
