#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool visited[2005][2005];
struct node{int x,y,r,l;};
queue<node>q;
int main()
{
    int n,m;
    cin>>n>>m;
    string s[n+1];
    int a,b;
    cin>>a>>b;
    int x,y;
    cin>>x>>y;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int total=0;
    q.push({a-1,b-1,x,y});
    while(!q.empty()){
        node temp=q.front();
        q.pop();
        int x=temp.x,y=temp.y;
        if(visited[x][y]) continue;
        visited[x][y]=1;
        total++;
        if(x>0 && s[x-1][y]=='.'){
		q.push({x-1,y,temp.r,temp.l});}
        if(x<n-1 && s[x+1][y]=='.'){
		q.push({x+1,y,temp.r,temp.l});}
        if(y>0 && s[x][y-1]=='.' && temp.x>0){
		q.push({x,y-1,temp.r-1,temp.l});}
        if(y<m-1 && s[x][y+1]=='.' && temp.y>0){
		q.push({x,y+1,temp.r,temp.l-1});}
    }
    cout<<total<<endl;
    return 0;
}
