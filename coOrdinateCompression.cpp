#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 100001

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>obstacles;
	for(int i=0;i<2*m;i++){
		int a,b;cin>>a>>b;
		obstacles.push_back({a,b});
	}

	set<int>x;
	set<int>y;

	for(int i=0;i<2*m;i++){
		// cout<<obstacles[i].first<<" "<<obstacles[i].second<<endl;
		x.insert(obstacles[i].first);
		y.insert(obstacles[i].second);
	}
	map<int,pair<int,int>>rowmp;
	// map<int,int>newRow;
	int curr=0;
	int prev = 0;
	for(auto it=x.begin();it!=x.end();it++){
		if(*it==0  || *it==prev){
			rowmp[curr++]={*it,*it};
		}
		else{
			rowmp[curr++]={prev,*it-1};
			rowmp[curr++]={*it,*it};
		}
		prev=*it+1;
	}
	if(*x.rbegin()!=n-1){
		rowmp[curr]={prev,n-1};
	}
	// for(auto n:y) cout<<n<<endl;

	map<int,pair<int,int>>colmp;
	// map<int,int>newRow;
	curr=0;
	prev = 0;
	for(auto it=y.begin();it!=y.end();it++){
		// cout<<"tt "<<*it<<" "<<prev<<endl;
		if(*it==0 || *it==prev){
			colmp[curr++]={*it,*it};
		}
		else{
			colmp[curr++]={prev,*it-1};
			colmp[curr++]={*it,*it};
		}
		prev=*it+1;
	}

	if(*y.rbegin()!=n-1){
		colmp[curr]={prev,n-1};
	}

	cout<<"row"<<endl;
	for(auto x:rowmp){
		cout<<x.first<<" "<<(x.second.second-x.second.first+1)<<endl;
	}
	cout<<"coln"<<endl;
	for(auto y:colmp){
		cout<<y.first<<" "<<(y.second.second-y.second.first+1)<<endl;
	}

	
}