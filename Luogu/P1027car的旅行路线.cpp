#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
int test_case;
int n;
int air_p;
int st,ed;
int mp[401][3];
int k;
double mon[401][401];
void find_way();
double get_price(int a,int b);
int main(){
    cin>>test_case;
    for(int i=0;i<test_case;i++){
        cin>>n>>air_p>>st>>ed;
        int x1,x2,x3,x4;
        int y1,y2,y3,y4;
        int pic;
        int temp1,temp2,temp3;
        k=0;
        for(int j=0;j<n;j++){
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>pic;
            temp1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            temp2 = (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
            temp3 = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
            if(temp1>temp2){
                if(temp1>temp3){
                    x4 = x1+x2-x3;
                    y4 = y1+y2-y3;
                }else{
                    x4 = x3+x2-x1;
                    y4 = y3+y2-y1;
                }
            }else{
                if(temp2>temp3){
                    x4 = x1+x3-x2;
                    y4 = y1+y3-y2;
                }else{
                    x4 = x3+x2-x1;
                    y4 = y3+y2-y1;
                }
            }
            mp[k][0]=x1,mp[k][1]=y1,mp[k][2]=pic,k++;
            mp[k][0]=x2,mp[k][1]=y2,mp[k][2]=pic,k++;
            mp[k][0]=x3,mp[k][1]=y3,mp[k][2]=pic,k++;
            mp[k][0]=x4,mp[k][1]=y4,mp[k][2]=pic,k++;
        }
//        for(int j=0;j<k;j++){
//            cout<<mp[j][0]<<" "<<mp[j][1]<<" "<<mp[j][2]<<endl;
//            cout<<get_price(0,j)<<endl;
//        }
        find_way();
        double te = mon[st*4-4][ed*4-4];
        for(int xi=0;xi<4;xi++){
            for(int xj=0;xj<4;xj++){
                if(te>mon[st*4-4+xi][ed*4-4+xj]){
                    te = mon[st*4-4+xi][ed*4-4+xj];
                }
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1)<<te<<endl;
    }
    return 0;
}
void find_way(){

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
        mon[i][j]=get_price(i,j);
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            for(int xi=0;xi<k;xi++){
                mon[j][xi] = min(mon[j][xi],mon[j][i]+mon[i][xi]);
            }
        }
    }
}
double get_price(int a,int b){
    int xx = (mp[a][0]-mp[b][0])*(mp[a][0]-mp[b][0])+(mp[a][1]-mp[b][1])*(mp[a][1]-mp[b][1]);
    if(a/4==b/4){
        return sqrt(xx)*mp[a][2];
    }else{
        return sqrt(xx)*air_p;
    }
}

