#include <bits/stdc++.h>
using namespace std;
int pre[105];
bool chuaXet[105];
void DFS(int u, int a[105][105], int n){
    chuaXet[u] = 0;
    for (int v = 1; v <= n; v++){
        if (a[u][v] && chuaXet[v]){
            pre[v] = u;
            DFS(v, a, n);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t, n, u, v, a[105][105];
    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    if (t == 1){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (a[u][i] && a[i][v]) cnt++;
        }
        cout << cnt << "\n";
    }
    else if (t == 2){
        memset(pre, 0, sizeof(pre));
        memset(chuaXet, 1, sizeof(chuaXet));
        DFS(u, a, n);
        if (chuaXet[v]){
            cout << "0\n";
            return 0;
        }
        vector<int> path;
        int cur = v;
        while (cur != 0){
            path.push_back(cur);
            if (cur == u) break;
            cur = pre[cur];
        }
        reverse(path.begin(), path.end());
        for (int i : path) cout << i << " ";
        cout << "\n";
    }
    return 0;
}