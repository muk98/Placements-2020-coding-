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
	

signed main(){
    string s;
    while(1){
        cin>>s;
        if(s=="0") break;
        int n=s.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int cnt=0;
        int val=0;
        for(auto x:mp){
            if(x.second%2==1){
                cnt++;
                val=x.first;
            }
        }
        if(n%2==0 && cnt>0){
            cout<<"Impossible\n";
            continue;
        }
        if(n%2==1 && (cnt>1 || cnt==0)) {
            cout<<"Impossible\n";
            continue;
        }
        cnt=0;
        int i=0;
        while(i<n/2)
        {
            int j=n-i-1;
            if(s[i]==s[j])
                i++;
            else
            {
                int p=0,q=0;
                for(q=i+1;s[j]!=s[q];q++);

                for(p=j-1;s[i]!=s[p];p--);

                cnt+=min(q-i,j-p);
                // cout<<cnt<<endl;
                if(q-i<j-p)
                {
                    for(int k=q;k>i;k--)
                    swap(s[k],s[k-1]);
                }
                else
                {
                    for(int k=p;k<j;k++)
                    swap(s[k],s[k+1]);
                }
                // i++;
            }
            cout<<s<<endl;
            i++;
        }
        cout<<cnt<<endl;
    }
}