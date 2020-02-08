#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  int t;cin>>t;
  for(int z=1;z<=t;z++){
    cout<<"Case #"<<z<<": ";
    int n;long long m;cin>>n>>m;
    
   
    vector<pair<int,int>>b(51,{n,0});// f->0
  int k=0;
    for(int i=0;i<n;i++){
      long long x;cin>>x;
     k=max(k,(int)log2(x)+1);
      int j=0;
      while(x!=0){
        int l=x%2;
        if(l==1){
          b[j].first--;
          b[j].second++;
        }
        j++;
        x=(x>>1);
      }
    }
     k=max(k,(int)log2(m)+1);
    vector<long long>c(k+1,0);
    for(int i=0;i<=k;i++){
      if(i==0)c[i]=min(b[i].first,b[i].second);
      else{
        c[i]=c[i-1]+((1<<i)*min(b[i].first,b[i].second));
      }
    }
    long long ans=0,sum=0;
    if(c[k]>m)cout<<"-1\n";
    else{
      for(int i=k;i>=0;i--){
        if(b[i].first<=b[i].second){
          ans+=(1<<i)*b[i].first;
          sum+=(1<<i);
        }
        else{
          int l=(i==0)?0:c[i-1];
          if(ans+l+(1<<i)*b[i].first<=m){
            ans+=(1<<i)*b[i].first;
            sum+=(1<<i);
          }
          else ans+=(1<<i)*b[i].second;
        }
      }
      cout<<sum<<endl;
    }


   }


}