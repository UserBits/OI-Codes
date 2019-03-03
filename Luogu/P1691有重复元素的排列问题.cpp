#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[505],b[505];
int n,s=1;
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    sort(a,a+n);
    strcpy(b,a);
    puts(a);
    while(next_permutation(a,a+n))
    {
        if(!strcmp(b,a))
            continue;
        puts(a);
        s++;
    }
    printf("%d",s);
    return 0;
}
