#include <cstdio>
#include <cstring>
char st[101];
int main()
{
	int a=-1,b=-1,flag=-1,js=-2,wz=-2;
	gets(st+1);
	int len=strlen(st+1);
	for(int i=1; i<=len; i++)
	{
		if(st[i]==' ')
			continue;
		if(st[i]>='0' && st[i]<='9')
		{
			if(flag==-1)
			{
				a=0;
				while(1)
				{
					if(st[i]==' ')
						i++;
					else if(st[i]>='0' && st[i]<='9')
					{
						a=a*10+st[i]-'0';
						i++;
					}
					else
						break;
				}
				flag=0;
			}
			else if(flag==0)
			{
				b=0;
				while(1)
				{
					if(st[i]==' ')
						i++;
					else if(st[i]>='0' && st[i]<='9')
					{
						b=b*10+st[i]-'0';
						i++;
					}
					else
						break;
				}
			}
		}
		if(st[i]=='+')
			js=-1;
		else if(st[i]=='-')
			js=0;
		if(st[i]=='?')
		{
			if(a==-1 && b==-1)
				wz=-1;
			else if(a!=-1 && b==-1)
				wz=0;
			else if(a!=-1 && b!=-1)
			{
				if(js==-1)
					printf("%d",a+b);
				else if(js==0)
					printf("%d",b-a);
				return 0;
			}
		}
	}
	if(wz==-1)
	{
		if(js==-1)
			printf("%d",b-a);
		else if(js==0)
			printf("%d",a+b);
	}
	else if(wz==0)
	{
		if(js==-1)
			printf("%d",b-a);
		else if(js==0)
			printf("%d",a-b);
	}
	return 0;
}

