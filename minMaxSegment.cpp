#include<bits/stdc++.h>

using namespace std;

#define ll long long


int maxQuery(vector<int>&sgmntTree,int rs,int re,int ss,int se,int index){
	if(rs<=ss && re>=se){
		return sgmntTree[index];
	}

	if(rs>se || re<ss) return INT_MIN;

	int mid = (ss+se)/2;

	return max(maxQuery(sgmntTree,rs,re,ss,mid,2*index+1),maxQuery(sgmntTree,rs,re,mid+1,se,2*index+2));

}


int buildTree(vector<int>&arr,vector<int>&sgmntTree,int s,int e,int pos){
	if(s==e){
		sgmntTree[pos]=arr[s];
		return sgmntTree[pos];
	}

	int mid = (s+e)/2;
	sgmntTree[pos] = max(buildTree(arr,sgmntTree,s,mid,2*pos+1),buildTree(arr,sgmntTree,mid+1,e,2*pos+2));
	return sgmntTree[pos];
}


void buildSegmentTree(vector<int>&arr,vector<int>sgmntTree){
	int n = arr.size();
	int h = ceil(log2(n));

	int size = 2*pow(2,h)-1;
	sgmntTree.resize(size);

	buildTree(arr,sgmntTree,0,n-1,0);
}

int main(){
	int n,w;
	cin>>n>>w;
	vector<vector<int>>sgmntTrees(n);
	vector<int>size(n);
	for(int i=0;i<n;i++){
		int aw;cin>>aw;
		size[i]=aw;
		vector<int>v(aw);
		for(int i=0;i<aw;i++){
			cin>>v[i];
		}
		buildSegmentTree(v,sgmntTrees[i]);
	}

	int ans=0;
}