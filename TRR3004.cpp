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

const int MAXN=101;

int t, n, u;

int a[MAXN][MAXN];
vector<int> adj[MAXN];
vector<pair<int,int>> vp;
bool visited[MAXN];


void dfs(int u){
    visited[u]=true;
    for(int i=1;i<=n;++i){
        if(!visited[i]&&(a[i][u]||a[u][i])){
            
            dfs(i);
        }
    }
}


int check(){
    memset(visited,false,sizeof(visited));
    
    dfs(1);
    int degin[MAXN]={0};
    int degout[MAXN]={0};
    for(int i = 1; i <= n; i++){
		if(!visited[i]) return 0;
		for(int j = 1; j <= n; j++){
			degout[i] += a[i][j];
			degin[j] += a[i][j];
		}
	}
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(degin[i]!=degout[i]){
            if(abs(degin[i]-degout[i])>1) return 0;
        }
        else ++cnt;
    }
    if(cnt==0) return 1;
    else if(cnt<=2) return 2;
    else return 0;

    
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
                a[s][i]=0;
                break;
            }
        }
        if(!kt){
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
   freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
    cin>>t;
    if(t==1){
        cin>>n;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>a[i][j];
            }
        }
        
        cout<<check();



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
    return 0;
}



