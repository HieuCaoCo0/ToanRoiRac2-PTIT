#include <bits/stdc++.h>
using namespace std;
struct Canh{
    int u, v, ts;
    Canh(int u, int v, int ts) : u(u), v(v), ts(ts){}
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, V, E;
    vector<Canh> ds;
    cin >> t >> V >> E;
    for (int i = 0; i < E; i++){
        int u, v, ts;
        cin >> u >> v >> ts;
        ds.push_back(Canh(u, v, ts));
    }
    if (t == 1){
        for (int i = 1; i <= V; i++){
            int deg = 0;
            for (auto j : ds){
                if (i == j.u || i == j.v) deg++;
            } cout << deg << " ";
        } cout << "\n";
    }
    if (t == 2){
        int mt[105][105] = {0};
        for (auto i : ds){
            mt[i.u][i.v] = i.ts;
            mt[i.v][i.u] = i.ts;
        }
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                if (mt[i][j] == 0 && i != j) cout << "10000 ";
                else cout << mt[i][j] << " ";
            } cout << "\n";
        }
    }
    return 0;
}