#include<cstdio>
const int maxm=100500;
int a[maxm]={-1};
bool hash[maxm]={false};
int m,n;
bool isprime(int a)
{
    if(a<=1) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(!isprime(m)){
        do{
            m++;
        }while(!isprime(m));
    }
    for(int i=0;i<n;i++){
        int t=a[i]%m;
        if(i!=0) printf(" ");
        if(!hash[t]){
            printf("%d",t);
        }
        else{
        ///�����
        //���η�����̽�鷨 �� temp=a + step*step
        //if(step<Tsize) step++ ;
            int step=0;
            do{//����������
                step++;
                if(step>m) break;
                int temp=a[i]+step*step;
                t=temp%m;
            }while(hash[t]);
            if(!hash[t]){
                printf("%d",t);
            }
            else printf("-");
        }
        hash[t]=true;
    }
    return 0;
}
