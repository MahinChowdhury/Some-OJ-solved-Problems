#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pcase(a,b) cout<<"Case "<<a++<<": "<<b<<endl;
#define mod 10000007

int tcs=1;

void solve(){

    ll n;
    cin>>n;

    vector<ll>a(n);
    unordered_map<ll,ll>mp;
    for(int i=0 ; i<n ; i++){
        int u;
        cin>>u;
        mp[u]++;
    }

    ll res = 0;

    for(auto u:mp){
        ll x = ceil((double)u.second / (double)(u.first+1)) * (u.first+1);
        res += x;
    }

    pcase(tcs,res)


}
int main(){
    
    IOS;
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
 
}