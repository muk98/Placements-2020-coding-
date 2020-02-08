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


void updateLazy(vector<pair<int,int>>&st,int ss,int se,int qs,int qe,int val,int pos){
    if(st[pos].second!=0){
        if(ss!=se){
            st[2*pos+1].second += st[pos].second;
            st[2*pos+2].second += st[pos].second;
        }
        st[pos].first+= (se-ss+1)*st[pos].second;
        st[pos].second=0;
    }
    if(ss>se || qe<ss || qs>se) return;
    if(ss>=qs && se<=qe){
        if(ss!=se){
            st[2*pos+1].second += val;
            st[2*pos+2].second += val;
        }
        st[pos].first+= (se-ss+1)*val;
        return;
    }
    
    int mid = (ss+se)/2;

    updateLazy(st,ss,mid,qs,qe,val,2*pos+1); 
    updateLazy(st,mid+1,se,qs,qe,val,2*pos+2);    
    st[pos].first = st[2*pos+1].first+st[2*pos+2].first;

}

int query(vector<pair<int,int>>&st,int ss,int se,int qs,int qe,int pos){
    if(st[pos].second!=0){
        if(ss!=se){
            st[2*pos+1].second += st[pos].second;
            st[2*pos+2].second += st[pos].second;
        }
        st[pos].first+= (se-ss+1)*st[pos].second;
        st[pos].second=0;
    }
    if(ss>se || qe<ss || qs>se) return 0;

    if(ss>=qs && se<=qe){
        return st[pos].first;
    }   
    
    int mid = (ss+se)/2;
    int l = query(st,ss,mid,qs,qe,2*pos+1);
    int r = query(st,mid+1,se,qs,qe,2*pos+2);
    // st[pos].first = st[2*pos+1].first+st[2*pos+2].first;
    return l+r;
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int h=ceil(log2(n));
        int size = 2*(pow(2,h))-1;
        vector<pair<int,int>>st(size);
        while(c--){
            int q;
            cin>>q;
            if(q==0){
                int l,r,val;
                cin>>l>>r>>val;
                updateLazy(st,0,n-1,l-1,r-1,val,0);
            }
            else if(q==1){
                int l,r;
                cin>>l>>r;
                int ans = query(st,0,n-1,l-1,r-1,0);
                cout<<ans<<endl;
            }
        }
        
    }
    return 0;
}