#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, vector<int> > mp;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>> > pque;
    int minx = INT_MAX;
    int maxx = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;   
        if(mp.find({a[i].first, a[i].second})==mp.end()){
            mp[{a[i].first, a[i].second}] = vector<int>();
        }
        mp[{a[i].first, a[i].second}].push_back(i+1);
        pque.push({{a[i].first, 0}, a[i].second});
        minx = min(a[i].first, minx);
        maxx = max(a[i].second, maxx);
    }
    vector<pair<int, int>> ans;

    multiset<pair<int, int> > active;
    for(int i=minx; i<=maxx&&!pque.empty(); i++){
        while(!pque.empty()&&pque.top().first.second==0 && pque.top().first.first==i){
            auto it = pque.top();
            pque.pop();
            active.insert({it.second, it.first.first});
            pque.push({{it.second, 1}, it.first.first});
        }
        while(active.size()>k){
            auto it = active.end();
            it--;
            ans.push_back({it->second, it->first});
            active.erase(it);
        }
        while(!pque.empty()&&pque.top().first.second==1&&pque.top().first.first==i){
            auto it = pque.top();
            pque.pop();
            auto it2 = active.find({it.first.first, it.second});
            if(it2!=active.end()){
                active.erase(it2);
            }
        }
    }

    int m = ans.size();
    cout<<m<<endl;
    for(int i=0; i<m; i++){
        cout<<mp[{ans[i].first, ans[i].second}][mp[{ans[i].first, ans[i].second}].size()-1]<<" ";
        mp[{ans[i].first,ans[i].second}].pop_back();
    }
    cout<<endl;
    return 0;
}