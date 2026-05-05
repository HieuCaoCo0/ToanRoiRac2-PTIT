#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, V, E, u, v;
    cin >> t >> V >> E;
    vector<pair<int, int>> ds(E+1);
    for (int i = 0; i < E; i++){
        cin >> u >> v;
        ds.push_back({u, v});
    }
    if (t == 1){
        vector<int> deg(V+1);
        for (auto i : ds){
            deg[i.first]++;
            deg[i.second]++;
        }
        for (int i = 1; i <= V; i++){
            cout << deg[i] << " ";
        } cout << "\n";
    }
    else if (t == 2){
        int a[105][105] = {0};
        for (auto i : ds){
            a[i.first][i.second] = 1;
            a[i.second][i.first] = 1;
        }
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                cout << a[i][j] << " ";
            } cout << "\n";
        }
    }
    return 0;
}