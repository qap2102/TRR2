#include<bits/stdc++.h>
using namespace std;
 
vector<int> chuaxet(1000, 0);
int dem = 0;
void BFS(int a[1000][1000], int n,int u)
{
    queue<int> q;
    dem++;
    q.push(u);
    chuaxet[u] = 1;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i =1;i<=n;i++)
        {
            if(a[s][i] == 1 && chuaxet[i] == 0)
            {
                q.push(i);
                dem++;
                chuaxet[i] = 1;
            }
        }
    }
}   
 
bool euler(int n,int a[1000][1000])
{
    if(dem != n) return false;
    for(int i = 1;i<=n;i++)
    {
        int sum1 = 0;
        for(int j = 1;j<=n;j++)
        {
            sum1 += a[i][j];
        }
        if(sum1 % 2 !=0) return false;
    }
    return true;
}
 
bool half_euler(int n, int a[1000][1000])
{
    if(dem != n) return false;
    int cnt =0;
    for(int i = 1;i<=n;i++)
    {
        int sum2 = 0;
        for(int j =1; j<=n;j++)
        {
            sum2+= a[i][j];
        }
        if(sum2 % 2 != 0) cnt++;
    }
    if(cnt == 0 || cnt == 2) return true;
    return false;
}
 
vector<int> euler_cycle(int a[1000][1000], int n, int u)
{
    stack<int> s;
    vector<int> ce;
    s.push(u);
    while(!s.empty())
    {
        int s1 = s.top();
        bool kt = false;
        for(int i = 1;i<=n;i++)
        {
            if(a[s1][i] == 1)
            {
                kt = true;
                s.push(i);
                a[s1][i] = a[i][s1] = 0;
                break;
            }
        }
        if(kt == false)
        {
            s.pop();
            ce.push_back(s1);
        }
    }
    reverse(ce.begin(),ce.end());
    return ce;
}
int main()
{
    int t;cin >> t;
    if(t==1)
    {
        int n,m;cin >> n >>m;
        int a[1000][1000];
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                a[i][j] = 0;
            }
        }
        for(int i = 1;i<=m;i++)
        {
            int m1,m2;
            cin >> m1 >> m2;
            a[m1][m2] = 1;
            a[m2][m1] = 1;
        }
 
        BFS(a,n,1);
 
        if(euler(n,a)) cout << 1;
        else if(half_euler(n,a)) cout << 2;
        else cout << 0;
 
    }
    else if(t==2)
    {
        int n,m, u;
        cin >> n>>m >> u;
        int a[1000][1000];
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                a[i][j] = 0;
            }
        }
        for(int i = 1;i<=m;i++)
        {
            int m1,m2;
            cin >> m1 >> m2;
            a[m1][m2] = 1;
            a[m2][m1] = 1;
        }
        vector<int> res = euler_cycle(a,n,u);
        for(auto x : res) cout << x << " ";
    }
    return 0;
}