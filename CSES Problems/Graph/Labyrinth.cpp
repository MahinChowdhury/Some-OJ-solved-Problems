#include<bits/stdc++.h>
 
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define N 1005

int n,m;
vector<string>s;
bool vis[N][N];
int dis[N][N];
vector<pair<int,int>> path[N];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int sx,int sy){

    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;

    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for(int k=0 ; k<4 ; k++){
            int x = u+dx[k];
            int y = v+dy[k];

            if(x>=0 && x<n && y>=0 && y<m && s[x][y]!='#' && vis[x][y]==0){
                vis[x][y] = 1;
                dis[x][y] = 1+dis[u][v];
                path[x][y] = {dx[k],dy[k]};
                q.push({x,y});
            }

        }

    }

}

void solve(){

    cin>>n>>m;
    s.resize(n);

    for(int i=0 ; i<n ; i++){
        path[i].resize(m);
        cin>>s[i];
    }

    int sx=0,sy=0,ex=0,ey=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(s[i][j]=='A'){
                sx=i,sy=j;
                bfs(i,j);
            }
            if(s[i][j]=='B'){
                ex=i,ey=j;
            }
        }
    }

    if(!vis[ex][ey]){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    cout<<dis[ex][ey]<<endl;

    pair<int,int>t = {ex,ey};

    vector<pair<int,int>>ans;

    while(t.first != sx || t.second != sy){

        ans.push_back(path[t.first][t.second]);
        t.first -= ans.back().first;
        t.second -= ans.back().second;
    }

    //cout<<ans.size()<<endl;

    reverse(ans.begin(),ans.end());

    for(auto c:ans){
        if(c.first == 1 and c.second ==0)
        {
            cout << 'D';
        }
        else if(c.first == -1 and c.second ==0)
        {
            cout << 'U';
        }
        else if(c.first == 0 and c.second == 1)
        {
            cout << 'R';
        }
        else if(c.first == 0 and c.second == -1)
        {
            cout << 'L';
        }
    }


}
int main(){
    
    IOS;
    int tc=1;
    //cin>>tc;
    while(tc--){
        solve();
    }
 
}