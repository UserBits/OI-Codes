#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct abcd
{
	long long size;
	int dpt;
	abcd() {}
	abcd(long long _,int __):
		size(_),dpt(__) {}
	friend bool operator<(const abcd &x,const abcd &y)
	{
		if(x.size!=y.size)
			return x.size>y.size;
		return x.dpt>y.dpt;
	}
};
int n,k,ans2;
long long ans1;
priority_queue<abcd> heap;
void Merge(int cnt)
{
	long long _size=0;
	int _dpt=0;
	while(cnt--)
	{
		abcd temp=heap.top();
		heap.pop();
		_size+=temp.size;
		_dpt=max(_dpt,temp.dpt);
	}
	ans1+=_size;
	ans2=max(ans2,++_dpt);
	heap.push(abcd(_size,_dpt));
}
int main()
{
	int i;
	long long x;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		scanf("%lld",&x);
		heap.push(abcd(x,0));
	}
	if((n-1)%(k-1)+1!=1 && n!=1)
		Merge(min((n-1)%(k-1)+1,n));
	while(heap.size()>1)
		Merge(min(k,(int)heap.size()));
	cout<<ans1<<'\n'<<ans2<<endl;
	return 0;
}

