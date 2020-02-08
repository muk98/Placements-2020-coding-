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
	
void manacherOdd(string s,int n,vector<int>&odd){
    int l=0;
    int r=-1;
    for(int i=0;i<n;i++){
        int k = ((i>r)? 1:min(odd[l+r-i],r-i));

        while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
            k++;
        }
        odd[i]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
}

void manacherEven(string s,int n,vector<int>&even){
    int l=0,r=-1;
    for(int i=0;i<n;i++){
        int k = ((i>r)? 0: min(even[l+r-i+1],r-i+1)) +1;
        while(i-k>=0 && i+k-1<n && s[i-k]==s[i+k-1]){
            k++;
        }
        even[i]= --k;
        if(i+k>r){
            l=i-k;
            r=i+k-1;
        }
    }
}


signed main(){
    int n;
    // cin>>n;
    string s;
    cin>>s;
    n = s.size();
    vector<int>odd(n,0);
    vector<int>even(n,0);
    manacherOdd(s,n,odd);
    manacherEven(s,n,even);
    int maxi1=0;
    int maxi2=0;
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,max(2*odd[i]-1,2*even[i]));
    }

    for(int i=0;i<even.size();i++){
        cout<<even[i]<<" ";
    }

    cout<<endl;
    cout<<ans<<endl;
    return 0;
}