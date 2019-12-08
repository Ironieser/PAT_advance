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
const int maxn=10040;
int n,m;
vector<int>nott[100000];
set<int> st;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int id,w;
		scanf("%d%d",&id,&w);
		nott[id].push_back(w);
		nott[w].push_back(id);
	}
	while(m--){
		int k;
		scanf("%d",&k);
		st.clear();
		for(int i=0;i<k;i++){
			int good;
			scanf("%d",&good);
			st.insert(good);
		}
		set<int >::iterator it;
		bool flag=true;
		for(it=st.begin();it!=st.end()&&flag;it++){
			if(nott[*it].size()!=0){
				for(int i=0;i<nott[*it].size()&&flag;i++){
					if(st.find(nott[*it][i])!=st.end()){	
						flag=false;
						break;					
					}
				}

			}
		}
		if(flag){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	
	}
	return 0;
}