#include <bits/stdc++.h>
using namespace std;
int n, a[105][105];
bool chuaXet[105];
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaXet[u] = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        chuaXet[x] = 0;
        for (int i = 1; i <= n; i++){
            if (a[x][i] && chuaXet[i]){
                chuaXet[i] = 0;
                q.push(i);
            }
        }
    }
}
void BFS2(int u, int s, int t){
    queue<int> q;
    q.push(u);
    chuaXet[u] = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        chuaXet[x] = 0;
        for (int i = 1; i <= n; i++){
            if ((x == s && i == t) || (i == s && x == t)) continue;
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
    cin >> n;
    vector<pair<int, int>> ds;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && i < j) ds.push_back({i, j});
        }
    }
    int cnt = 0, tplt = 0;
    vector<pair<int, int>> canhCau;
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        if (chuaXet[i]){
            tplt++;
            BFS(i);
        }
    }
    for (auto it : ds){
        int x = it.first, y = it.second, dem = 0;
        memset(chuaXet, 1, sizeof(chuaXet));
        for (int i = 1; i <= n; i++){
            if (chuaXet[i]){
                dem++;
                BFS2(i, x, y);
            }
        }
        if (dem > tplt){
            cnt++;
            canhCau.push_back(it);
        }
    }
    cout << cnt << "\n";
    for (auto i : canhCau)
        cout << i.first << " " << i.second << "\n";
    return 0;
}