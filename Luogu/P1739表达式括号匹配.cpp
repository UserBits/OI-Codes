#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
char a;
bool flag;
int main()
{
    stack<char>sum;
    while(1)
    {
        cin>>a;
        if(a=='@')
            break;
        if(a=='(')
            sum.push(a);
        if(a==')')
        {
            if(!sum.empty())
                sum.pop();
            else
                flag=1;
        }
    }
    if(flag || !sum.empty())
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
