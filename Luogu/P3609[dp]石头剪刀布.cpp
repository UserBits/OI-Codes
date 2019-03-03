#include <cstdio>
#include <algorithm>
using namespace std;
int f[200001][21][3];
//f[i][j][0/1/2]表示前i局变化j次第i局出石头、剪刀、布时分别能赢多少
//H(Hoof): 石头(题中指“蹄子”)
//S(Scissors): 剪刀
//P(Paper): 布
char a[200001];
inline int getval(char a,char b){
    if((a=='H'&&b=='S') || (a=='S'&&b=='P') || (a=='P'&&b=='H'))
        return 1;
    return 0;
}
inline int mx3(int a,int b,int c){
    return max(a,max(b,c));
}
inline void gc(char &c){
    c=getchar();
    while(c!='H'&&c!='P'&&c!='S')
        c=getchar();
}
int main(){
    int n,k,i,j,tmp;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
        gc(a[i]);
    for(i=1;i<=n;++i){
        f[i][0][0]=f[i-1][0][0]+getval('H',a[i]);
        f[i][0][1]=f[i-1][0][1]+getval('S',a[i]);
        f[i][0][2]=f[i-1][0][2]+getval('P',a[i]);
    }
    for(i=1;i<=n;++i){
        tmp=min(i-1,k);//前i局最多变化i-1次，由于题目有限制，取i-1和k的最小值
        for(j=1;j<=tmp;++j){
            f[i][j][0]=mx3(f[i-1][j][0],f[i-1][j-1][1],f[i-1][j-1][2])+getval('H',a[i]);
            f[i][j][1]=mx3(f[i-1][j-1][0],f[i-1][j][1],f[i-1][j-1][2])+getval('S',a[i]);
            f[i][j][2]=mx3(f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j][2])+getval('P',a[i]);
        }
    }
    printf("%d\n",mx3(f[n][k][0],f[n][k][1],f[n][k][2]));
    //system("pause");
    return 0;
}