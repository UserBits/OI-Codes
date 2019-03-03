#include<cstdio>
int n,m,ans,l=1,r,que[1001];
bool have[1001];
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x;scanf("%d",&x);
        if(!have[x])
        {
            ++ans;
            if(r-l+1==n)have[que[l++]]=false;
            have[x]=true;
            que[++r]=x;
        }
    }
    printf("%d\n",ans);
}
