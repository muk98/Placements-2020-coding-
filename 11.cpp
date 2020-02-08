
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
    int n,k;
    cin>>n>>k;
    set<int>mp;
    queue<int>q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(mp.find(a)!=mp.end()){
            continue;
        }

        if(mp.size()<k){
            mp.insert(a);
            q.push(a);
        }
        else{
            // cout<<a<<endl;
            int t = q.front();
            q.pop();
            mp.erase(t);
            mp.insert(a);
            q.push(a);
        }
        // cout<<a<<endl;
    }
    vector<int>v1(q.size());

    cout<<mp.size()<<endl;
    int i=0;
    while(!q.empty()){
        v1[i]=q.front();
        i++;
        q.pop();
    }
    reverse(v1.begin(),v1.end());
    for(int x:v1){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}