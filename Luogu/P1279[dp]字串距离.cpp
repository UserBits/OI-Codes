#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
char x[2001],y[2001];
int f[2001][2001];
inline int dis(char a,char b){
    return abs(a-b);
}
int main(){
    int n,m,c;
    scanf("%s%s%d",x+1,y+1,&c);
    n=strlen(x+1);      m=strlen(y+1);
    for(int i=1;i<=n;i++)
        f[i][0]=c*i;
    for(int i=1;i<=m;i++)
        f[0][i]=c*i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            f[i][j]=min(f[i-1][j-1]+dis(x[i],y[j]),min(f[i-1][j],f[i][j-1])+c);
    }
    printf("%d",f[n][m]);
    //system("pause");
    return 0;
}