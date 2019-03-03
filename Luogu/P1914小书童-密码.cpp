#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char in[100];
    int n,j;
    scanf("%d%s",&n,in);
    for(j=0;in[j]!='\0';j++)
        putchar((in[j]-'a'+n)%26+'a');
    return 0;
}
