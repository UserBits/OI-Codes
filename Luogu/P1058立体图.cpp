#include <cstdio>
using namespace std;
int i,j,k,m,n,debug,tmp,array[1005][1005],value_x,value_y,d1[6]={2,1,0,0,0,0},d2[6]={6,6,6,6,5,4};
char str[1005][1005],jpg[20][20]=
{
	"  +---+",
	" /   /|",
	"+---+ |",
	"|   | +",
	"|   |/",
	"+---+",
};
inline void read(int &s)
{
	char c=getchar();
	s=0;
	for(;c<'0' || c>'9';c=getchar());
	for(;c>='0' && c<='9';c=getchar())
		s=(s<<1)+(s<<3)+(c-'0');
}
void function(int x,int y)
{
    int i,j;
    for(i=5;i>=0;i--)
    {
        for(j=d1[i];j<=d2[i];j++)
        {
            str[5-i+x][j+y]=jpg[i][j];
            if(5-i+x>value_x)
				value_x=5-i+x;
            if(j+y>value_y)
				value_y=j+y;
        }
    }
}
int main()
{
    read(n);
    read(m);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
            read(array[i][j]);
    }
    for(tmp=1;tmp<=n;tmp++)
    {
        for(k=0;k<m;k++)
        {
            for(debug=0;debug<array[tmp][k];debug++)
                function((n-tmp)*2+1+3*debug,(n-tmp)*2+1+4*k);
		}
	}
    for(i=value_x;i>=1;i--)
    {
        for(j=1;j<=value_y;j++)
        {
            if(str[i][j]=='\0')
				putchar('.');
            else
				putchar(str[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

