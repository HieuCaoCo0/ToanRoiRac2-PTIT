#include <bits/stdc++.h>
using namespace std;
int n, a[105][105];
bool chuaXet[105];
vector<vector<int>> tplt;
vector<int> lt;
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaXet[u] = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        chuaXet[x] = 0;
        lt.push_back(x);
        for (int i = 1; i <= n; i++){
            if (a[x][i] && chuaXet[i]){
                chuaXet[i] = 0;
                q.push(i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    memset(chuaXet, 1, sizeof(chuaXet));
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (chuaXet[i]){
            lt.clear();
            cnt++;
            BFS(i);
            tplt.push_back(lt);
        }
    }
    cout << cnt << "\n";
    for (auto i : tplt){
        sort(i.begin(), i.end());
        for (auto j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}