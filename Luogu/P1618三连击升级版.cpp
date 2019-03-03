#include<iostream>
#include<cstdio>
using namespace std;
bool funcation(int a,int b,int c)
{
    int a1=a/100,b1=b/100,c1=c/100;
    int a2=a/10%10,b2=b/10%10,c2=c/10%10;
    int a3=a%10,b3=b%10,c3=c%10;
    int p=a1+a2+a3+b1+b2+b3+c1+c2+c3;
    int q=a1*a2*a3*b1*b2*b3*c1*c2*c3;
    if(p==45 && q==362880)
        return 1;
    else
        return 0;
}
int main()
{
    int x,y,z;
    int i,j,k;
    bool p=0;
    scanf("%d%d%d",&i,&j,&k);
    for(x=100;x<1000;x++)
    {
        y=x*1.0/i*j;
        z=x*1.0/i*k;
        if(funcation(x,y,z)==1)
        {
            printf("%d %d %d\n",x,y,z);
            p=1;
        }
    }
    if(p==0)
        printf("No!!!\n");
    return 0;
}
