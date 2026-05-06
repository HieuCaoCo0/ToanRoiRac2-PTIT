#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, V, E;
    vector<int> Ke[105];
    cin >> t >> V;
    for (int i = 1; i <= V; i++){
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            int v; cin >> v;
            Ke[i].push_back(v);
        }
    }
    if (t == 1){
        int deg_in[105] = {0}, deg_out[105] = {0};
        for (int i = 1; i <= V; i++){
            deg_out[i] = Ke[i].size();
            for (int v : Ke[i]) deg_in[v]++;
        }
        for (int i = 1; i <= V; i++)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    }
    if (t == 2){
        vector<pair<int, int>> ds;
        for (int i = 1; i <= V; i++){
            for (int v : Ke[i]){
                ds.push_back({i, v});
            }
        }
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