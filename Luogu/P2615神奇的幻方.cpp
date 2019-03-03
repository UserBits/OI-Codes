#include<iostream>
#include<cstring>
using namespace std;
int n,pi,pj;
int map[50][50];
int main()
{
    cin>>n;
    memset(map,0,sizeof(map));
    map[1][n/2+1]=1;
    pi=1;
    pj=n/2+1;
    for(int i=2;i<=n*n;i++)
    {
        if((pi==1)&&(pj!=n))
        {
            map[n][pj+1]=i;
            pi=n;
            pj=pj+1;
            continue;
        }
        if((pi!=1)&&(pj==n))
        {
            map[pi-1][1]=i;
            pi=pi-1;
            pj=1;
            continue;
        }
        if((pi==1)&&(pj==n))
        {
            map[pi+1][pj]=i;
            pi=pi+1;
            continue;
        }
        if((pi!=1)&&(pj!=n))
        {
            if(map[pi-1][pj+1]==0)
            {
                map[pi-1][pj+1]=i;
                pi=pi-1;
                pj=pj+1;
            }
            else
            {
                map[pi+1][pj]=i;
                pi=pi+1;
            }
            continue;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
