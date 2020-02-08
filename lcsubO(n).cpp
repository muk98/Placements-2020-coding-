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
	
int pos[100001];
int gap=0;
int n;

bool mycomp(int i,int j){
    if(pos[i]!=pos[j]) return pos[i]<pos[j];
    i+= gap;
    j+= gap;
    return (i<n && j<n)?pos[i]<pos[j]:i>j;
}


void buildSuffix(string s,int n,vector<int>&sa,vector<int>&temp){
    for(int i=0;i<n;i++){
        sa[i]=i;
        pos[i]=s[i];
    }
    for(gap=1;;gap*=2){
        sort(sa.begin(),sa.end(),mycomp);
        for(int i=0;i<n-1;i++){
            temp[i+1] = temp[i]+mycomp(sa[i],sa[i+1]); 
        }
        rep(i,0,n) pos[sa[i]]=temp[i];
        if(temp[n-1]==n-1) break;
    }
}


void buildlcp(string s,vector<int>&lcp,vector<int>&sa){
    int k=0;
    for(int i=0;i<n;i++){
        if(pos[i]!=n-1){
            for(int j=sa[pos[i]+1];s[i+k]==s[j+k] && i+k<n && j+k<n;){
                k++;
            }
            lcp[pos[i]]=k;
            if(k) k--;
        }
    }
}

int main(){
    string s1;
    string s2;
    
    cin>>s1>>s2;
    n=s1.length()+s2.length()+1;
    int n1=s1.size();
    int n2 = s2.size();
    reverse(s2.begin(),s2.end());
    gap=1;
    vector<int>sa(n,0);
    vector<int>temp(n,0);
    vector<int>lcp(n,0);
    string s = s1+"#"+s2;
    buildSuffix(s,n,sa,temp);
    buildlcp(s,lcp,sa);
    int len=0;
    int ai=0;
    for(int i=0;i<n;i++){
        if(lcp[i]>len && ((sa[lcp[i]]<n1 && sa[lcp[i]+1]>n1) || (sa[lcp[i]]>n1 && sa[lcp[i]+1]<n1))){
            len=lcp[i];
            ai=i;
        }
    }

    //rep(i,0,n) cout<<sa[i]<<" "<<lcp[i]<<endl;
    if(len==0){
        cout<<-1<<endl;
    }
    else{
        string s1=s.substr(sa[ai],len);
        string s2=s.substr(sa[ai],len);
        // cout<<s<<endl;
        // cout<<s1<<endl;
        reverse(s2.begin(),s2.end());
        // cout<<sa[ai]<<endl;
        // cout<<sa[ai+1]<<endl;
        string ans;
        if(s[sa[ai+1]+len]!='#')
             ans = s1+s[sa[ai+1]+len]+s2;
        else if(sa[ai]+len<n){
            ans =  s1+s[sa[ai]+len]+s2;
        }
        else ans = s1 + s2;
        cout<<ans<<endl;
    }
    return 0;
}