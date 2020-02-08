#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000007;
bitset<maxn> dp;

int main(){
    int n;cin>>n;
    int sum =0;
    dp[0]=1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        dp = dp|dp<<x;
    }
    int target = (sum+1)/2;
    for(int i=target;i<=sum;i++){
        if(dp[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}