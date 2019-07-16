#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int w[10][10000];
int k;
bool check(int x,int y)
{
	for(int i=2;i<=k;i++)
		if(w[i][x]>w[i][y]) return true;
	return false;
}
int main()
{   int n;
	cin>>n>>k;
	int q[10][10000],dp[10000];
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>q[i][j];
		w[i][q[i][j]]=j;
	}
	for(int i=1;i<=n;i++) {
	dp[i]=1;}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		if(check(q[1][i],q[1][j]))
			dp[j]=max(dp[j],dp[i]+1);
	int ans=0;
	for(int i=1;i<=n;i++) 
	{ans=max(ans,dp[i]);}
	cout<<ans;
}
