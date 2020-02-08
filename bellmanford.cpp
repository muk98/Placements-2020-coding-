#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

// typedef long long int ll;
typedef long double ld;
#define int long long

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

// <set>.order_of_key(key) returns  iterator to the k-th largest element
//	<set>.order_of_key(key) returns the number of items in a set that are strictly smaller than our item


#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define out1(a) cout<<a<<endl
#define rep(i,a,b) for (int i = a; i < b; ++i)

signed main(){
    int n,m;
    cin>>n>>m;
	vector<vector<int>>grp(n,vector<int>(n,INT_MAX));
    rep(i,0,m){
		int a,b,c;
		cin>>a>>b>>c;
		grp[a][b]=c;
	}
    int p;
    cin>>p;
    vector<vector<int>>dp(2,vector<int>(n,INT_MAX));
    dp[0][0]=0;
    for(int i=1;i<n;i++){
        dp[i%2][0]=0;
        for(int j=1;j<n;j++){
            for(int k=0;k<n;k++){
                if(grp[k][j]!= INT_MAX && dp[(i)%2][j] > dp[(i-1)%2][k] + grp[k][j]){
                    dp[(i)%2][j] = dp[(i-1)%2][k] + grp[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[(n-1)%2][i]<<" ";
    }
    cout<<endl;
    return 0;
    
}