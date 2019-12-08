 #include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<set>
using namespace std;
const int maxn=150;
int n;
vector <int >word(maxn);
int wolf[maxn];
set <int>lier;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int w;
		scanf("%d",&w);
		word[i]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			fill(wolf+1,wolf+n+1,1);
			lier.clear();
			wolf[i]=wolf[j]=-1;
			for(int k=1;k<=n;k++){
				int id=abs(word[k]);
				if(wolf[id]*word[k]<0){
					lier.insert(k);
					if(lier.size()>2) break;
				}
			}
			if(lier.size()==2){
				if((lier.find(i)==lier.end()&&lier.find(j)!=lier.end())||(lier.find(i)!=lier.end()&&lier.find(j)==lier.end())){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	printf("No Solution");
	return 0;
}
