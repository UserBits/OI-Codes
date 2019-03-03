#include <cstdio>
#include <cstdlib>
int a[300001];
int main(){
    int n,k,l=1,r=1,ans=0,sum=0,x,y;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        register char c=getchar();
        while(c<'0'||c>'1') c=getchar();
        a[i]=c-'0';
    }
    while(r<=n){
        sum+=1^a[r];
        while(sum>k)
            sum-=1^a[l++];
        if(r-l+1>ans){
            ans=r-l+1;
            x=l; y=r;
        }
        r++;
    }
    for(int i=x;i<=y;i++)
        a[i]=1;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}