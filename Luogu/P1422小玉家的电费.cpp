#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    float s=0;
    scanf("%d",&n);
    if(n<=150)
        s+=n*0.4463;
    if(n>=151 && n<=400)
        s+=150*0.4463+(n-150)*0.4663;
    if(n>=401)
        s+=150*0.4463+250*0.4663+(n-400)*0.5663;
    printf("%.1f",s);
    return 0;
}
