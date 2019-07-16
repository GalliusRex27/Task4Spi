#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>s[200100];
int n,m,w;
int a,b;
int in[200100],out[200100],ss[200100];
int ans=1;
 
void dfs(int x)
{
	in[ans]=x;
	out[x]=ans++;
	for(int i=0;i<s[x].size();i++)
	   dfs(s[x][i]);
	ss[x]=ans;
}
 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&w);
		s[w].push_back(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].size();j++){
		cout<<s[i][j];
	}
	cout<<endl;
    }
	dfs(1);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		if(b<=ss[a]-out[a])
		   printf("%d\n",in[out[a]+b-1]);
		else printf("-1\n");
	}
	return 0;
}
