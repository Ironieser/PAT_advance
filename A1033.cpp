#include<cstdio>
#include<algorithm>
using namespace std;
struct Sta
{
    double price;
    double distance;
}sta[550];
bool cmp(Sta a,Sta b)
{
    if(a.distance!=b.distance)
        return a.distance<b.distance;
    else
        return a.price<b.price;
}

//************************
//提前写好算法步骤，着重注意判断条件
//本题一个错误：测试点2： 起点无加油站的情况
//其他错误：在计算加油的花费时，应该为
//需要的油减去油箱剩余的油：mone+= (temp- gas)*price ；
//************************
int main()
{
    double  c,maxdis,per;
    int n;
    double maxmove;
    scanf("%lf%lf%lf%d",&c,&maxdis,&per,&n);
    maxmove=c*per;//一箱油的最大移动距离
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&sta[i].price,&sta[i].distance);
    }
    double money=0;
    double gas=0;
    sort(sta,sta+n,cmp);
    for(int i=0;i<n;i++){
        double temp;
        if(sta[0].distance!=0) {printf("The maximum travel distance = 0.00");return 0;};
        //第一个加油站不在起点
        if(i+1<n){temp=(sta[i+1].distance-sta[i].distance)/per;}//到下一站需要的油
        else{temp=(maxdis-sta[i].distance)/per;}//若为最后一个加油站;
        if(temp>c){////判断能否到达下一站，超过油箱容量
            printf("The maximum travel distance = %0.2lf",sta[i].distance+maxmove);
            return 0;
        }

        if(sta[i+1].price<sta[i].price||i==n-1){//下一站油便宜或此站位为最后一站；
            if(i==n-1){temp=maxdis-sta[i].distance;temp/=per;}
            else temp=(sta[i+1].distance-sta[i].distance)/per;
            //求到下一站需要的油
            if(gas<temp){//剩下的油不够到下一站
                money+=(temp-gas)*sta[i].price;
                gas=0;
            }
            else{//剩下的油够到下一站
                gas-=temp;
            }
        }
        else{//下一站油贵
            bool flag=false;//是否找到
            for(int j=i;j<n;j++){
            //在可行驶最大距离内寻找下一个更便宜的加油站,直接行驶到更便宜的加油站
                if(sta[j].price<sta[i].price&&sta[j].distance-sta[i].distance<=maxmove){
                    temp=(sta[j].distance-sta[i].distance)/per;
                    flag=true;
                    if(gas<temp){//剩下的油不够
                        money+=(temp-gas)*sta[i].price;
                        gas=0;
                    }
                    else{
                        gas-=temp;
                    }
                    i=j-1;
                    break;
                }
            }
            if(!flag){//没有找到;邮箱加满，向下个加油站前进
                if(maxmove<=maxdis-sta[i].distance){//行驶不到终点
                    temp=c-gas;
                    money+=temp*sta[i].price;
                    gas=c-(sta[i+1].distance-sta[i].distance)/per;
                }
                else{//直接行驶到终点
                    temp=(maxdis-sta[i].distance)/per;
                    money+=(temp-gas)*sta[i].price;
                    break;
                }
            }
        }
    }
    printf("%0.2lf",money);
    return 0;
}
