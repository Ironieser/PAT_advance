#include<cstdio>
#include<cstring>
int main()
{
    char a[30][30];
    char s[90];
    int n1,n2,n3,n;
    scanf("%s",s);
    n=strlen(s);
    n1=n3=(n+2)/3;
    n2=n+2-n1-n3;
    int t=0;
	//����㣺��ά����δ����ʼֵ���ո�
	//��ά�����Ĭ��ֵΪ����������´���
    //�����ʼ�� ȫ����ֵ�ո�
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
            a[i][j]=' ';

    }
    for(int i=0;i<n1;i++)
    {
        a[i][0]=s[t++];
    }
    for(int i=1;i<n2;i++)
        a[n1-1][i]=s[t++];
    for(int i=n3-2;i>=0;i--)
        a[i][n2-1]=s[t++];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
            printf("%c",a[i][j]);
        if(i!=n1-1) printf("\n");
    }
    return 0;
}
