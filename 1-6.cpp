#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t, V, E, u, v;
    cin >> t >> V >> E;
    vector<pair<int, int>> ds;
    for (int i = 0; i < E; i++){
        cin >> u >> v;
        ds.push_back({u, v});
    }
    if (t == 1){
        int deg[105];
        for (auto i : ds){
            deg[i.first]++;
            deg[i.second]++;
        }
        for (int i = 1; i <= V; i++){
            cout << deg[i] << " ";
        } cout << "\n";
    }
    else if (t == 2){
        int mt[105][1005] = {0};
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < E; j++){
                if (i == ds[j].first || i == ds[j].second){
                    mt[i][j] = 1;
                }
            }
        }
        cout << V << " " << E << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < E; j++){
                cout << mt[i][j] << " ";
            } cout << "\n";
        }
        // cout << V << " " << ds.size() << "\n";
        // for (int i = 1; i <= V; i++){
        //     for (int j = 0; j < ds.size(); j++){
        //         if (i == ds[j].first || i == ds[j].second){
        //             mt[i][j] = 1;
        //         }
        //     }
        // }
        // for (int i = 1; i <= V; i++){
        //     for (int j = 0; j < ds.size(); j++){
        //         cout << mt[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    return 0;
}