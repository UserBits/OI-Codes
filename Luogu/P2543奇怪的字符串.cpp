#include <cstring>
#include <iostream>
using namespace std;
int dp[5005][5005];
char a[10005],b[10005];
int main()
{
	int len1,len2,i,j;
	cin>>a+1>>b+1;
	len1=strlen(a+1);
	len2=strlen(b+1);
	for(i=1; i<=len1; i++)
	{
		for(j=1; j<=len2; j++)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[len1][len2]<<endl;
	return 0;
}

