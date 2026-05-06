#include <bits/stdc++.h>
using namespace std;
int n, a[105][105];
bool chuaXet[105];
void DFS(int u){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if (a[u][i] && chuaXet[i]) DFS(i);
    }
}
void DFS2(int u, int s, int t){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if ((u == s && i == t) || (u == t && i == s)) continue;
        if (a[u][i] && chuaXet[i]) DFS2(i, s, t);
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
            DFS(i);
        }
    }
    for (auto it : ds){
        int x = it.first, y = it.second, dem = 0;
        memset(chuaXet, 1, sizeof(chuaXet));
        for (int i = 1; i <= n; i++){
            if (chuaXet[i]){
                dem++;
                DFS2(i, x, y);
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