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
	vector<vector<pair<int,int>>>grp(n);
    rep(i,0,m){
		int a,b,c;
		cin>>a>>b>>c;
		grp[a].push_back({b,c});
        grp[b].push_back({a,c});
	}

    int p;
    cin>>p;
    vector<int>dis(n,INT_MAX);
    dis[p]=0;
    set<pair<int,int>>s;
    s.insert({dis[p],p});
    int cost=0;
    vector<int>path;
    while(!s.empty()){
        // cout<<"set\n";
        // for(auto x:s){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        auto t = s.begin();
        s.erase(s.begin());
        cost +=  t->first;
        int v = t->second;
        path.push_back(v);

        for(auto p:grp[v]){
            int u = p.first;
            int w = p.second;
            if(dis[u] > dis[v] + w){
                s.erase({dis[u],u});
                dis[u] = dis[v] + w;
                s.insert({dis[u],u});
            }
        }
    }

    cout<<cost<<endl;
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}