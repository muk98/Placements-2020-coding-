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


vector<int> query(vector<vector<int>>&st,int rs,int re,int ss,int se,int pos){
	if(rs<=ss && re>=se){
        // int cnt=0;
		return st[pos];
	}
    vector<int>v(26,0);
	if(rs>se || re<ss) return v;

	int mid = (ss+se)/2;

    vector<int>v1 = query(st,rs,re,ss,mid,2*pos+1);
    vector<int>v2 = query(st,rs,re,mid+1,se,2*pos+2);

    for(int i=0;i<26;i++){
        v[i]=v1[i]+v2[i];
    }  
    return v;
}


void buildTree(string& s,vector<vector<int>>&st,int ss,int se,int pos){
    if(ss==se){
		st[pos][s[ss]-'a']=1;
        return ;
	}

    int mid =(ss+se)/2;
    buildTree(s,st,ss,mid,2*pos+1);
    buildTree(s,st,mid+1,se,2*pos+2);
    
    for(int i=0;i<26;i++){
        st[pos][i] = st[2*pos+1][i]+st[2*pos+2][i];
    }
}

void buildSegmentTree(string& s,vector<vector<int>>&st){
	int n = s.size();
	int h = ceil(log2(n));

	int size = 2*pow(2,h)-1;
	st.resize(size);
    for(int i=0;i<size;i++){
        st[i].resize(26);
    }
	buildTree(s,st,0,n-1,0);
}

void update(string& s,vector<vector<int>>&st,int ss,int se,int pos,int index,char val){
    if(ss==se){
        st[pos][s[index]-'a']=0;
        // cout<<s[index]<<endl;
        s[index]=val;
        // cout<<s[index]<<endl;
		st[pos][s[index]-'a']=1;
        // cout<<s[index]<<endl;
        return ;
	}

    int mid = (ss+se)/2;
    if(index<=mid && index>=ss){
        update(s,st,ss,mid,2*pos+1,index,val);
    }
    else{
        update(s,st,mid+1,se,2*pos+2,index,val);   
    }

    for(int i=0;i<26;i++){
        st[pos][i]=0;
        st[pos][i]=st[2*pos+1][i]+st[2*pos+2][i];
    }
}


int main(){
    vector<vector<int>>st;
    string s;
    cin>>s;
    buildSegmentTree(s,st);
    int n=s.size();
    // for(int i=0;i<st.size();i++){
    //     cout<<st[i].size()<<" ";
    // }
    // cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int a;cin>>a;
        if(a==1){
            int indx;char c;
            cin>>indx>>c;
            update(s,st,0,n-1,0,indx-1,c);
            // for(int i=0;i<st.size();i++){
            //     cout<<st[i].size()<<" ";
            // }
            // cout<<endl;
        }
        else{
            int b,c;
            cin>>b>>c;
            vector<int>ans= query(st,b-1,c-1,0,n-1,0);
            int cnt=0;
            for(int i=0;i<26;i++){
                if(ans[i]>0) cnt++;
                // cout<<ans[i]<<" ";
            }
            cout<<cnt<<endl;
        }
    }

    return 0;
}   