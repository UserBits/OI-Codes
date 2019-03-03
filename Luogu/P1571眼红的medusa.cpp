#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,b[100005];
struct Node
{
	int s,id;
} a[100005];
inline bool cmp1(Node a,Node b)
{
	return a.s<b.s;
}
inline bool cmp2(Node a,Node b)
{
	return a.id<b.id;
}
int main()
{
	scanf ("%d%d",&n,&m);
	for (int i=0; i<n; i++)
		scanf ("%d",&a[i].s),a[i].id=i;
	for (int i=0; i<m; i++)
		scanf ("%d",&b[i]);
	sort(a,a+n,cmp1);
	sort(b,b+m);
	int i=0,j=0;
	for (; i<n; i++)
	{
		while (b[j]<a[i].s && j<m)
			j++;
		if (b[j]!=a[i].s)
			a[i].s=0;
	}
	sort(a,a+n,cmp2);
	for (i=0; i<n; i++)
	{
		if (a[i].s)
			printf("%d ",a[i].s);
	}
	return 0;
}
