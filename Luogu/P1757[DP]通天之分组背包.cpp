#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    vector<int> weight,value;
    int cnt;
    node(){
        cnt=0;
        weight.clear();
        value.clear();
    }
}a[1005];
int f[1005];
int main(){
    int m,n,x,y,z,all=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(z>all)
            all=z;
        a[z].cnt++;
        a[z].weight.push_back(x);
        a[z].value.push_back(y);
    }
    for(int i=1;i<=all;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<a[i].cnt;k++){
                if(j>=a[i].weight[k])
                    f[j]=max(f[j],f[j-a[i].weight[k]]+a[i].value[k]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
