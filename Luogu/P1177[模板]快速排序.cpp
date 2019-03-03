#include<iostream>
using namespace std;
int a[100010];
int temp[100010];
void merge_sort(int *a,int start,int end)
{
    if(start+1>=end)
    return;
    int mid=start+(end-start)/2;
    int i=start,j=mid,count=start;
    merge_sort(a,start,mid);
    merge_sort(a,mid,end);
    while(i<mid||j<end)
    {
        if(j>=end||(i<mid&&a[i]<=a[j]))
        {
            temp[count++]=a[i++];
        }
        else
        temp[count++]=a[j++];
    }
    for(int v=start;v<end;v++)
    {
        a[v]=temp[v];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
