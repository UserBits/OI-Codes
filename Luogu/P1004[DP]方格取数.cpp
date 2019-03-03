#include <iostream>
using namespace std;
#define F(i) for(int i = k; i >= 0; --i)
int n,mp[20][20], dp[20][20];
int main()
{
    cin>>n;
    int x, y, m;
    while(cin>>x>>y>>m, !(x==0 && y==0 && m==0 ))
        mp[y][x]=m;
    for(int k=1;k<=2*n-1; ++k)
        F(j) F(l)
        {
            int y1=k-j+1,y2=k-l+1;
            dp[j][l]=max(max(dp[j][l],dp[j-1][l]),max(dp[j][l-1],dp[j-1][l-1]))+(j==l?mp[y1][j]:mp[y1][j]+mp[y2][l]);
        }
    cout<<dp[n][n]<<endl;
    return 0;
}

