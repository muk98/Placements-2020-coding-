#include<bits/stdc++.h>
using namespace std;

int check(int mid,int C,vector<int > v){
	int count=1; 
	int curr = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		if(v[i]-curr>=mid){
			if(++count==C) return 1;
			curr = v[i];
		}
	}
	return 0;
}

int main(){
	int n,c;
	cin>>n>>c;
	// vector<vector<int>>v(r,vector<int>(c,0))
	// dp[30][30];
	// memset(v,0,sizeof(v));
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
	sort(v.begin(),v.end());
	int lo = 0;
	int high = v[n-1] - v[0] +1;
	int mid;
	while(high-lo>1){
		mid = ( high + lo)>>1;
		int flag = check(mid,c,v);
		if(flag==1) lo = mid;
		else high = mid;
	}
	cout<<lo;
}