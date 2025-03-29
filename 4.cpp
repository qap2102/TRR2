#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long



int main(){
    faster;
    int t,n;
	cin>>t>>n;
	int a[n][n];
	int dem2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0&&a[i][j]<=50) dem2++;
		}
	}
	if(t==1){
		for(int i=0;i<n;i++){
			int dem1=0;
			for(int j=0;j<n;j++){
				if(a[i][j]!=0&&a[i][j]<=50) dem1++;
			}
			cout<<dem1<<" ";
		}
	}
	if(t==2){
		cout<<n<<" "<<dem2/2<<endl;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i][j]!=0&&a[i][j]<=50){
					cout<<i+1<<" "<<j+1<<" "<<a[i][j]<<endl;
				}
			}
		}
	}
}
