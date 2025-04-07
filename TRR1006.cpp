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
vector<int> adj[1001];
vector<pair<int,int>> vp;

int main(){
    faster;
    freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
    int t;
    cin>>t;
    cin>>n>>m;
    map<int,int> mp;
    
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        // adj[x].push_back(y);
        // adj[y].push_back(x);
        mp[x]++;
        mp[y]++;
        // vp.push_back({x,y});
        a[x][i]=1;
        a[y][i]=1;
        
        
    }
    if(t==1){
        for(auto it:mp){
            cout<<it.se<<" ";
        }
    }
    else if(t==2){
        cout<<n<<" "<<m<<endl;
        
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
            
    }
}
