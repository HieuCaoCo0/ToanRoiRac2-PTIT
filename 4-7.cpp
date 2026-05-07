#include <bits/stdc++.h>
using namespace std;
struct Canh{
    int u, v, ts;
    Canh(int u, int  v, int ts) : u(u), v(v), ts(ts){}
};
int n, m;
vector<Canh> canh;
int parent[105], num[105];

void init(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        num[i] = 1;
    }
}
int find(int u){
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}
bool Union(int a, int b){
    a = find(a); b = find(b);
    if (a == b) return 0;
    if (num[a] < num[b]) swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    return 1;
}
bool cmp(Canh a, Canh b){
	if(a.ts==b.ts){
		if(a.u==b.u) return a.v<b.v;
		return a.u<b.u; 
	}
	return a.ts<b.ts;
}
void kruskal(){
    vector<Canh> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (int i = 0; i < m; i++){
        if (mst.size() == n-1) break;
        Canh e = canh[i];
        if (Union(e.u, e.v)){
            mst.push_back(e);
            d += e.ts;
        }
    }
    if (mst.size() != n-1){
        cout << "0\n";
        return;
    }
    cout << d << "\n";
    for (auto e : mst){
        int x = min(e.u, e.v);
        int y = max(e.u, e.v);

        cout << x << " " << y << " " << e.ts << "\n";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++){
        int u, v, ts;
        cin >> u >> v >> ts;
        canh.push_back({u, v, ts});
    }
    kruskal();
    
    return 0;
}

