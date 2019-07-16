#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int A[n];
	int B[m][2];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	long cost=0;
	for(int i=0;i<m;i++){
		int r,l;
		cin>>r>>l;
		cost+=min(A[r-1],A[l-1]);
	}
	cout<<cost;
	return 0;
}
