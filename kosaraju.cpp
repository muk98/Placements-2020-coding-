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

int n,tim=0;
int start[100005];
int finish[100005];
int visited[100005];

void dfs(int u,vector<vector<int>>&grp){
	visited[u]=1;
	start[u]= ++tim;
	// cout<<u<<endl;;
	rep(i,0,grp[u].size()){
		if(visited[grp[u][i]]) continue;
		
		dfs(grp[u][i],grp);
	}
	finish[u]=++tim;
}


void dfs(int u,vector<vector<int>>&grp,vector<int>&temp){
	visited[u]=1;
	rep(i,0,grp[u].size()){
		if(visited[grp[u][i]])
			continue;
		temp.push_back(grp[u][i]);
		dfs(grp[u][i],grp,temp);
	}
}

void buildTranspose(vector<vector<int>>&grp,vector<vector<int>>&transGrp){
	for(int i=0;i<n;i++){
		for(int j=0;j<grp[i].size();j++)
		transGrp[grp[i][j]].pb(i); 
	}
}

signed main(){
	int m;
	cin>>n>>m;
	vector<vector<int>>grp(n);
	memset(finish,0,sizeof(finish));
	memset(start,0,sizeof(start));
	memset(visited,0,sizeof(visited));

	rep(i,0,m){
		int a,b;
		cin>>a>>b;
		grp[a-1].push_back(b-1);
	}
	int flg=1;
	rep(i,0,n){
		if(visited[i]==0)
			dfs(i,grp);
	}
	vector<pair<int,int>>fin(n);
	for(int i=0;i<n;i++){
		fin[i]={finish[i],i};
	}
	sort(fin.begin(),fin.end(),greater<pair<int,int>>());

	memset(visited,0,sizeof(visited));
	vector<vector<int>>scc;
	vector<vector<int>>transpGrp(n);
	buildTranspose(grp,transpGrp);

	for(int i=0;i<n;i++){
		int u = fin[i].second;
		vector<int>temp;
		if(visited[u]==0){
			temp.push_back(u);
			dfs(u,transpGrp,temp);
			scc.push_back(temp);
		}
	}
	
	// for(auto x:scc){
	// 	for(auto y:x)
	// 		cout<<y+1<<" ";
	// 	cout<<endl;
	// }

	int size = scc.size();
	cout<<scc[size-1].size()<<endl;
	for(int i=0;i<scc[size-1].size();i++)
		cout<<scc[size-1][i]+1<<" ";
	cout<<endl;
	return 0;
}