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
        vector<int> Ke[105];
        for (auto i : ds){
            Ke[i.first].push_back(i.second);
            Ke[i.second].push_back(i.first);
        }
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            cout << Ke[i].size() << " ";
            for (int v : Ke[i]) cout << v << " ";
            cout << "\n";
        }
    }
    return 0;
}