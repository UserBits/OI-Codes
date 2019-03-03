#include <cstdio>
#include <cstdlib>
struct node{
    int x,y,z,c;
}a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].c);
    int ans=1<<30,id=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i].x<a[j].x && a[i].y<a[j].y && a[i].z<a[j].z){
                a[i].c=1<<30;
                break;
            }
        }
        if(a[i].c<ans){
            ans=a[i].c;
            id=i;
        }
    }
    printf("%d\n",id);
    return 0;
}