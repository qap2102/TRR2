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

const int MAXN=1005;

int t,n,m,u;
int a[MAXN][MAXN];
// vector<int> adj[MAXN];
set<int> adj[MAXN];
vector<pair<int,int>> vp;
bool visited[MAXN];
int parent[MAXN];
vector<vector<int>> tplt;

void dfs(int u, vector<int> &v1){
    visited[u]=true;
    v1.push_back(u); // lưu đỉnh liên thông vào vector v1
    for(int x:adj[u]){
        if(!visited[x]){
            dfs(x,v1);
        }
    }
}

int main(){
    faster;
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if(a[i][j]){
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            vector<int> v1;
            dfs(i,v1);
            sort(v1.begin(),v1.end());
            tplt.push_back(v1);
        }
    }
    cout<<tplt.size()<<endl;
    for(auto it:tplt){
        for(int k:it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;++i){
        adj[i].clear();
    }
}