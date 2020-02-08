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
    int t;
    cin>>t;
    int k=1;
    while(t--){
        int n,h;
        cin>>n>>h;
        vector<int>v1(n);
        vector<int>v2(n);
        for(int i=0;i<n;i++) cin>>v1[i];
        for(int j=0;j<n;j++) cin>>v2[j];

        queue<pair<pair<ll,ll>,int>>q;
        q.push({{v1[0],0},1});
        q.push({{0,v2[0]},1});
        q.push({{v1[0],v2[0]},1});

        ll count=0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            // cout<<t.first.first<<" "<<t.first.second<<" "<<t.second<<endl;
            if(t.first.first>=h && t.first.second>=h && t.second>=n){
                count++;
                continue;
            }
            else if(t.second>=n) continue;
            q.push({{t.first.first+v1[t.second],t.first.second},t.second+1});
            q.push({{t.first.first,t.first.second+v2[t.second]},t.second+1});
            q.push({{t.first.first+v1[t.second],t.first.second+v2[t.second]},t.second+1});
            
        }
        cout<<"Case #"<<k<<": "<<count<<endl;
        k++;
    }

}