#include <bits/stdc++.h>
using namespace std;
int a[1000][1000], d[1000][1000], Next[1000][1000];
bool chuaXet[1000];
int n, s, t;
int main(){
    // nhap gia tri
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cin >> a[i][j];
            d[i][j] = a[i][j];
            if (i != j && a[i][j] < 10000) Next[i][j] = j;
            else Next[i][j] = -1;
        }
    }
    // khoi tao
    memset(chuaXet, 1, sizeof(chuaXet));

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    Next[i][j] = k;
                }
            }
        }
    }
    if (Next[s][t] == -1) cout << "khong co duong di";
    else {
        vector<int> path;
        int curr = s;
        while (curr != -1){
            path.push_back(curr);
            curr = Next[curr][t];
        }
        for (int i : path) cout << i << " ";
    }
    
    return 0;
}