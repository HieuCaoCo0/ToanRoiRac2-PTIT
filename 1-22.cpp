#include <bits/stdc++.h>
using namespace std;
struct Canh{
    int u, v, ts;
    Canh(int u,int v, int ts) : u(u), v(v), ts(ts){}
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
        int deg_in[105] = {0}, deg_out[105] = {0};
        for (auto i : ds){
            deg_in[i.v]++;
            deg_out[i.u]++;
        }
        for (int i = 1; i <= V; i++)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    }
    if (t == 2){
        int a[105][105] = {0};
        for (auto i : ds) a[i.u][i.v] = i.ts;
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                if (i != j && a[i][j] == 0) cout << "10000 ";
                else cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}