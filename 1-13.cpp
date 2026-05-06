#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, n, a[105][105];
    cin >> t >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    if (t == 1){
        int deg_i[105] = {0}, deg_o[105] = {0};
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j]){
                    deg_i[j]++;
                    deg_o[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << deg_i[i] << " " << deg_o[i] << "\n";
    }
    else if (t == 2){
        vector<int> Ke[105];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j]) Ke[i].push_back(j);
            }
        }
        cout << n << "\n";
        for (int i = 1; i <= n; i++){
            cout << Ke[i].size() << " ";
            for (int v : Ke[i]) cout << v << " ";
            cout << "\n";
        }
    }
    return 0;
}