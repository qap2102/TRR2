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
const int MAXN = 205;
 
bool visited[MAXN];
int n,m,u;
int dem=0;
int a[MAXN][MAXN];
set<int> adj[MAXN];

void dfs(int u){
    visited[u]=true;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            
            dfs(i);
        }
    }

}
bool kiemtra(){
    int ans=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }
    if(ans==1) return true;
    else return false;
}

void bfs(int u){
    memset(visited,false,sizeof(visited));
    queue<int> q;
    dem++;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=1;i<=n;++i){
            if(a[v][i]==1&&!visited[i]){
                q.push(i);

                ++dem;
                visited[i]=true;
            }
        }
    }


}

bool euler(){
    if(dem!=n) return false;
    for(int i=1;i<=n;++i){
        int sum1=0;
        for(int j=1;j<=n;++j){
            sum1+=a[i][j];
        }
        if(sum1&1) return false;
    }
    return true;
}

bool half_euler(){
    if(dem!=n) return false;
    int cnt=0;
    for(int i=1;i<=n;++i){
        int sum2=0;
        for(int j=1;j<=n;++j){
            sum2+=a[i][j];
        }
        if(sum2&1) ++cnt;
    }
    if(cnt==0||cnt==2) return true;
    else return false;
}

void euler_cycle(int v){
    stack<int> st;
    vector<int> ec;
    st.push(v);
    while(!st.empty()){
        int x = st.top();
        if(adj[x].size()!=0){
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
 
        }
        else {
            st.pop();
            ec.push_back(x);
        }
    }
    reverse(ec.begin(),ec.end());
    for(int x:ec){
 
        cout<<x<<" ";
    }
}

int main(){
    faster;
    // freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);
    int t;
    cin>>t;
    
    if(t==1){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                a[i][j]=0;
            }
        }
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            a[x][y]=1;
            a[y][x]=1;
        }
        // if(kiemtra()){
        //     int cnt=0;
        //     int kt=0;
        //     for(int i=1;i<=n;++i){
        //         if(degree[i]%2!=0){
        //             cnt++;
        //             kt=1;
        //         }
        //     }
        //     if(kt==0) cout<<"1";
        //     else if(cnt==0||cnt==2) cout<<"2";
        //     else cout<<"0";
        // }
        // else cout<<"0";
        
        bfs(1);
        if(euler()) cout<<"1";
        else if(half_euler()) cout<<"2";
        else cout<<"0";
    }
    else {
        cin>>n>>m>>u;
        adj->clear();
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        euler_cycle(u);

    }
}


