#include <cstdio>
int a[10005];
int mx(int x,int y){
    return x>y?x:y;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0,l,r;
    for(int i=1;i<=n;i++){
        l=r=i;
        while(a[l]>=a[l-1] && l>1)
            l--;
        while(a[r]>=a[r+1] && r<n)
            r++;
        ans=mx(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
