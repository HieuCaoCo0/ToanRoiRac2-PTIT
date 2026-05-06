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
void DFS_nguoc(int u){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if (a[i][u] && chuaXet[i]) DFS_nguoc(i);
    }
}
void DFS_voHuong(int u){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if ((a[u][i] || a[i][u]) && chuaXet[i]) DFS_voHuong(i);
    }
}
bool lt_manh(){
    memset(chuaXet, 1, sizeof(chuaXet));
    DFS(1);
    for (int i = 1; i <= n; i++)
        if (chuaXet[i]) return 0;
    memset(chuaXet, 1, sizeof(chuaXet));
    DFS_nguoc(1);
    for (int i = 1; i <= n; i++)
        if (chuaXet[i]) return 0;
    return 1;
}
bool lt_yeu(){
    memset(chuaXet, 1, sizeof(chuaXet));
    DFS_voHuong(1);
    for (int i = 1; i <= n; i++)
        if (chuaXet[i]) return 0;
    return 1;
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
    if (lt_manh()) cout << "1\n";
    else if (lt_yeu()) cout << "2\n";
    else cout << "0\n";
    return 0;
}