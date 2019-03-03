#include<iostream>
#include<algorithm>
using namespace std;
int N,M,a[10010];
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>a[i];
    for(int i=0;i<M;i++)
        next_permutation(a,a+N);
    for(int i=0;i<N-1;i++)
        cout<<a[i]<<" ";
    cout<<a[N-1]<<endl;
    return 0;
}
