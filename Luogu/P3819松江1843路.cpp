#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	long long pos,cost;
}a[100005];
inline bool cmp(node x,node y){
	return x.pos<y.pos;
}
int main()
{
	int n,l;
	long long sum=0;
	scanf("%d%d",&l,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].pos,&a[i].cost);
		sum+=a[i].cost;
	}
	long long tp=(sum+1)>>1,mid,ans=0;
	sort(a+1,a+1+n,cmp);
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].cost;
		if(sum>tp){
			mid=a[i].pos;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		ans+=abs(mid-a[i].pos)*a[i].cost;
	cout<<ans<<endl;
    return 0;
}
