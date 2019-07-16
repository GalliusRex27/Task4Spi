#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int num,vis[100000];
int k;
long ans;
vector<int>G[100000];
long P(int x){
	long temp=1;
	for(int i=1;i<=k;i++)
		(temp*=x)%=(long)(pow(10,9)+7);
	return temp;
}
void dfs(int x){
	num++;
	vis[x]=1;
	for(auto itr:G[x])
	if(!vis[itr]) dfs(itr);
}
int main(){
	int n;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int l,r,x;
		cin>>l>>r>>x;
		if(x==0){
			G[l].push_back(r);
			G[r].push_back(l);
		}
	}
	ans=P(n);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			num=0;
			dfs(i);
			ans=(ans-P(num)+(long)(pow(10,9)+7))%long(pow(10,9)+7);
		}
	cout<<ans;
}
