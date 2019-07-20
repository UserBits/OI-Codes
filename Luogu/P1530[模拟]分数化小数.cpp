#include <cstdio>
#include <cstdlib>

using namespace std;

int p[100005],q[100005];
int get_len(int x){
    if(x==0)
        return 1;
    int s=0;
    while(x){
        x/=10,s++;
    }
    return s;
}
int main(){
    int n,y,cnt=0;
    scanf("%d%d",&n,&y);
    int t=n/y;
    printf("%d.",t);
    cnt+=get_len(t)+1;
    if(n%y==0){
        printf("0");
        return 0;
    }
    int x=n%y;
    int k=0;
    while(x>0){
        q[++k]=(x*10)/y;
        if(p[x]==0)
            p[x]=k;
        else{
            for(int i=1;i<p[x];i++){
                printf("%d",q[i]),cnt++;
                if(cnt==76)
                    cnt=0,putchar('\n');
            }
            printf("("),cnt++;
            if(cnt==76)
                cnt=0,putchar('\n');
            for(int i=p[x];i<k;i++){
                printf("%d",q[i]),cnt++;
                if(cnt==76)
                    cnt=0,putchar('\n');
            }
            printf(")"),cnt++;
            if(cnt==76)
                cnt=0,putchar('\n');
            break;
        }
        x=(x*10)%y;
    }
    if(!x){
        for(int i=1;i<=k;i++){
            printf("%d",q[i]),cnt++;
            if(cnt==76)
                cnt=0,putchar('\n');
        }
    }
    //system("pause");
}