#include<cstdio>
int main()
{
    char mp[]={'S','H','C','D','J'};
    int start[55]={0};
	int end[55]={0};
    for(int i=1;i<=54;i++)//????????
        start[i]=i;
    int k,list[55];
    scanf("%d",&k); //???????
    for(int i=1;i<=54;i++)//??????????????
        scanf("%d",&list[i]);
    for(int j=0;j<k;j++)
    {
        for(int i=1;i<=54;i++)
        {
            end[list[i]]=start[i];//????????????end??
        }
        for(int i=1;i<=54;i++)
        {
            start[i]=end[i];//copy end to start
        }
    }
//    for(int i=1;i<=53;i++)
//    {
//        printf("%c%d ",start[i]%13==0?mp[start[i]/13-1]:mp[start[i]/13],start[i]%13==0?13:start[i]%13);
//        // start[i]/13 ???????start[i]%13??????
//    }
//    printf("%c%d",start[54]%13==0?mp[start[54]/13-1]:mp[start[54]/13],start[54]%13==0?13:start[54]%13);//??¦Â????

	 for(int i=1;i<=54;i++)
	{
		if(i!=1) printf(" ");
		start[i]--;
		printf("%c%d",mp[start[i]/13],start[i]%13+1);
		//?????? 13/13 = 1 ?? 13%13=0?????
		//start[i]-1 ????????? 0/13=0 ?? 12/13=0?? 0%13+1=1 ??12%13+1=13
	}
	return 0;
}

