#include<stdio.h>
#include<string.h>
using namespace std;
int stack[10005],top=0;
char s[1005];
int main()
{
	memset(stack,0,sizeof(stack));
	scanf("%s",s);
	int i=0,x=0;
	while(i<=strlen(s)-2)
	{
		switch(s[i])
		{
			case '+':
				stack[--top]+=stack[top+1];
				break;
			case '-':
				stack[--top]-=stack[top+1];
				break;
			case '*':
				stack[--top]*=stack[top+1];
				break;
			case '/':
				stack[--top]/=stack[top+1];
				break;
			default:
				x=0;
				while(s[i]!='.')x=x*10+s[i++]-'0';
				stack[++top]=x;
				break;
		}
		i++;
	}
	printf("%d\n",stack[top]);
	return 0;
}
