#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; 
	char A[n-1]; 
	cin>>n>>A;
	for (int i=0;i<n;i++) {
		int l=i-1, r=i, x=1, y=1;
		while(A[l]!='L'&&l>=0)
		{
		x+=1; 
		l--;}
		while(A[r]!='R'&&r<n) 
		{
		y+=1;
		r++;}
		if(x>y){
			cout<<x;
		}
		else{
			cout<<y;
		}
	}
}
