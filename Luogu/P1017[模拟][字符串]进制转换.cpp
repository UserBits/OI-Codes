#include <cstdio>
using namespace std;
int work(int n,int m,char str[])
{
    int i=0,tmp;
    while(n!=0)
    {
        tmp=n%m;
        n/=m;
        if(tmp<0)
		{
			tmp-=m;
			n+=1;
		}
        if(tmp>9)
			str[i]=(char)(tmp-10+'A');
        else
			str[i]=(char)(tmp+'0');
        i++;
    }
    return i-1;
}
int main()
{
    int m,n;
    char r[40];
    scanf("%d%d",&m,&n);
    printf("%d=",m);
    if(m==0)
		printf("0");
    for(int i=work(m,n,r);i>=0;i--)
  		putchar(r[i]);
    printf("(base%d)\n",n);
    return 0;
}

