#include <bits/stdc++.h>
using namespace std;
int n, m, p;
bool chuaXet[105];
vector<int> Ke[105];
void DFS(int u){
    stack<int> st;
    st.push(u);
    while (!st.empty()){
        int x = st.top(); st.pop();
        if (chuaXet[x]){
            cout << x << " ";
            chuaXet[x] = 0;
            for (int i = Ke[x].size()-1; i >= 0; i--){
                int v = Ke[x][i];
                if (chuaXet[v]) st.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(chuaXet, 1, sizeof(chuaXet));
    cin >> n >> m >> p;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        Ke[u].push_back(v);
        Ke[v].push_back(u);
    }
    DFS(p);
    return 0;
}