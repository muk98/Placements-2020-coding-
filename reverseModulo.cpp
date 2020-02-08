#include<bits/stdc++.h>
using namespace std;

long long modFact(long long n,long long mod){
    long long ans =1;
    for(long long i=1;i<=n;i++){
        ans = ((ans)%mod*(i)%mod)%mod;
    }
    return ans;
}


long long modExp(long long n,long long m,long long mod){
    long long ans=1;
    n=n%mod;
    while(m>0){
        if(m&1){
            ans = ((ans)%mod*(n)%mod)%mod;
        }
        m=m>>1;
        n = (((n%mod))*((n)%mod))%mod;
        // cout<<n<<" "<<ans<<endl;
    }   
    return ans;
}

long long reverseModulo(long long n,long long r,long long mod){
    long long a = modFact(n,mod);    
    long long b = modFact(r,mod);
    long long c = modFact(n-r,mod);

    // cout<<a<<" "<<b<<" "<<c<<endl;

    long long e = modExp(b,mod-2,mod);
    long long f = modExp(c,mod-2,mod);

    // cout<<e<<" "<<f<<endl;
    long long ans = ((((a)%mod*(e)%mod)%mod)*f)%mod;
    return ans;
}

int main(){
    long long d,f,t;
    cin>>d>>f>>t;
    long long mod=1e9+7;
    int a=0;
    if(t>=d) 
        a = reverseModulo(t-1,d-1,mod);
    int b=0;
    if(t>f && t-f-1>=d-1){
        b=reverseModulo(t-f-1,d-1,mod);
    }
    cout<<a<<" "<<b<<endl;
    int ans = a-b;
    cout<<ans<<endl;
}