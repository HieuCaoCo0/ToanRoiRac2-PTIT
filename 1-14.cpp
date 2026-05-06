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
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (t == 1){
        int deg_in[105] = {0}, deg_out[105] = {0};
        for (int i = 1;i <= n ; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j]){
                    deg_in[j]++;
                    deg_out[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    }
    else if (t == 2){
        vector<pair<int, int>> ds;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j]) ds.push_back({i, j});
            }
        }
        int mt[105][200] = {0};
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < ds.size(); j++){
                if (i == ds[j].first) mt[i][j] = 1;
                else if (i == ds[j].second) mt[i][j] = -1;
            }
        }
        cout << n << " " << ds.size() << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < ds.size(); j++){
                cout << mt[i][j] << " ";
            }cout << "\n";
        }
    }
    return 0;
}