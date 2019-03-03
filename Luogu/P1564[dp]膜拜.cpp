#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m,a[2505],f[2505];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i]=2e9;
        int s1=0,s2=0;
        for(int j=i;j>0;j--){
            if(a[j]==1)
                s1++;
            else
                s2++;
            if(s1==0 || s2==0 || abs(s1-s2)<=m)
                f[i]=min(f[i],f[j-1]+1);
        }
    }
    printf("%d\n",f[n]);
    return 0;
}