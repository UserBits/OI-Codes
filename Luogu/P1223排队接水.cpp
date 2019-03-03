#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
    long long index,t;
    friend bool operator<(node a,node b)
    {
        if(a.t>=b.t)
            return true;
        else
            return false;
    }
};
priority_queue <node> a;
inline int read()
{
    int data=0,w=1;
    char ch=0;
    while(ch!='-' && (ch<'0' || ch>'9'))
        ch=getchar();
    if (ch=='-') w=-1,ch=getchar();
    while (ch>='0' && ch<='9')
        data=data*10+ch-'0',ch=getchar();
    return data*w;
}
inline void write(int x)
{
    if(x<0)
        putchar('-'),
    x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main()
{
    int n;
    cin>>n;
    node tmp;
    for(int i=0;i<n;i++)
    {
        tmp.index=i+1;
        tmp.t=read();
        a.push(tmp);
    }
    long long sum=0,ans=0,temp=n;
    while(!a.empty())
    {
        n--;
        sum+=a.top().t*n;
        write(a.top().index);
        printf(" ");
        a.pop();
    }
    double answer=(double)sum/temp;
    printf("\n%.2f",answer);
    return 0;
}
