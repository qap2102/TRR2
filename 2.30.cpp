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

const int MAXN=105;

int n;
int a[MAXN][MAXN];
// vector<int> adj[MAXN];
set<int> adj[MAXN];
vector<pair<int,int>> vp;
bool visited[MAXN];

void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void bfs(int u){
    visited[u]=true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int k:adj[v]){
            if(!visited[k]){
                visited[k]=true;
                q.push(k);
            }
        }
    }
}

int demtplt(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    return cnt;
}

int main(){
    faster;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if(a[i][j]){
                adj[i].insert(j);
                
                if(i<j) vp.push_back({i,j});
            }
        }
    }
    int tmp=demtplt();
    vector<pair<int,int>> ans;
    for(auto it:vp){
        adj[it.fi].erase(it.se);
        adj[it.se].erase(it.fi);
        memset(visited,false,sizeof(visited));
        if(tmp<demtplt()){
            ans.push_back(it);
        }
        adj[it.fi].insert(it.se);
        adj[it.se].insert(it.fi);
    }
    cout<<ans.size()<<endl;
    for(auto m:ans){
        cout<<m.fi<<" "<<m.se<<endl;
    }

}
