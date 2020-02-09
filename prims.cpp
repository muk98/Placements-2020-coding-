#include<bits/stdc++.h>

using namespace std;

int findMST(vector<vector<int>>&grp,int n,int m){
	vector<int>parent(n);
	vector<int>distance(n,INT_MAX);  
    vector<int>minVertices(n,0);
  	
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // int root=0;

    pq.push({0,0});

   	distance[0] = 0;  
    parent[0] = -1; 
  
    while(!pq.empty()){
    	auto t = pq.top();
    	int u = t.second;
    	pq.pop();
    	minVertices[u]=1;

    	for(int i=0;i<n;i++){
    		if(i==u) continue;
    		int wght = grp[u][i];
    		if(minVertices[i]==0 && distance[i]>wght){
    			distance[i]=wght;
    			pq.push({wght,i});
    			parent[i]=u;
    		}
    	}
    }

    int sum=0;
    for(int i=1;i<n;i++){
    	sum += grp[i][parent[i]];
    }
    return sum;
}



int main(){
	int t;
	cin>>t;
	int k=1;
	while(k<=t){
		int n,m;
		cin>>n>>m;
		vector<vector<int>>grp(n,vector<int>(n,0));
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			grp[a-1][b-1]=1;
			grp[b-1][a-1]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(grp[i][j]==0){
					grp[i][j]=2;
				}
			}
		}

		cout<<"Case #"<<k<<": "<<findMST(grp,n,m)<<endl;
		k++;
	}
}