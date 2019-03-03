#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[2005],f[2005][2005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i][i]=n*a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			register int j=i+len-1;
			if(j>n)
				break;
			f[i][j]=max(f[i+1][j]+a[i]*(n-len+1),f[i][j-1]+a[j]*(n-len+1));
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
