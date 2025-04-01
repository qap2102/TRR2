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


// chuyển danh sách cạnh sang ma trận kề
int n, m;
int a[1001][1001];
vector<int> b;
int main(){
	faster;
    ifstream fin("DT.INP");
	ofstream fout("DT.OUT");
    int t;
    fin>>t;

	fin>>n>>m;
    
	for(int i=1;i<=m;++i){
        
		int x,y;
		fin>>x>>y;
		a[x][y]=a[y][x]=1;
        
	}
    if(t==1){
        for(int i=1;i<=n;++i){
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(a[i][j]){
                    ++cnt;
                }
            }
            b.push_back(cnt);
        }
        for(auto it:b){
            fout<<it<<" ";
        }
    }
    else if(t==2){
        fout<<n<<endl;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                fout<<a[i][j]<<" ";
            }
            fout<<endl;
        }
    }
    fin.close();
	fout.close();
	// for(int i=1;i<=n;++i){
	// 	for(int j=1;j<=n;++j){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	
}



