#include<cstdio>
//˼·��
//�����ַ�Ϊ��ߣ���ǰλ���ұ�������
//���չ��ɣ����ݵ�ǰλ��1�Ĺ�ϵ���������
//��λΪ1�����ֵ��ܸ���
//��temp>1  ,num=(left+1)*t;
//��temp==1,num=(left)*t+right+1;
//��temp==0,num=(left)*t
int main()
{
    int n,left,right,t=1;
    int ans=0;
    scanf("%d",&n);
    while(n/t!=0){
        right=n%t;
        left=n/(t*10);
        int temp;
        temp=n/t%10;
        if(temp>1){
            ans+=(left+1)*t;
        }
        else if(temp==1){
            ans+=(left)*t+right+1;
        }
        else{
            ans+=(left)*t;
        }
        t*=10;
    }
    printf("%d",ans);
    return 0;
}
