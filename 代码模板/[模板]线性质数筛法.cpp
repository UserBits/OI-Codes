#include <cstdio>
const int N=1000005,M=200005;
bool np[N];
int p[M];
int work(){
    int s=0;
    for(int i=2;i<N;i++){
        if(!np[i])
            p[++s]=i;
        for(int j=1;j<=s && i*p[j]<N;j++){
            np[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
    return s;
}
int main(){
    int cnt=work();
    return 0;
}