#include<cstdio>
const int maxn=100200;
int arr[maxn];
int p[maxn];//������ֵ�λ��
int count=0;
void Swap(int a,int b)
{//��arr[i]��0�����������潻����ĵ�ַ
    a=0;
    int temp=p[b];
    p[b]=p[a];
    p[a]=temp;

    arr[p[a]]=a;
    arr[p[b]]=b;
    count++;
}
//*************************
///����һ��k������¼���ڱ�λ����С����
///ÿ��0�ص���λ���㿪ʼ�����ж������Ƿ���ص���λ
///һ������δ�ص���λ�����֣����¼λ��k
//*************************
int k=1;
int  isok(int n)
{
    for( int i=k;i<n;i++){
        if(arr[i]!=i){
            k=i;
            return i;
        }
    }
    return -1;
}
//*************************
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp;
        p[temp]=i;//������Ϊ�Ǳ꣬�������λ��;
    }
//*************************************
///�˴���Ϊ�㷨���󣬲����������С�Ľ�������
///�ھ����㷨ʱ��Ӧ��ʹ�����������ж�
//***************************************
//    for(int i=1;i<n;i++){
//        if(arr[i]!=i){//�����i��λ�ò���i
//            if(arr[i]!=0){//�����i��λ�ò���0��
//                Swap(arr[i]);//��arr[i]��0�����������潻����ĵ�ַ
//            }
//            Swap(arr[p[i]]);//��0���λ�õ���������
//        }
//    }
//***********************************
    while(isok(n)!=-1){
        if(arr[0]!=0){
            int tag=p[0];//0����λ�õ�,���λ��Ӧ��Ӧ��������
            Swap(0,tag);
        }
        else{
            int tag;
            tag=isok(n);
            if(tag==-1) break;
            else {
                Swap(0,tag);
            }
        }
    }
    printf("%d",count);
}
