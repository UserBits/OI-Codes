#include<cstdio>
int main()
{
	int s,t,w,num[26];
	scanf("%d %d %d\n",&s,&t,&w);
	for(int i=0; i<w; i++)
	{
		num[i]=getchar();
		num[i]=num[i]-'a'+1;
	}
	for(int k=0; k<5; k++)
	{
		for(int i=w-1; i>=0; i--)
		{
			if(num[i]+1<=t-(w-1-i))
			{
				num[i]++;
				for(int j=i+1; j<w; j++)
					num[j]=num[i]+j-i;
				for(int i=0; i<w; i++)
					printf("%c",num[i]+'a'-1);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
