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

const int MAXN=1001;

int n;
int a[MAXN][MAXN];
vector<int> adj[MAXN];
vector<pair<int,int>> vp;




int main(){
    faster;
    freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
    int t;
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    if(t==1){
        for(int i=1;i<=n;++i){
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(a[i][j]) ++cnt;
            }
            cout<<cnt<<" ";
        }
    }
    else {
        vp.clear();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i][j]&&i<j){
                    vp.push_back({i,j});
                }
            }
        }
        cout<<n<<" "<<vp.size()<<endl;
        for(auto it:vp){
            cout<<it.fi<<" "<<it.se<<endl;
        }
    }
}