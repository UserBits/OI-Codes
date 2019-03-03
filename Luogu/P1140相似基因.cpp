#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int val[5][5]={
	5,-1,-2,-1,-3,
	-1,5,-3,-2,-4,
	-2,-3,5,-2,-2,
	-1,-2,-2,5,-1,
	-3,-4,-2,-1,0
};
int f[105][105],signa[105],signb[105];
int main()
{
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++)
			f[i][j]=-1<<30;
	}
	string a,b;
	int lena,lenb;
	cin>>lena>>a;
	cin>>lenb>>b;
	for(int i=0;i<lena;i++){
		switch(a[i]){
			case 'A':
				signa[i+1]=0;
				break;
			case 'C':
				signa[i+1]=1;
				break;
			case 'G':
				signa[i+1]=2;
				break;
			case 'T':
				signa[i+1]=3;
				break;
		}
	}
	for(int i=0;i<lenb;i++){
		switch(b[i]){
			case 'A':
				signb[i+1]=0;
				break;
			case 'C':
				signb[i+1]=1;
				break;
			case 'G':
				signb[i+1]=2;
				break;
			case 'T':
				signb[i+1]=3;
				break;
		}
	}
	for(int i=1;i<=lena;i++)
		f[i][0]=f[i-1][0]+val[signa[i]][4];
	for(int i=1;i<=lenb;i++)
		f[0][i]=f[0][i-1]+val[signb[i]][4];
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			f[i][j]=max(f[i][j],
					max(f[i-1][j]+val[signa[i]][4],
					max(f[i][j-1]+val[signb[j]][4],
					f[i-1][j-1]+val[signa[i]][signb[j]])
					));
		}
	}
	printf("%d\n",f[lena][lenb]);
    return 0;
}
