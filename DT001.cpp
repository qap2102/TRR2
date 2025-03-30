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

int t, n, m;
vector<int> adj[1001];
int a[1001][1001];
vector<pair<int,int>> vp;

int main(){
    faster;
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    if(t==2){
        int cnt=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i][j]&&i<j){
                    cnt++;
                    vp.push_back({i,j});
                }
            }
        }
        cout<<n<<" "<<cnt<<endl;
        for(auto it:vp){
            cout<<it.fi<<" "<<it.se<<endl;
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
			int count=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]){
					count++;
				}
			}
			cout<<count<<" ";
		}
    }
}