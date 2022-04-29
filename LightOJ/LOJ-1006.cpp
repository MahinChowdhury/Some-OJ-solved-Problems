#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pcase(a,b) cout<<"Case "<<a++<<": "<<b<<endl;
#define mod 10000007

int tcs=1;

ll a,b,c,d,e,f,n;

ll calc(ll n){

    ll dp[10005];
    dp[0]=a;
    dp[1]=b;
    dp[2]=c;
    dp[3]=d;
    dp[4]=e;
    dp[5]=f;

    for(ll i=6 ; i<=n ; i++){
        dp[i] = (((((dp[i-1] + dp[i-2])%mod + dp[i-3])%mod + dp[i-4])%mod + dp[i-5])%mod + dp[i-6])%mod;
    }

    return dp[n];
}

void solve(){

    cin>>a>>b>>c>>d>>e>>f>>n;

    ll ans = calc(n)%mod;
    pcase(tcs,ans);

}
int main(){
    
    IOS;
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
 
}