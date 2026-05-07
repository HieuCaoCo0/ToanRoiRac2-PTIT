#include <bits/stdc++.h>
using namespace std;
int t, n, s, a[105][105];
bool chuaXet[105];
vector<int> Ke[105];
vector<pair<int, int>> tree;
void DFS(int u){
    chuaXet[u] = 0;
    for (int v : Ke[u]){
        if (chuaXet[v]){
            tree.push_back({u, v});
            DFS(v);
        }
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    chuaXet[u] = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        chuaXet[x] = 0;
        for (int v : Ke[x]){
            if (chuaXet[v]){
                tree.push_back({x, v});
                q.push(v);
                chuaXet[v] = 0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> t >> n >> s;
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                Ke[i].push_back(j);
                Ke[j].push_back(i);
            }
        }
    }
    if (t == 1) DFS(s);
    else if (t == 2) BFS(s);
    cout << n-1 << "\n";
    for (auto br : tree){
        if (br.first > br.second) swap(br.first, br.second);
        cout << br.first << " " << br.second << "\n";
    }
    return 0;
}

