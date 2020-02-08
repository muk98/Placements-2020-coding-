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

void preprocess(vector<int>&pre,string s,int n){
    int i=0;
    int j=0;
    pre[0]=pre[1]=0;
    for(int i=2;i<=n;i++){
        j=pre[i-1];
        while(j>0 && s[j]!=s[i-1]){
            j = pre[j];   
        }
        if(s[j]==s[i-1]) j++;
        pre[i]=j;
    }
}

signed main(){
    string pat;
    cin>>pat;
    int n = pat.size();
    vector<int>pre(n+1,0);
    preprocess(pre,pat,n);
    for(auto x:pre) cout<<x<<" ";
    cout<<endl;
}