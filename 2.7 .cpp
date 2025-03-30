#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define fi first
#define se second
const int MOD = 1e9+7;
const int N=1e6+5;

int n,m;
int a[1001][1001];
bool visited[1001];
vector<int> adj[1001];

vector<pair<int,int>> vp;
vector<pair<int,int>> check;

void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        vp.push_back({x,y});
    }
}

void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]) dfs(v);
    }
}


void dfs1(int u, int s, int t){
    visited[u]=true;
    for(int v:adj[u]){
        if((u==s&&v==t)||(u==t&&v==s)){
            continue;
        }
        if(!visited[v]) dfs1(v,s,t);
    }
}

void canhcau(){
    int ans=0;
    int tplt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    for(auto it:vp){
        int x=it.fi, y=it.se;
        memset(visited,false,sizeof(visited));
        // loại bỏ cạnh x y khỏi đồ thị
        int dem=0;
        for(int j=1;j<=n;++j){
            if(!visited[j]){
                ++dem;
                dfs1(j,x,y);
            }
        }
        if(dem>tplt){
            ++ans;
            check.push_back({x,y});
            
        }
    }
    cout<<ans<<endl;
    for(auto k:check){
        cout<<k.fi<<" "<<k.se<<endl;
    }
}

int main(){
    faster;
    nhap();
    canhcau();
}

