#include <cstdio>
#include <cstdlib>
const int N=70;
int sum,mx,mn,num[N];
bool get_ans;
void dfs(int group,int now_sum,int target,int last){
    if(group==0){
        printf("%d\n",target);
        get_ans=1;
    }
    if(!get_ans){
        if(now_sum==target){
            dfs(group-1,0,target,mx);
            return;
        }
        for(int i=last;i>=mn;i--){
            if(num[i] && now_sum+i<=target){
                num[i]--;
                dfs(group,now_sum+i,target,i);
                num[i]++;
                if(!now_sum || now_sum+i==target)
                    break;
            }
        }
    }
}
int main(){
    int DC,x;
    scanf("%d",&DC);
    mn=2e9;
    while(DC--){
        scanf("%d",&x);
        if(x<=50){
            num[x]++;
            if(x>mx)
                mx=x;
            if(x<mn)
                mn=x;
            sum+=x;
        }
    }
    for(int i=mx;i<=sum;i++){
        if(sum%i==0){
            dfs(sum/i,0,i,mx);
            if(get_ans)
                break;
        }
    }
    return 0;
}