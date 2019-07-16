#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> pos;
bool flag;
bool visited[100][100];
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
int n,m,k;
char s[100][100];
void dfs(int x, int y)
{
	visited[x][y] = true;
	pos.emplace_back(x, y);
	if (x==0||y==0||x==n-1||y==m-1)
		flag = true;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0&&ny>=0&&nx<n&&ny<m&&s[nx][ny]!='*'&&!visited[nx][ny])
			dfs(nx, ny);
	}
}

int main(){
cin>>n;
cin>>m;
cin>>k;
for (int i = 0; i < n; ++i){
	cin>>s[i];}
vector<pair<int, vector<pair<int, int>>>>check;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!visited[i][j] && s[i][j] == '.')
			{
				flag=false;
				pos.clear();
				dfs(i, j);
				if (!flag)
					check.emplace_back(pos.size(), pos);
			}
	sort(check.begin(),check.end());
	int ans=0;
	for (int i=0;i<check.size()-k;i++)
	{
		ans += check[i].first;
		vector<pair<int, vector<pair<int, int>>>>::iterator it;
		for (auto &itr : check[i].second)
			s[itr.first][itr.second] = '*';
	}
	cout<<ans;
	for (int i = 0; i < n; ++i)
		cout<<s[i]<<endl;
	return 0;
}
