#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int num,loc;
}a[100005],b[100005];
int array[100005],temp[100005],ans;
const int mod=99999997;
inline bool cmp(node x,node y)
{
    return x.num<y.num;
}
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
			ans%=mod;
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
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].loc=i;
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        b[i].loc=i;
        scanf("%d",&b[i]);
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
        array[a[i].loc]=b[i].loc;
    merge_sort(1,n);
    printf("%d\n",ans);
}
