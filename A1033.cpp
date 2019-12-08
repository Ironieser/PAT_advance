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
//��ǰд���㷨���裬����ע���ж�����
//����һ�����󣺲��Ե�2�� ����޼���վ�����
//���������ڼ�����͵Ļ���ʱ��Ӧ��Ϊ
//��Ҫ���ͼ�ȥ����ʣ����ͣ�mone+= (temp- gas)*price ��
//************************
int main()
{
    double  c,maxdis,per;
    int n;
    double maxmove;
    scanf("%lf%lf%lf%d",&c,&maxdis,&per,&n);
    maxmove=c*per;//һ���͵�����ƶ�����
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&sta[i].price,&sta[i].distance);
    }
    double money=0;
    double gas=0;
    sort(sta,sta+n,cmp);
    for(int i=0;i<n;i++){
        double temp;
        if(sta[0].distance!=0) {printf("The maximum travel distance = 0.00");return 0;};
        //��һ������վ�������
        if(i+1<n){temp=(sta[i+1].distance-sta[i].distance)/per;}//����һվ��Ҫ����
        else{temp=(maxdis-sta[i].distance)/per;}//��Ϊ���һ������վ;
        if(temp>c){////�ж��ܷ񵽴���һվ��������������
            printf("The maximum travel distance = %0.2lf",sta[i].distance+maxmove);
            return 0;
        }

        if(sta[i+1].price<sta[i].price||i==n-1){//��һվ�ͱ��˻��վλΪ���һվ��
            if(i==n-1){temp=maxdis-sta[i].distance;temp/=per;}
            else temp=(sta[i+1].distance-sta[i].distance)/per;
            //����һվ��Ҫ����
            if(gas<temp){//ʣ�µ��Ͳ�������һվ
                money+=(temp-gas)*sta[i].price;
                gas=0;
            }
            else{//ʣ�µ��͹�����һվ
                gas-=temp;
            }
        }
        else{//��һվ�͹�
            bool flag=false;//�Ƿ��ҵ�
            for(int j=i;j<n;j++){
            //�ڿ���ʻ��������Ѱ����һ�������˵ļ���վ,ֱ����ʻ�������˵ļ���վ
                if(sta[j].price<sta[i].price&&sta[j].distance-sta[i].distance<=maxmove){
                    temp=(sta[j].distance-sta[i].distance)/per;
                    flag=true;
                    if(gas<temp){//ʣ�µ��Ͳ���
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
            if(!flag){//û���ҵ�;������������¸�����վǰ��
                if(maxmove<=maxdis-sta[i].distance){//��ʻ�����յ�
                    temp=c-gas;
                    money+=temp*sta[i].price;
                    gas=c-(sta[i+1].distance-sta[i].distance)/per;
                }
                else{//ֱ����ʻ���յ�
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
