#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)


void dfs(int u,vector<vector<int>>&adj,vector<pair<int,int>>&trav,vector<int>&visited,int height){
    visited[u]=1;
    trav.push_back({u,height});
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(v,adj,trav,visited,height+1);
            trav.push_back({u,height});
        }
    }
}

signed main(){
    int t;
    cin>>t;
    int ss=1;
    while(ss<=t){
        int n;
        cin>>n;
        vector<vector<int>>adj(n+1);
        for(int i=1;i<=n;i++){
            int c;
            cin>>c;
            while(c--){
                int a;
                cin>>a;
                adj[a].push_back(i);
                adj[i].push_back(a);
            }
        }
        
        vector<pair<int,int>>trav;
        vector<int>visited(n+1,0);
        dfs(1,adj,trav,visited,0);

        map<int,int>mp;
        int k = trav.size();
        for(int i=0;i<trav.size();i++){
            if(mp.find(trav[i].first)==mp.end()){
                mp[trav[i].first]=i;
            }
        }
        int maxSize = ceil(log2(k));
        vector<vector<pair<int,int>>>sptbl(k,vector<pair<int,int>>(maxSize+1,{INT_MAX,-1}));

        for(int j=0;j<=maxSize;j++){
            for(int i=0;i<k;i++){
                if(i+(1<<j)-1<k){
                    // sptbl[i][j] = j? min(sptbl[i][j-1].first,sptbl[i+(1<<(j-1))][j-1]): trav[i].second;
                    if(j==0){
                        sptbl[i][j].first = trav[i].second;
                        sptbl[i][j].second = trav[i].first;
                    }
                    else {
                        if(sptbl[i][j-1].first<sptbl[i+(1<<(j-1))][j-1].first){
                            sptbl[i][j].first = sptbl[i][j-1].first;
                            sptbl[i][j].second = sptbl[i][j-1].second;
                        }
                        else{
                            sptbl[i][j].first = sptbl[i+(1<<(j-1))][j-1].first;
                            sptbl[i][j].second = sptbl[i+(1<<(j-1))][j-1].second;
                        }
                    }
                }
            }
        }
        
        int q;
        cin>>q;
        cout<<"Case "<<ss<<":"<<endl;
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            int l = min(mp[a],mp[b]);
            int r = max(mp[a],mp[b]);
            // cout<<l<<" "<<r<<endl;
            int x = log2(r-l+1);
            if(sptbl[l][x].first < sptbl[r-(1<<x)+1][x].first){
                cout<<sptbl[l][x].second<<endl;
            }
            else cout<<sptbl[r-(1<<x)+1][x].second<<endl;
        }
        ss++;
    }
    return 0;

}   