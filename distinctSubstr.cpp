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


int pos[100005];
int gap=1;
int n;

bool mycomp(int i,int j){
    if(pos[i]!=pos[j]) return pos[i]<pos[j];

    i+=gap;
    j+=gap;
    return (i<n && j<n)?pos[i]<pos[j]: i>j;
}


void buildSA(string s,vector<int>&sa,vector<int>&temp){
    rep(i,0,s.size()){
        pos[i]=s[i];
        sa[i]=i;
    }
    
    for(gap=1;;gap*=2){
        sort(sa.begin(),sa.end(),mycomp);
        rep(i,0,n-1) temp[i+1] = temp[i] + mycomp(sa[i],sa[i+1]);
        rep(i,0,n) pos[sa[i]] = temp[i];
        if(temp[n-1]==n-1) break;
    }

}


void buildLCP(vector<int>&sa,vector<int>&lcp,string s){
    int k=0;
    rep(i,0,n){
        if(pos[i]!=n-1){
            for(int j=sa[pos[i]+1];s[i+k]==s[j+k] && i+k<n && j+k<n;){
                k++;
            }
            lcp[pos[i]] = k;
            if(k) k--;
        }
    }   
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        memset(pos,0,sizeof(pos));
        vector<int>sa(n);
        vector<int>lcp(n);
        vector<int>temp(n);
        buildSA(s,sa,temp);
        buildLCP(sa,lcp,s);

        int s1 = accumulate(lcp.begin(),lcp.end(),0LL);
        int sum = (((n*(n+1))/2)%mod - s1%mod)%mod;
        cout<<sum<<endl;
    }
    
}