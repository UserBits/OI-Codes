#include<cstdio>
#include<cmath>
using namespace std;
char s[40005];
int main()
{
	//freopen("testdata.in","r",stdin);
	int len=0;
	char p;
	while((p=getchar())!=EOF)
	{
		if(p>='0' && p<='9')
			s[len++]=p;
	}
	int n=(int)sqrt(len*1.0),t=0;
	char now='0';
	printf("%d ",n);
	for(int i=0;i<=len;i++)
	{
		if(s[i]==now)
			t++;
		else
		{
			now=s[i];
			printf("%d ",t);
			t=1;
		}
	}
	return 0;
}

