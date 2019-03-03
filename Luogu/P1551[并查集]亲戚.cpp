#include <cstdio>
#include <cstdlib>
int f[5005];
inline int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}
inline void Union(int x,int y){
    int tx=Find(x),ty=Find(y);
    if(tx!=ty)
        f[ty]=tx;
}
int main(){
    int n,m,p,x,y;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        f[i]=i;
    while(m--){
        scanf("%d%d",&x,&y);
        Union(x,y);
    }
    while(p--){
        scanf("%d%d",&x,&y);
        puts(Find(x)==Find(y)?"Yes":"No");
    }
    //system("pause");
    return 0;
}