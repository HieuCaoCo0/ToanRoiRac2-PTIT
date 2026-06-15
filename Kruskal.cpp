#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int u, v, w;
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
deque<Edge> V, T;
int n;
bool cmp(Edge a, Edge b){
    if (a.w == b.w){
        if (a.u == b.u) return a.v < b.v;
        return a.u < b.u;
    }
    return a.w < b.w;
}
bool chuTrinh(){
    int cnt = 0, arr[1000];
    for (int i = 0; i < T.size(); i++){
        arr[T[i].u] = 1;
        arr[T[i].v] = 1;
    }
    for (int i = 0; i < 1000; i++) cnt += arr[i];
    return (cnt == T.size()+1); // Khong co chu trinh
}
void Kruskal(){
    int d = 0;
    sort(V.begin(), V.end(), cmp);
    while (T.size() < n-1){
        Edge e = V.front();
        V.pop_front();
        T.push_back(e);
        if (chuTrinh()) T.pop_back();
        else d += e.w;
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        V.push_back({u, v, w});
    }
    Kruskal();
}