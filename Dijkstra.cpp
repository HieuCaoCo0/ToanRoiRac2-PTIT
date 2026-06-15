#include <bits/stdc++.h>
using namespace std;
int a[1000][1000], d[1000], trc[1000];
bool chuaXet[1000];
int n, s, t;
int main(){
    // nhap gia tri
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++) cin >> a[i][j];
    }
    // khoi tao
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        d[i] = 10000;
        trc[i] = 0;
    }
    d[s] = 0;

    while (1){
        int u = 0;
        int min_d = 10000;
        for (int i = 1; i <= n; i++){
            if (chuaXet[i] && d[i] < min_d){
                min_d = d[i];
                u = i;
            }
        }
        if (u == 0 || u == t) break;
        chuaXet[u] = 0;
        for (int i = 1; i <= n; i++){
            if (chuaXet[i] && d[i] > d[u] + a[u][i]){
                d[i] = d[u] + a[u][i];
                trc[i] = u;
            }
        }
    }
    if (d[t] == 10000) cout << "Khong co duong di\n";
    else{
        vector<int> path;
        int curr = t;
        while (curr != 0){
            path.push_back(curr);
            curr = trc[curr];
        }
        reverse(path.begin(), path.end());
        for (int i : path) cout << i << " ";
    }
    return 0;
}