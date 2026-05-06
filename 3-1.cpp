#include <bits/stdc++.h>
using namespace std;
int t, n, a[105][105];
set<int> Ke[105];
bool chuaXet[105];
void nhapMT(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                Ke[i].insert(j);
                Ke[j].insert(i);
            }
        }
    }
}
void DFS(int u){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if (a[u][i] && chuaXet[i]) DFS(i);
    }
}
void findEuler(){
    int u;
    cin >> n >> u;
    nhapMT();

    stack<int> st;
    vector<int> EC;
    st.push(u);
    while (!st.empty()){
        int x = st.top();
        if (Ke[x].size() > 0){
            int y = *Ke[x].begin();
            st.push(y);
            Ke[x].erase(y);
            Ke[y].erase(x);
        }
        else{
            EC.push_back(x);
            st.pop();
        }
    }
    reverse(EC.begin(), EC.end());
    for (int i : EC) cout << i << " ";
    cout << "\n";
}
void checkEuler(){
    cin >> n;
    memset(chuaXet, 1, sizeof(chuaXet));
    nhapMT();
    int deg[105] = {0};
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            if (a[i][j]) deg[i]++;
    }
    int tplt = 0;
    for (int i = 1; i <= n; i++){
        if (chuaXet[i]){
            tplt++;
            DFS(i);
        }
    }
    int le = 0;
    for (int i = 1; i <= n; i++){
        if (deg[i] % 2 == 1) le++;
        if (le > 2){
            cout << "0\n";
            return;
        }
        else if (deg[i] == 0) tplt--;
    }
    if (le == 2 && tplt == 1) cout << "2\n";
    else if (le == 0 && tplt == 1) cout << "1\n";
    else cout << "0\n"; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t;
    if (t == 1) checkEuler();
    else if (t == 2) findEuler();
    return 0;
}