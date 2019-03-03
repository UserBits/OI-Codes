#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a[n], b[n];
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++) cin>>b[i];
	int ok[8], ok5[3] = {0};
	for(int i = 1; i < 8; i++)ok[i] = 3;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] != b[j][n-i-1]) ok[1] = 0;
			if(a[n-i-1][n-j-1] != b[i][j]) ok[2] = 0;
			if(a[j][n-i+1] != b[i][j]) ok[3] = 0;
			if(a[i][n-j-1] != b[i][j]) ok[4] = 0;
			if(a[i][n-j-1] != b[j][n-i-1] && !ok5[0]) ok[5]--, ok5[0]++;
			if(a[n-i-1][n-(n-j-1)-1] != b[i][j]&& !ok5[1]) ok[5]--, ok5[1]++;
			if(a[n-j-1][n-i+1] != b[i][j]&& !ok5[2]) ok[5]--, ok5[2]++;
			if(a[i][j] != b[i][j]) ok[6] = 0;
		}
	}
	for(int i = 1; i < 8; i++)
		if(ok[i])
		{
			cout<<i<<endl;
			return 0;
		}
	cout<<7<<endl;
	return 0;
}

