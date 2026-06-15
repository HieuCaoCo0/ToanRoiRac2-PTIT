#include <bits/stdc++.h>
using namespace std;
int inf = 10000;
int s, t, n, a[200][200];
int d[200][200], Next[200][200];
void khoiTao(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            d[i][j] = a[i][j];
            if (i != j && a[i][j] < 10000) Next[i][j] = j;
            else Next[i][j] = -1;
        }
    }
}
void lap(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}
void in(){
    int x, y, z = -10000;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j && d[i][j] > z && d[i][j] != 10000){
                z= d[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << x << " " << y << " " << z << "\n";
    while (x != -1){
        cout << x << " ";
        x = Next[x][y];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    khoiTao();
    lap();
    in();
    return 0;
}