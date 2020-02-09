#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define pii pair<int,int>
// #define mod 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)


signed main(){
	int mod = 1000000007;
	int n,q,a,b;
	cin>>n>>q;
	vector<int>fib(n+1);
	cin>>fib[1];
	cin>>fib[2];
	cin>>a>>b;
	for(int i=3;i<n+1;i++){
		fib[i]= ((a*fib[i-2])%mod + (b*fib[i-1])%mod)%mod;
	}
		// for(auto x:fib){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	vector<int>temp(n+1,0);
	while(q--){
		int l,r;
		cin>>l>>r;
		temp[l]= (temp[l]+fib[1])%mod;
		if(l<r) {
			temp[l+1]= (temp[l+1]+fib[2])%mod;
			temp[l+1]= (temp[l+1] + mod - (b*fib[1])%mod)%mod;
			if(r+1<n+1) temp[r+1]=(temp[r+1] + mod - (a*fib[r-l])%mod)%mod;
			if(r+1<n+1) temp[r+1] = (temp[r+1] + mod - (b*fib[r-l+1])%mod)%mod;
			if(r+2<n+1) temp[r+2]=(temp[r+2]+mod-(a*fib[r-l+1])%mod)%mod;
			// if(r+2<n+1) temp[r+2]=(temp[r+2]+mod-(b*fib[r-l+2])%mod)%mod;
		}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		else{
			if(r+1<n+1) temp[r+1] = (temp[r+1]+mod-(b*fib[1])%mod)%mod;
			if(r+2<n+1) temp[r+2] = (temp[r+2]+mod-(a*fib[1])%mod)%mod;
		}

		// for(int i=1;i<n+1;i++){
		// 	cout<<temp[i]<<" ";
		// }
		// cout<<endl;
	}

	temp[2] = (temp[2]+(b*temp[1])%mod)%mod;
	for(int i=3;i<n+1;i++){
		temp[i] += ((a*temp[i-2])%mod + (b*temp[i-1])%mod)%mod;
	}
	for(int i=1;i<n+1;i++){
		cout<<(temp[i]+v[i])%mod<<" ";
	}
	cout<<endl;
	return 0;
}