#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[7],f[1000005];
int main(){
    int sum=0;
    for(int i=1;i<=6;i++){
        scanf("%d",&a[i]);
        sum+=a[i]*i;
    }
    int cnt=1;
    while(a[6]||a[1]||a[2]||a[3]||a[4]||a[5]){
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=6;i++){
            for(int j=sum/2;j>=i;j--){
                for(int k=1;k<=a[i];k++){
                    if(j>=i*k&&f[j-i*k])
                        f[j]=1;
                }
            }
        }
        printf("Collection #%d:\n",cnt);
        if(sum&1)
            puts("Can't be divided.\n");
        else{
            if(f[sum/2])
                puts("Can be divided.\n");
            else
                puts("Can't be divided.\n");
        }
        sum=0;
        cnt++;
        for(int i=1;i<=6;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*i;
        }
    }
    //system("pause");
    return 0;
}