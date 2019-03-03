#include<bits/stdc++.h>
using namespace std;
char a[50],b[50],d[50];
int n;
int main()
{
	int i;
	scanf("%d",&n);
	while(n--)
	{
		int x=0,y=0,xy,XY,l1,l2,num=0,tmp=1;
		char c;
		scanf("%s",a);
		if(a[0]=='a'||a[0]=='b'||a[0]=='c')
		{
			c=a[0];
			scanf("%s%s",b,d);
			l1=strlen(b);
			l2=strlen(d);
			for(i=l1-1; i>=0; i--)
			{
				x+=(b[i]-'0')*tmp;
				tmp*=10;
			}
			tmp=1;
			for(i=l2-1; i>=0; i--)
			{
				y+=(d[i]-'0')*tmp;
				tmp*=10;
			}
			if(a[0]=='a')
			{
				xy=x+y,XY=x+y;
				while(xy>0)
				{
					num++;
					xy/=10;
				}
				if(XY==0)
					num=1;
				printf("%d+%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
			else if(a[0]=='b')
			{
				xy=x-y,XY=x-y;
				if(XY>0)
					while(xy>0)
					{
						num++;
						xy/=10;
					}
				if(XY==0)
					num=1;
				if(XY<0)
				{
					xy=-xy;
					while(xy>0)
					{
						num++;
						xy/=10;
					}
					num++;
				}
				printf("%d-%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
			else if(a[0]=='c')
			{
				xy=x*y,XY=x*y;
				while(xy>0)
				{
					num++;
					xy/=10;
				}
				if(XY==0)
					num=1;
				printf("%d*%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
		}
		else
		{
			scanf("%s",b);
			l1=strlen(a);
			l2=strlen(b);
			for(i=l1-1; i>=0; i--)
			{
				x+=(a[i]-'0')*tmp;
				tmp*=10;
			}
			tmp=1;
			for(i=l2-1; i>=0; i--)
			{
				y+=(b[i]-'0')*tmp;
				tmp*=10;
			}
			if(c=='a')
			{
				xy=x+y,XY=x+y;
				while(xy>0)
				{
					num++;
					xy/=10;
				}
				if(XY==0)
					num=1;
				printf("%d+%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
			else if(c=='b')
			{
				xy=x-y,XY=x-y;
				if(XY>0)
					while(xy>0)
					{
						num++;
						xy/=10;
					}
				if(XY==0)
					num=1;
				if(XY<0)
				{
					xy=-xy;
					while(xy>0)
					{
						num++;
						xy/=10;
					}
					num++;
				}
				printf("%d-%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
			else if(c=='c')
			{
				xy=x*y,XY=x*y;
				while(xy>0)
				{
					num++;
					xy/=10;
				}
				if(XY==0)
					num=1;
				printf("%d*%d=%d\n%d\n",x,y,XY,l1+l2+num+2);
			}
		}
	}
	return 0;
}

