#include<cstdio>
#include<algorithm>
using namespace std;
int s1[200050];
//һ��ʼ�ڴ������ѡ�������һ�����飬
//����ʼ¼��ڶ����飬ֱ�ӽ����жϣ�
int main()
{
    int n1,n2;
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&s1[i]);
    }
    s1[n1]=(1<<31)-1;
    scanf("%d",&n2);
    int mid=(n1+n2-1)/2;
    int i=0,num=0;
    int temp;
    for(int j=0;j<n2;j++){
        scanf("%d",&temp);
        if(num==mid){//����Ҫ�����֣�������λ�����ж����
            printf("%d",min(temp,s1[i]));
            return 0;
        }
        while(temp>=s1[i]) {//����������ִ�������һ��������������һ��ָ��
                i++;num++;//�±�+1������+1
                if(num==mid){
                    printf("%d",min(temp,s1[i]));
                    return 0;
                }
        }
        num++;//����¼�������������һ���ж�
    }
    printf("%d",s1[mid-n2]);//�����ȫ�����룬��λ��δ�������������һ�ж�Ӧλ�ô�ӡ
    return 0;
}
