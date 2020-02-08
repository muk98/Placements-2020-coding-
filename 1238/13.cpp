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
    int t;cin>>t;
    int k=1;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<vector<int>>bit(2,vector<int>(64,0));
        for(int i=0;i<n;i++){
            int t = v[i];
            int j=63;
            while(j>=0){
                int l=t%2;
                bit[l][j]++;
                j--;
                t/=2;
            }
        }
        int maxi;
        for(int i=0;i<64;i++){
            if(bit[1][i]>0){
                maxi=i;
                break;
            }
        }

        int temp = m;
        int j=63;
        vector<int>tt(64,0);
        while(j>=0){
            if(temp%2) tt[j]=1;
            j--;
            temp/=2;
        }
        for(int i=0;i<64;i++){
            if(tt[i]==1){
                // cout<<i<<" "<<maxi<<endl;
                maxi=min(maxi,i);
                break;
            }
        }
        ll ans=0;
        ll ans1=0;
        int flag=0;
        for(int i=maxi;i<64;i++){
            int k = bit[0][i];
            int k2 = bit[1][i];
            ll temp = ans+k*(pow(2,(64-i-1)));
            if(temp<=m){
                ans += k*(pow(2,(64-i-1)));
                ans1 += pow(2,(64-i-1));
                flag=1;
                // m -= k*(pow(2,(64-i-1)));
            }
            else{
                ans+=  k2*(pow(2,(64-i-1)));
            }
            cout<<(64-i-1)<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
        if(flag)
            cout<<"Case #"<<k<<": "<<ans1<<endl;
        else 
            cout<<"Case #"<<k<<": "<<-1<<endl;
        k++;
    }
}