#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,p,maxFacSum=-1;
vector<int> fac,ans,temp;
int power(int x)
{
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
void init(){
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
}
void DFS(int index , int nowK , int sum , int facsum)
{
	if(sum==n&& nowK==k){
		if(facsum>maxFacSum){
			ans=temp;
			maxFacSum=facsum;
		}
		return;
	}
	if(sum>n||nowK>k) return ;
	if(index >= 1){
		temp.push_back(index);
		DFS(index,nowK+1,sum+fac[index],facsum+index);//ѡ
		temp.pop_back();//�Ƴ����������
		DFS(index-1,nowK,sum,facsum);//��ѡ
	}
}
int main()
{
	scanf("%d %d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(maxFacSum==-1) printf("Impossible\n");
	else {
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
}