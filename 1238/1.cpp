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


bool isPossible(vector<int>&v,int minn,int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]<minn){
            cnt += (minn-v[i]);
        }
    }
    if(cnt<=k) return true;
    else return false;
}


bool isPossible2(vector<int>&v,int maxx,int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]>maxx){
            cnt += (v[i]-maxx);
        }
    }
    if(cnt<=k) return true;
    else return false;
}

int fun1(vector<int>v,int n,int k){
    int l=0;
    int r=INT_MAX;
    int m;
    while(l<r){
        int mid= l+(r-l+1)/2;
        // cout<<mid<<" "<<l<<" "<<r<<endl;
        if(isPossible(v,mid,n,k)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]<l){
            k -= (l-v[i]);
            v[i]=l;
        }
    }
    int minn=l;
    l=0;
    r=INT_MAX;
    while(l<r){
        int mid= l+(r-l-1)/2;
        if(!isPossible2(v,mid,n,k)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
	for(int i=0;i<n;i++){
        if(v[i]>r){
            k -= (v[i]-r);
            v[i]=r;
        }
    }
    cout<<r<<" 1 "<<minn<<" "<<k<<endl;
    return r-minn;
}

int fun2(vector<int>v,int n,int k){
    int l=0;
    int r=INT_MAX;
    while(l<r){
        int mid= l+(r-l-1)/2;
        if(!isPossible2(v,mid,n,k)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }

    for(int i=0;i<n;i++){
        if(v[i]>r){
            k -= (v[i]-r);
            v[i]=r;
        }
    }
    int maxx=r;
	// cout<<"maxx "<<maxx<<" "<<k<<endl;
    l=0;
    r=INT_MAX;
    while(l<r){
        int mid= l+(r-l+1)/2;
        // cout<<mid<<" "<<l<<" "<<r<<endl;
        if(isPossible(v,mid,n,k)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
	for(int i=0;i<n;i++){
        if(v[i]<l){
            k -= (l-v[i]);
            v[i]=l;
        }
    }

	cout<<maxx<<" 2 "<<l<<" "<<k<<endl;
    return (maxx-l);
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
	cout<<fun1(v,n,k)<<" \n"<<fun2(v,n,k)<<endl;
    // cout<<min(,)<<endl;
    return 0;
}   