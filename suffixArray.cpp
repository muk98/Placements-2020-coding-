#include <bits/stdc++.h>
using namespace std;
// #define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
	
int pos[100005];
int n;
int gap=0;

bool mycomp(int i,int j){
    if(pos[i]!=pos[j]) return pos[i]<pos[j];

    i += gap;
    j += gap;

    return (i<n && j<n)? pos[i]<pos[j]:i>j;
}


void buildSA(string s,vector<int>&sa,vector<int>&temp){
    rep(i,0,n){
        sa[i]=i;
        pos[i] = s[i];
    }

    for(gap=1;;gap*=2){
        // cout<<gap<<endl;
        sort(sa.begin(),sa.end(),mycomp);
        rep(i,0,n-1) temp[i+1] = temp[i]+mycomp(sa[i],sa[i+1]);
        rep(i,0,n) pos[sa[i]] = temp[i];
        if(temp[n-1]==n-1) break;
    }
}


void buildLCP(vector<int>&sa,vector<int>&lcp,vector<int>&diff){
    int k=0;
    for(int i=0;i<n;i++){
        if(pos[i]!=n-1){
            for(int j=sa[pos[i]+1];diff[i+k]==diff[j+k];){
                k++;
            }
            lcp[pos[i]]=k;
            if(k) k--;
        }
    }
}

signed main(){
    int mod =1e9+9;
    int t;cin>>t;
    while(t--){
        // cin>>n;
        string s;
        cin>>s;
        n = s.size();
        memset(pos,0,sizeof(pos));
        vector<int>sa(n);
        vector<int>temp(n);
        vector<int>arr(n);
        vector<int>lcp(n);
        
        
        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }

        // if(n == 1 || n==0) {
        //     printf("0\n");
        //     continue;
        // }
        // if(n == 2) {
        //     printf("1\n");
        //     continue;
        // }
        // vector<int>diff(n-1);
        // rep(i,0,n-1){
        //     diff[i] = arr[i+1]-arr[i];
        // }
        // int mi = 101, ma = -101;
        // n--;
        // rep(i,0,n){
        //     if(diff[i]<mi) mi = diff[i];
        // }        
        // rep(i,0,n){
        //     diff[i] -= mi-1;
        //     if(diff[i]>ma) ma=diff[i];
        // }
        string s1 = s+s;
        buildSA(s1,sa,temp);
        // buildLCP(sa,lcp,diff);

        for(auto x:sa) cout<<x<<" ";
        cout<<endl;
        // int sum = accumulate(lcp.begin(),lcp.end(),0LL);
        int res=0;
        for(int i=0;i<n;i++){
            res += n-sa[i]-lcp[i];
            res %= 1000000009;;
        }
        
        cout<<res<<endl;
    }
}