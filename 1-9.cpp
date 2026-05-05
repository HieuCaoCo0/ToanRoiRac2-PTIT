#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t, V, E;
    vector<int> Ke[105];
    cin >> t >> V;
        cin.ignore();
        for (int i = 1; i <= V; i++){
            int k, u;
            cin >> k;
            for (int j = 0; j < k; j++){
                cin >> u;
                Ke[i].push_back(u);
            }
        }
    if (t == 1){
        for (int i = 1; i <= V; i++) cout << Ke[i].size() << " ";
        cout << "\n";
    }
    else if (t == 2){
        vector<pair<int, int>> ds;
        for (int i = 1; i <= V; i++){
            for (int j : Ke[i]){
                if (i < j) ds.push_back({i, j});
            }
        }
        cout << V << " " << ds.size() << "\n";
        int mt[105][1000] = {0};
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < ds.size(); j++){
                if (i == ds[j].first || i == ds[j].second){
                    mt[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= V; i++){
            for (int j = 0; j < ds.size(); j++){
                cout << mt[i][j] << " ";
            } cout << "\n";
        }
    }
    return 0;
}