#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int main(){
    int q;cin>>q;
    while(q--){
        ll n;cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        map<ll,vector<int>>mp;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(mp.find(v[i])==mp.end()){
                temp.push_back(v[i]);
            }
            mp[v[i]].push_back(i);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int cnt++;
        for(int i=0;i<n-1;i++){
            int m = mp[temp[i+1]].size();
            int a = mp[temp[i]][0];
            int b = mp[temp[i+1]][n-1];
            if(b>a){
                cnt++;
            }
        }
    }

}