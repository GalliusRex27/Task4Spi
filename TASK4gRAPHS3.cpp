#include<bits/stdc++.h>
#include<math.h>
using namespace std;
bool visited[1<<22]={0};
bool arr[1<<22]={0};
int n,m,x,r;
void dfs(int a)
{
    if(visited[a])
        return;
    visited[a]=true;
    for(int b=1;b<=a;b<<=1)
    {
        if(a&b)
            dfs(a^b);
    }
    if(arr[a])
        dfs(a^r);
}
int main()
{
	int ans=0;
    cin>>n>> m;
    r=(1<<n)-1;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        arr[x]=1;
    }
    for(int i=0;i<(1<<n);i++)
    {
        if((1-visited[i])&arr[i])
        {
            dfs(r^i);
            ans++;
        }
    }
    cout <<ans<< endl;
    return 0;
}

