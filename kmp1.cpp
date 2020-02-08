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


void preprocess(string s,int n,vector<int>&pr){
    int k=0;
    pr[0]=pr[1]=0;
    for(int i=2;i<=n;i++){
        k=pr[i-1];
        while(k>0 && s[i-1]!=s[k]){
            k=pr[k];
        }
        if(s[i-1]==s[k])k++;
        pr[i]=k;
    }
}


int kmp(vector<int>&pr,string p,string t,int n){
    int k=0;
    int maxi=-1;
    int indx = 0;
    for(int i=1;i<=2*n;i++){
        while(k>0 && t[(i-1)%n]!=p[k]){
            k = pr[k];
        }
        if(t[(i-1)%n]==p[k]){
            k++;
            if(k>maxi){
                maxi= k;
                indx = i-k;
            }
        }
    }
    return indx;
}

signed main(){
    int n;
    string p;
    string t;
    cin>>n;
    cin>>p>>t;
    t+=t;
    vector<int>pr(n+1,0);
    preprocess(p,n,pr);
    for(auto x:pr) cout<<x<<" ";
    cout<<endl;
    cout<<kmp(pr,p,t,n)<<endl;
    return 0;
}