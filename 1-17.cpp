#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, V, E;
    vector<pair<int, int>> ds;
    cin >> t >> V >> E;
    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        ds.push_back({u, v});
    }
    if (t == 1){
        int deg_in[105] = {0}, deg_out[105] = {0};
        for (auto i : ds){
            deg_out[i.first]++;
            deg_in[i.second]++;
        }
        for (int i = 1; i <= V; i++)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    }
    else if (t == 2){
        int mt[105][200] = {0};
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < ds.size(); j++){
                if (i == ds[j].first) mt[i][j] = 1;
                else if (i == ds[j].second) mt[i][j] = -1;
            }
        }
        cout << V << " " << ds.size() << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < ds.size(); j++){
                cout << mt[i][j] << " ";
            }cout << "\n";
        }
    }
    return 0;
}