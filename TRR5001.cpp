#include <bits/stdc++.h>
using namespace std;
int inf = 10000;
int s, t, n, a[200][200];
vector<bool> chuaXet(200, 1);
vector<int> d(200, inf), truoc(200, 0);
vector<pair<int, int>> Ke[200];
void khoiTao(){
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] < inf) Ke[i].push_back({j, a[i][j]});
        }
    }
    d[s] = 0;
}
void lap(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()){
        auto p = q.top(); q.pop();
        int u = p.second;
        for (auto it : Ke[u]){
            int v = it.first, w = it.second;
            if (d[v] > d[u] + w){
                d[v] = d[u]+w;
                truoc[v] = u;
                q.push({d[v], v});
            }
        }
    }
}
void in(){
    if (d[t] == inf){
        cout << 0;
        return;
    }
    vector<int> path;
    int curr = t;
    while (curr != 0){
        path.push_back(curr);
        curr = truoc[curr];
    }
    reverse(path.begin(), path.end());
    cout << d[t] << "\n";
    for (int i : path) cout << i << " ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    khoiTao();
    lap();
    in();
    return 0;
}