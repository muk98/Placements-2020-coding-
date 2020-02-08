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

   
    int overlap(vector<vector<int>>&prep,string s1,string s2){
        int n1=s1.size();
        int n2=s2.size();
        
        for(int i=0;i<n1;i++){
            int j=0;
            int p=i;
            int k=i;
            while(p<n1 && j<n2 && s1[p]==s2[j]){
                p++;
                j++;
            }
            if(p==n1){
                return (n1-k);
            }
        }
        return 0;
    }
    
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>>prep(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                prep[i][j]=overlap(prep,A[i],A[j]);
                prep[j][i]=overlap(prep,A[j],A[i]);
                // cout<<i<<" "<<j<<" "<<prep[i][j]<<" "<<prep[j][i]<<endl;
            }
        }
        int finalMask=(1<<n)-1;
        priority_queue<pair<int,pair<int,pair<int,string>>>>pq;
        pq.push({0,{-1,{0,""}}});
        vector<vector<int>>visited(n,vector<int>(1<<n,0));
        vector<vector<long long>>dis(n,vector<long long>(1<<n,INT_MAX));
        string ans;
        int minLen = INT_MAX;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int len = t.first;
            int last = t.second.first;
            int mask = t.second.second.first;
            string s = t.second.second.second;
            // cou.t<<s<<endl;
            if(mask==finalMask && s.size()<minLen){
                ans = s;
                // cout<<s<<endl;
                minLen = s.size();
                break;
                // continue;
            }
            if(last!=-1&&visited[last][mask])continue;
            if(last!=-1){
                visited[last][mask]=1;
            }
            for(int i=0;i<n;i++){
                if(!((1<<i)&mask)){
                    int tt;
                    if(last==-1){
                        tt = A[i].size();  
                        pq.push({tt,{i,{1<<i,A[i]}}});
                        dis[i][1<<i] = A[i].size();
                        continue;
                    }
                    if(dis[i][mask|(1<<i)] > dis[last][mask]+(A[i].size()-prep[last][i])){
                        dis[i][mask|(1<<i)] = dis[last][mask]+ (A[i].size()-prep[last][i]);
                        int match = prep[last][i];
                        int notMatch = A[i].size()-match;
                        tt = len+notMatch;
                        string temp = s + A[i].substr(match,notMatch);
                        pq.push({tt,{i,{mask|(1<<i),temp}}});
                    }
                }
            }
        }
        // cout<<"yoo"<<endl;
        return ans;
    }


signed main(){
    int n;
    cin>>n;
    vector<string>t;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        t.push_back(a);
    }
    cout<<shortestSuperstring(t)<<endl;
}