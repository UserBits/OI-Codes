#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,sum,A,B,C,D,a[40005],f[20005],ans[20005][5];

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i];
        f[a[i]]++;
    }

    for (int i=1;i<=2000;i++){
        sum=0;
        for (A=n-9*i-1;A>=1;A--){
            B=A+2*i; C=A+8*i+1; D=A+9*i+1;
            sum+=f[C]*f[D];
            ans[A][1]+=f[B]*sum;
            ans[B][2]+=f[A]*sum;
        }

        sum=0;
        for (C=2+8*i;C<=n;C++){
            A=C-8*i-1; B=C-6*i-1; D=C+i;
            sum+=f[A]*f[B];
            ans[C][3]+=f[D]*sum;
            ans[D][4]+=f[C]*sum;
        }
    }

    for (int i=1;i<=m;i++)
        cout<<ans[a[i]][1]<<' '<<ans[a[i]][2]<<' '<<ans[a[i]][3]<<' '<<ans[a[i]][4]<<'\n';

    return 0;
}
