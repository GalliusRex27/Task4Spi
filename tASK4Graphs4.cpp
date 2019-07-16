#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int n,m,k,q[100000],w[100000],e[100000],a[100000],f[100000];
int find(int a){
	if (a==f[a]){
	return a;}
	return f[a]=find(f[a]);
}
int check(int mid){
	for (int i=1;i<=n;i++){
	f[i]=i;
	}
	for (int i=1;i<=m;i++)
		if (e[i]<=mid){
			int xx=find(q[i]);
			int yy=find(w[i]);
			f[xx]=yy;
		}
	for (int i=2;i<=k;i++)
		if (find(a[i])!=find(a[1]))return 0;
	return 1;	
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	cin>>a[i];
	for (int i=1;i<=m;i++){
		cin>>q[i]>>w[i]>>e[i];
	}
	int l=0,r=pow(10,9);
	while (l<r){
		int mid=(l+r)/2;
		if (check(mid))r=mid;
		else l=mid+1;
	}
	for (int i=1;i<=k;i++)
	cout<<l;
}
