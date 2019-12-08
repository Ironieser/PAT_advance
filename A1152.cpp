#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<string>

using namespace std;
int L, K;

string e;
bool IsPrime(int a)//质数判断
{
	if (a<2) return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)
			return false ;
	}
	return true;
}
int q2num(queue<int> q)//队列转为 int 整数
{
	int num=0;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		num=10*num+a;
	}
	return num;
}
bool flag=false;
int main()
{
	int aaa=5235360287;
	cout<<IsPrime(aaa);
	return 0;
	queue<int > q;
#ifdef _DEBUG
	ifstream cin("a.txt");
#endif
	cin>>L>>K;
	if(L<K) cout <<"404";
	else {
		int num=L-K+1;
		cin>>e;
		int i=0;
		for(i=0;i<K;i++){
			q.push(e[i]-'0');
		}
		while(num--){
			int a=q2num(q);
			if(IsPrime(a)){
				while(!q.empty()){
					cout<<q.front();
					q.pop();
				}
				flag=true;
				break;
			}else{
				if(i==L) break;
				q.pop();
				q.push(e[i]-'0');
				i++;
			}
		}
		if(!flag) cout<<"404";
	}


#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}