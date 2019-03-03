#include<iostream>
#include<algorithm>
using namespace std;
struct node{int number;int score;};
bool cmp(node line1,node line2){
    if(line1.score==line2.score) return (line1.number<line2.number);
        else return (line1.score>line2.score);
}
int main()
{
    node player[10000];
    int m,n,peoper=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>player[i].number>>player[i].score;
    sort(player+1,player+n+1,cmp);
    m=m*1.5;
    while(player[m].score==player[m+1].score) m++;
    cout<<player[m].score<<' '<<m<<endl;
    for(int i=1;i<=m;i++)
        cout<<player[i].number<<' '<<player[i].score<<endl;
    return 0;
}
