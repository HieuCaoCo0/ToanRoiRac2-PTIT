#include <bits/stdc++.h>
using namespace std;
struct Canh{
    int u, v, ts;
    Canh(int u, int  v, int ts) : u(u), v(v), ts(ts){}
};
int t, n, s, a[105][105];
bool chuaXet[105];
vector<pair<int, int>> Ke[105];


void prim(int u){
    vector<Canh> MST;
    int d = 0;
    chuaXet[u] = 0;
    while (MST.size() < n-1){
        int min_w = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++){
            if (!chuaXet[i]){
                for (auto it : Ke[i]){
                    int j = it.first, ts = it.second;
                    if (chuaXet[j] && ts < min_w){
                        min_w = ts;
                        X = j; Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        chuaXet[X] = 0;
    }
    cout << d << "\n";
    for (auto e : MST){
        if (e.u > e.v) swap(e.u, e.v);
        cout << e.u << " " << e.v << " " << e.ts << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> s;
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                Ke[i].push_back({j, a[i][j]});
                Ke[j].push_back({i, a[i][j]});
            }
        }
    }
    prim(s);
    
    return 0;
}

