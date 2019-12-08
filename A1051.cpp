#include<cstdio>
#include<stack>

const int maxn=1050;
using namespace std;
stack<int> st;
int main()
{
	int m,n,k;
	int seq[maxn];
	scanf("%d%d%d",&m,&n,&k);
	while(k--){
		for(int i=0;i<n;i++){
			scanf("%d",&seq[i]);
		}
		while(!st.empty()){//	Çå¿ÕÕ»
			st.pop();
		}
		bool flag=true;
		int num=0;
		for(int i=1;i<=n;i++){
			st.push(i);
			if(st.size()>m){
				flag=false;
				break;
			}
			while(!st.empty()&&st.top()==seq[num]){
				st.pop();
				num++;
			}
		}
		if(st.empty()&&flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}