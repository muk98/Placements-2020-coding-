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
    int count[2];
    trieNode(){
        count[0] =0;
        count[1] =0;
        next[0]=NULL;
        next[1]=NULL;
    }
}trieNode;

void insert(int val,trieNode* root){
    // int tt=val;
    vector<int>bit(32);
    for(int i=31;i>=0;i--){
        bit[i]= val%2;
        val/=2;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    }
    trieNode* curr = root;
    for(int i=0;i<32;i++){
        // curr->count++;
        // cout<<i<<" "<<bit[i]<<endl;
        if(curr->next[bit[i]]==NULL){
            curr->next[bit[i]] = new trieNode();
        }
        curr->count[bit[i]]++;
        curr= curr->next[bit[i]];
    }
    // curr->count++;
}


int buildAns(vector<int>&bit1,vector<int>&bit2,trieNode* head,int pos){
    if(head==NULL) return 0; 
    // cout<<pos<<endl;
    if(bit2[pos]==0){
        // cout<<pos<<endl;
        if(bit1[pos]==1) return buildAns(bit1,bit2,head->next[1],pos+1);
        else return buildAns(bit1,bit2,head->next[0],pos+1);
    }
    else{
        // cout<<pos<<endl;
        if(bit1[pos]==0){
            return  head->count[0] + buildAns(bit1,bit2,head->next[1],pos+1);
        }
        else{
            return head->count[1] + buildAns(bit1,bit2,head->next[0],pos+1);
        }
    }   
}

int query(int val,int k,trieNode* head){
    vector<int>bit1(32);
    vector<int>bit2(32);
    for(int i=31;i>=0;i--){
        bit1[i] = val&1;
        // cout<<bit1[i]<<" ";
        val>>=1;
    }
    // cout<<endl;
    for(int i=31;i>=0;i--){
        bit2[i] = k&1;
        // cout<<bit2[i]<<" ";
        k>>=1;
    }
// cout<<endl;
    return buildAns(bit1,bit2,head,0);
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        rep(i,0,n) cin>>v[i];
        trieNode* head = new trieNode();
        int ans=0;
        // insert(0,head,0);  
        int xr = 0;
        // if(v[0]<k) ans++;
        for(int i=0;i<n;i++){
            insert(xr,head);
            xr = xr^v[i];
            ans +=query(xr,k,head);
            // cout<<ans<<endl;
        }
        // ans +=query(xr,k,head);
        cout<<ans<<endl;
    }
}