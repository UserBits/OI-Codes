#include <cstdio>
#include <cstring>
using namespace std;
int n,x,y;
char str[3000][3000];
void copy(int &p,int &q)
{
	for(int i=1; i<=p; i++)
	{
		for(int j=1; j<=q; j++)
			str[i][q+j]=str[p+i][(q/2)+j]=str[i][j];
	}
	p*=2;
	q*=2;
}
int main()
{
	memset(str,' ',sizeof(str));
	str[1][1]=str[2][2]='\\';
	str[1][2]=str[1][3]='_';
	str[1][4]=str[2][3]='/';
	x=2;
	y=4;
	scanf("%d",&n);
	for(int i=1; i<n; i++)
		copy(x,y);
	for(int i=x; i>0; i--)
	{
		for(int j=y; j>0; j--)
			putchar(str[i][j]);
		putchar('\n');
	}
	return 0;
}

