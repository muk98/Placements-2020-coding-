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
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>v(m);
        for(int i=0;i<m;i++) cin>>v[i];
        vector<int>v2(q);
        for(int i=0;i<q;i++){
            cin>>v2[i];
        }
        map<int,int>mp;
        for(int i=0;i<m;i++){
            int val=v[i];
            for (int i=1; i<=sqrt(val); i++) 
            { 
                if (val%i == 0) 
                { 
                    if (val/i == i) 
                        {
                        mp[i]++;
                    }
                    else{
                       mp[i]++;
                       mp[val/i]++;
                    }
                } 
            } 
        }
        long long sum=0;
        for(int i=0;i<q;i++){
            sum += ((n/v2[i])-mp[v2[i]]);
        }
        cout<<"Case #"<<k<<": "<<sum<<endl;
        k++;
    }
    return 0;
}