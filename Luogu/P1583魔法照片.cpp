#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct person
{
	int id,w;
}p[10000001];
int n,k,e[11];
bool cmp(person a,person b)
{
	if(a.w==b.w) return a.id<b.id;
	return a.w>b.w;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1; i<=10; i++)
		scanf("%d",&e[i]);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&p[i].w);
		p[i].id=i+1;
	}
	sort(p,p+n,cmp);
	for(int i=0; i<n; i++)
		p[i].w+=e[i%10+1];
	sort(p,p+n,cmp);
	for(int i=0; i<k; i++)
		cout<<p[i].id<<' ';
	return 0;
}

