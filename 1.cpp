#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long



int main(){
    faster;
    int t;
    cin>>t;
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<int> b;
    vector<pair<int,int>> c;
    for(int i = 0;i < n;i++){
        int cnt = 0;
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                ++cnt;
                if(i < j) c.push_back({i + 1,j + 1});
            }
        }
        b.push_back(cnt);
    }
    if(t == 1){
        for(auto x : b){
            cout << x << " ";
        }
    }
    else{
        cout << n << " " << c.size() << endl;
        for(auto x : c){
            cout << x.first << " " << x.second << endl;
        }
    }
}
