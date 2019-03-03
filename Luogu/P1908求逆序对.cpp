#include <cstdio>
int array[100005],temp[100005],number,now,ans;
inline void merge_sort(int left,int right)
{
    if(left>=right)
        return;
    int mid=(left+right)>>1;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int i=left,j=mid+1,k=left;
    while(i<=mid && j<=right)
	{
        if(array[i]<=array[j])
            temp[k++]=array[i++];
        else
        {
            temp[k++]=array[j++];
			ans+=(mid-i+1);
		}
    }
    while(i<=mid)
        temp[k++]=array[i++];
    while(j<=right)
        temp[k++]=array[j++];
    for(i=left;i<=right;i++)
        array[i]=temp[i];
}
int main()
{
    scanf("%d",&number);
	now=number;
    for(int i=1;i<=number;i++)
        scanf("%d",&array[i]);
    merge_sort(1,number);
	printf("%d\n",ans);
    return 0;
}
