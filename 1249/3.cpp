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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        ll s;cin>>s;
        vector<pair<ll,ll>>v(n);
        for(int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            v[i].first=a;
            v[i].second=b;
        }
        sort(v.begin(),v.end());
        int midpos = n/2;
        ll l = v[0].first;
        ll r = s;
    
        while(l<r){
            ll mid=(l+r+1)/2;
            ll sum=0;
            int cnt=0;
            ll sum2=0;
            vector<pair<int,int>>temp;
            for(int i=0;i<n;i++){
                if(v[i].first<mid && v[i].second<mid){
                    cnt++;
                    sum+=v[i].first;
                }   
                else if(v[i].first<=mid && v[i].second>=mid) temp.push_back(v[i]);
                else{
                    sum2+=v[i].first;
                }
            }
 
            if(temp.size()==0){
            //    cout<<l<<" -1- "<<r<<" "<<sum<<" "<<temp.size()<<endl;
                if(cnt<=n/2){
                    l=mid;
                } 
                else{
                    r=mid-1;
                }
            }
            else{
                if(cnt>n/2){
                    // cout<<l<<" -2- "<<r<<" "<<sum<<" "<<temp.size()<<" "<<cnt<<endl;
                    r=mid-1;
                    continue;
                }
                int j=0;
                for(j=0;j<temp.size() && cnt<n/2;j++){
                    sum+= temp[j].first;
                    cnt++;
                }
                while(j<temp.size()){
                    sum+=mid;
                    j++;
                }
                sum+=sum2;
                // cout<<l<<" -3- "<<r<<" "<<sum<<" "<<temp.size()<<" "<<cnt<<endl;
                if(sum<=s){
                    l=mid;
                }
                else{
                    r=mid-1;
                }
            }
        }

        // cout<<l<<" "<<r<<endl;
        cout<<l<<endl;
    }
    return 0;
}