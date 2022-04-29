#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pcase(a,b) cout<<"Case "<<a++<<": "<<b<<endl;
#define mod 10000007

int tcs=1,n,k;
vector<int>a;

int count(int x){
    int cnt = 0,sum=0;

    for(int i=0 ; i<=n ; i++){
        if(sum+a[i]>x){
            sum = a[i];
            cnt++;
        }
        else sum += a[i];
    }

    return cnt;
}

int BS(int st,int en){
    
    int left=st,right=1e9;
    
    while(left<right){
        int mid = left + (right-left)/2;
        if(count(mid)<=k){
            right = mid;
        }
        else left = mid+1;
    }
    return left;

}

void solve(){

    cin>>n>>k;

    a.resize(n+1);
    int m = 0,sum=0;
    for(int i=0 ; i<=n ; i++){
        cin>>a[i];
        sum += a[i];
        m = max(m,a[i]);
    }

    int res = BS(m,sum);

    pcase(tcs,res);

    sum = 0;
    int cur = k;
    
    for(int i=0 ; i<n+1 ; i++){
            sum += a[i];
            if(sum>res || n-i+1==cur){
                cur--;
                sum-=a[i];
                cout<<sum<<endl;
                sum=a[i];
            }
    }
    cout<<sum<<endl;


}
int main(){
    
    IOS;
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
 
}