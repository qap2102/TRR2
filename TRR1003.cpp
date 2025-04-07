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




int main(){
    faster;
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	int t; cin >> t;
	int n; cin >> n;
	int a[n + 2][n + 2];
	vector<pair<int,int>> vp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j]; 
		} 
	} 
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int cnt = 0; 
			for(int j = 1; j <= n; j++){
				if(a[i][j]) cnt++; 
			} 
			cout << cnt << " "; 
		} 
	} 
	else {
		 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==1&&i<j)
				{
					vp.push_back({i,j});
				}
			}
		}
		int m = vp.size();
		int b[n+2][m+2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i][j]=0;
			}
			
		}
		for(int j=1;j<=m;j++){
			b[vp[j-1].fi][j] = 1;
			b[vp[j-1].se][j] = 1;
		}
		cout << n << " " << m << endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
		vp.clear();
		
	} 
	return 0; 
	
}
