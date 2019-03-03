#include <iostream>
#include <cstdio>
#include <stdlib.h>
int map[10]= {9,9,9,9,9,9,9,9,9,9};
int rules[8][3]=
{
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{1,4,7},
	{2,5,8},
	{3,6,9},
	{1,5,9},
	{3,5,7}
};
int now=-1;
void pexit(char *fmt)
{
	puts(fmt);
	exit(0);
}
void judge()
{
	for(int i=0; i<8; i++)
		if(map[rules[i][0]]==1 && map[rules[i][1]]==1 && map[rules[i][2]]==1)
			pexit("xiaoa wins.");
		else if(map[rules[i][0]]==-1 && map[rules[i][1]]==-1 && map[rules[i][2]]==-1)
			pexit("uim wins.");
}
int main()
{
	char ch;
	while((ch=getchar())!='\n')
	{
		map[ch-'0']=(now=-now);
		judge();
	}
	puts("drew.");
	return 0;
}
