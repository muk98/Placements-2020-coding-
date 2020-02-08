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


int n;

int findNonOverLap(string s1,string s2){
    int i=0,j=0;
    int n=s1.size();
    int m =s2.size();
    for(int i=0;i<n;i++){
        // int k=0;
        int flg=1;
        int j=0;
        for(j=0;j<m && i+j<n;j++){
            if(s1[i+j]!=s2[j]){
                flg=0;
                break;
            }
        }
        if(flg){
            int l = m-(n-i);
            return j==m?0:l;
        }
    }
    return m;
}


int buildSoln(vector<string>&v,vector<vector<int>>&dp,int finalMask,int mask,int last,vector<vector<int>>&preprocess,string& strans){
    if(mask == finalMask){
        dp[last+1][mask]=0;
        return 0;
    }

    if(dp[last+1][mask]!=-1){
        return dp[last+1][mask];
    }

    int ans = INT32_MAX;
    string t;
    for(int i=0;i<n;i++){
        if(!((mask>>i)&1)){
            int tmp = last!=-1? preprocess[last][i]:v[i].size();
            ans = min(ans,buildSoln(v,dp,finalMask,mask|(1<<i),i,preprocess,strans)+tmp);
            
        }
    }
    dp[last+1][mask] = ans;
    return ans;
}


signed main(){
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.pb(s);
    }
    vector<vector<int>>preprocess(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            preprocess[i][j] = findNonOverLap(v[i],v[j]);
            preprocess[j][i] = findNonOverLap(v[j],v[i]);
        }
    }
    int finalMask = (1<<n)-1;
    vector<vector<int>>dp(n+1,vector<int>(finalMask+1,-1));
    int mask=0;
    string strans;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            dp[i][j]=-1;
        }
    }
    int ans = buildSoln(v,dp,finalMask,mask,-1,preprocess,strans);
    cout<<ans<<endl;

}