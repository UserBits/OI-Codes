#include<iostream>
#include<algorithm>
using namespace std;
int N,ans,a[10010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>a[i];
    make_heap(a,a+N,cmp);
    ans=0;
    for(int i=N;i>1;i--)
    {
        pop_heap(a,a+i,cmp);
        pop_heap(a,a+i-1,cmp);
        a[i-2]+=a[i-1];
        ans+=a[i-2];
        push_heap(a,a+i-1,cmp);
    }
    cout<<ans<<endl;
    return 0;
}
