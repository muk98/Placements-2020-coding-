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

signed main(){
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int>d(n);
        for(int i=0;i<n;i++) cin>>d[i];
        sort(d.begin(),d.end());
        int r = d[n-1]+1;
        int l = 0;
        int mid=0;
        while(l<r){
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            mid = (l+r+1)/2;
            int cow=1;
            int curr=0;
            // int dis=0;
            for(int i=0;i<n;i++){
                int dis = d[i]-d[curr]; 
                if(dis>=mid){
                    cow++;
                    curr=i;
                }
            }
            if(cow>=c){
                l=mid;
            }
            else r=mid-1;
        }
        cout<<l<<endl;
    }
    return 0;
}