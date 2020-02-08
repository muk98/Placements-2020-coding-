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

typedef struct trieNode{
    trieNode* next[2];

    trieNode(){
        next[0]=NULL;
        next[1]=NULL;
    }
}trieNode;


void insert(int val,trieNode* root){
    vector<int>bit(32);
    for(int i=31;i>=0;i--){
        bit[i]= val%2;
        val/=2;
    }
    trieNode* curr = root;
    for(int i=0;i<32;i++){
        if(curr->next[bit[i]]==NULL){
            curr->next[bit[i]] = new trieNode();
        }
        curr= curr->next[bit[i]];
    }
}

int query(int val,trieNode* head){
    vector<int>bit(32);
    for(int i=31;i>=0;i--){
        bit[i] = val%2;
        val/=2;
    }
    int pwr = 31;
    int ans=0;
    for(int i=0;i<32;i++){
        if(head->next[bit[i]^1]==NULL){
            head = head->next[bit[i]];
        }
        else{
            ans += 1<<pwr;
            head = head->next[bit[i]^1];
        }
        pwr--;
    }
    return ans;
}

signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        rep(i,0,n) cin>>v[i];
        trieNode* head = new trieNode();
        int ans=0;
        insert(0,head);  
        int xr = 0;
        // insert(v[0],head);
        for(int i=0;i<n;i++){
            xr = xr^v[i];
            insert(xr,head);
            ans = max(ans,query(xr,head));
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}