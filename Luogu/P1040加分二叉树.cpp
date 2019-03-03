// luogu-judger-enable-o2
//#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll f[35][35];
int val[35],root[35][35];
inline void __Print_Out_(int _Dfs_Left,int _Dfs_Right)
{
	if(_Dfs_Left>_Dfs_Right)
		return;
	if(_Dfs_Left==_Dfs_Right)
	{
		cout<<_Dfs_Left<<" ";
		return;
	}
	cout<<root[_Dfs_Left][_Dfs_Right]<<' ';
	__Print_Out_(_Dfs_Left,root[_Dfs_Left][_Dfs_Right]-1);
	__Print_Out_(root[_Dfs_Left][_Dfs_Right]+1,_Dfs_Right);
}
int main()
{
	int n;
	cin>>n;
	/*
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			f[i][j]=1;
	}*/
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		//root[i][i]=i;
		f[i][i]=val[i];
		f[i][i-1]=1;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			register int tp=-1<<60;
			for(int k=i;k<=j;k++)
			{
				if(f[i][k-1]*f[k+1][j]+f[k][k]>f[i][j])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					root[i][j]=k;
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	__Print_Out_(1,n);//while(1);
	return 0;
}