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
    vector<int> ce;
    st.push(v);
    while(!st.empty()){
        int s = st.top();
        int kt=0;
        for(int i=1;i<=n;++i){
            if(a[s][i]){
                st.push(i);
                kt=1;
                a[s][i]=a[i][s]=0;
                break;
            }
        }
        if(!kt) {
            st.pop();
            ce.push_back(s);
        }
        


    }
    reverse(ce.begin(),ce.end());
    for(auto it:ce){
        cout<<it<<" ";
    }
}

int main(){
    faster;
    // freopen("CT.INP", "r", stdin);
	// freopen("CT.OUT", "w", stdout);
    int t;
    cin>>t;
    if(t==1){
        cin>>n;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>a[i][j];
            }
        }
        bfs(1);
        if(euler()) cout<<"1";
        else if(half_euler()) cout<<"2";
        else cout<<"0";

    }
    else {
        cin>>n>>u;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>a[i][j];
            }
        }
        euler_cycle(u);
    }
    
}


