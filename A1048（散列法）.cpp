#include<cstdio>
//��Ϊɢ�����������ö��ֲ��ң�two pointers ���������
const int maxm=1100;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int hash[maxm]={0};
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        hash[t]++;
    }
    bool flag=false;
    for(int i=0;i<m;i++){
        //i<m;��Ϊ����Ӳ����ֵ����Ӧ�����ʱ��������֧�����жϽ���
        if(hash[i]){
            hash[i]--;
            if(hash[m-i]){
                printf("%d %d",i,m-i);
                flag=true;
                break;
            }
            else
                hash[i]++;
        }
    }
    if(!flag)
        printf("No Solution");
    return 0;
}
