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
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            int deg = 0;
            for (int j = 1; j <= n ;j++){
                if (a[i][j]) deg++;
            }
            cout << deg << " ";
        }
        cout << "\n";
    }
    else if (t == 2){
        int mt[105][105] = {0};
        vector<pair<int, int>> ds;
        for (int i = 1; i <= n; i++){
            for (int j = i+1; j <= n; j++){
                if (a[i][j]) ds.push_back({i, j});
            }
        }
        cout << n << " " << ds.size() << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < ds.size(); j++){
                if (i == ds[j].first || i == ds[j].second){
                    mt[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < ds.size(); j++){
                cout << mt[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}