#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double min(double x,double y)
{
    if(x<y)
        return x;
    return y;
}
struct node
{
	int x,y;
}p[100005];
double dis(node a,node b)
{
	double x=abs(a.x-b.x),y=(a.y-b.y);
	return sqrt(x*x+y*y);
}
double minn=0x7fffffff;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		for(int j=i-1;j>=1;j--)
			minn=min(minn,dis(p[i],p[j]));
	}
	printf("%.4lf\n",minn);
	return 0;
}

