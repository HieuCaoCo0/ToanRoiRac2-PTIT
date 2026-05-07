#include <bits/stdc++.h>
using namespace std;
int n, u, a[105][105], cnt = 0;
vector<int> Ke[105];
int path[105];
bool chuaXet[105];
void haminton(int k){
    for (int v : Ke[path[k-1]]){
        if (chuaXet[v]){
            path[k] = v;
            chuaXet[v] = 0;
            if (k == n){
                for (int x : Ke[v]){
                    if (x == u){
                        cnt++;
                        for (int i = 1; i <= n; i++) cout << path[i] << " ";
                        cout << u << "\n";
                    }
                }
            }
            else haminton(k+1);
            chuaXet[v] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                Ke[i].push_back(j);
                // Ke[j].push_back(i);
            }
        }
    }
    path[1] = u;
    chuaXet[u] = 0;
    haminton(2);
    cout << cnt << "\n";
    return 0;
}

