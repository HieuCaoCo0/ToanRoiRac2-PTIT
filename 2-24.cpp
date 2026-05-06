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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int cnt = 0, tplt = 0;
    vector<int> dinhTru;
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        if (chuaXet[i]){
            tplt++;
            BFS(i);
        }
    }
    for (int i = 1; i <= n; i++){
        memset(chuaXet, 1, sizeof(chuaXet));
        int dem = 0;
        chuaXet[i] = 0;
        for (int j = 1; j <= n; j++){
            if (chuaXet[j]){
                dem++;
                BFS(j);
            }
        }
        if (dem > tplt){
            cnt++;
            dinhTru.push_back(i);
        }
    }
    cout << cnt << "\n";
    for (int i : dinhTru) cout << i << " ";
    cout << "\n";
    return 0;
}