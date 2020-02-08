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

void dfs(vector<int>&visited,vector<vector<int>>&adj,int u,vector<int>&parent,vector<vector<int>>&cost,vector<vector<vector<int>>>&dp,int root){
    visited[u]=1;
    for(auto v:adj[u]){
        if(!visited[v]){
            parent[v]=u;
            dfs(visited,adj,v,parent,cost,dp,root);
        }
    }

    if(adj[u].size()==1 && u!=root){
        // cout<<u<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) 
                if(i!=j) dp[u][i][j] = cost[u][i];
        }
    }
    else{
        for(auto v:adj[u]){
            if(u==parent[v]){
                for(int i=0;i<3;i++){
                    if(i==0){
                        dp[u][i][1]= dp[v][1][2]+cost[u][i];
                        dp[u][i][2]= dp[v][2][1]+cost[u][i];
                    }
                    else if(i==1){
                        dp[u][i][0]= dp[v][0][2]+cost[u][i];
                        dp[u][i][2]= dp[v][2][0]+cost[u][i];
                    }
                    else{
                        dp[u][i][1]= dp[v][1][0]+cost[u][i];
                        dp[u][i][0]= dp[v][0][1]+cost[u][i];
                    }
                }
            }
        }
    }
}

void dfs2(vector<int>&vis,vector<vector<int>>&adj,int u,vector<int>&col,queue<int>&q){
    vis[u]=1;
    col[u] = q.front();
    q.pop();
    q.push(col[u]);
    for(auto x:adj[u]){
        if(!vis[x]){
            dfs2(vis,adj,x,col,q);
        }
    }
}

signed main(){
    int n;
    cin>>n;
    vector<vector<int>>cost(n,vector<int>(3,0));
   
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>cost[j][i];
        }
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int flag=0;
    int root=0;

    for(int i=0;i<n;i++){
        if(adj[i].size()>2){
            flag=1;
        }
        if(adj[i].size()==1){
            root = i;
        }
    }
    if(flag==1){
        cout<<-1<<endl;
        return 0;
    }

    if(n==1){
        if(cost[0][0]<=cost[0][1] && cost[0][0]<=cost[0][2]){
            cout<<cost[0][0]<<endl;
            cout<<1<<endl;
        }
        else if(cost[0][1]<=cost[0][0] && cost[0][1]<=cost[0][2]){
            cout<<cost[0][1]<<endl;
            cout<<2<<endl;
        }
        else{
            cout<<cost[0][2]<<endl;
            cout<<3<<endl;
        }
        return 0;
    }
    vector<int>visited(n,0);
    vector<int>parent(n,-1);
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(3,LONG_LONG_MAX)));
    dfs(visited,adj,root,parent,cost,dp,root);
    int ans = LONG_LONG_MAX;
    int ai,aj,ak;
    vector<int>col(n,0);
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            if(dp[root][j][k]<ans){
                ans = dp[root][j][k];
                ai = j;
                aj = k;
            }
        } 
    }

    queue<int>q;
    q.push(ai);
    q.push(aj);
    if((ai==0 && aj==1) || (ai==1 && aj==0)){
        q.push(2);
    }
    else if((ai==1 && aj==2) || (ai==2 && aj==1)){
        q.push(0);
    }
    else{
        q.push(1);
    }
    vector<int>vis(n,0);
    dfs2(vis,adj,root,col,q);

    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        cout<<col[i]+1<<" ";
    }
    cout<<endl;
}