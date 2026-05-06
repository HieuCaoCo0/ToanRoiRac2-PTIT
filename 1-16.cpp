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
        vector<int> Ke[105];
        for (auto i : ds)
            Ke[i.first].push_back(i.second);
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            cout << Ke[i].size() << " ";
            for (int v : Ke[i]) cout << v << " ";
            cout << "\n";
        }
    }
    return 0;
}