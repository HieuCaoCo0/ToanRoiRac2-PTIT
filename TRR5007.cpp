#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
int n, s, t, a[200][200];
vector<int> truoc(200, -1), d(200, inf);
bool chuTrinhAm = 0;
void khoiTao(){
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    d[s] = 0;
    truoc[s] = 0;
}
void lap(){
    for (int k = 1; k <= n-1; k++){
        for (int v = 1; v <= n; v++){
            if (v != s){
                for (int u = 1; u <= n; u++){
                    if (a[u][v] != 10000 && d[u] != 10000 && d[v] > d[u] + a[u][v]){
                        d[v] = d[u] + a[u][v];
                        truoc[v] = u;
                    }
                }
            }
        }
    }
    for (int v = 1; v <= n; v++){
        if (v != s){
            for (int u = 1; u <= n; u++){
                if (a[u][v] != 10000 && d[u] != 10000 && d[v] > d[u] + a[u][v]){
                    chuTrinhAm = 1;
                    return;
                }
            }
        }
    }
}
void in(){
    if (chuTrinhAm) {cout << -1; return;}
    if (d[t] == inf){
        cout << 0;
        return;
    }
    vector<int> path;
    int curr = t;
    while (curr != 0){
        path.push_back(curr);
        curr = truoc[curr];
    }
    reverse(path.begin(), path.end());
    cout << d[t] << "\n";
    for (int i : path) cout << i << " ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    khoiTao();
    lap();
    in();
    return 0;
}