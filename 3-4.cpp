#include <bits/stdc++.h>
using namespace std;
int t, n, a[105][105];
set<int> Ke[105];
bool chuaXet[105];
int deg_in[105] = {0}, deg_out[105] = {0};
void nhapMT(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                Ke[i].insert(j);
                deg_in[j]++;
                deg_out[i]++;
            }
        }
    }
}
void DFS(int u){
    chuaXet[u] = 0;
    for (int i = 1; i <= n; i++){
        if ((a[u][i] || a[i][u]) && chuaXet[i]) DFS(i);
    }
}
void mode1(){
    cin >> n;
    nhapMT();
    memset(chuaXet, 1, sizeof(chuaXet));
    int tplt = 0;
    for (int i = 1; i <= n; i++){
        if (chuaXet[i] && (deg_in[i] + deg_out[i] > 0)){
            tplt++;
            DFS(i);
        }
    }
    if (tplt > 1){
        cout << "0\n";
        return;
    }
    int dau = 0, cuoi = 0;
    for (int i = 1; i <= n; i++){
        int diff = deg_out[i] - deg_in[i];
        if (diff == 1) dau++;
        else if (diff == -1) cuoi++;
        else if (diff != 0){
            cout << "0\n";
            return;
        }
    }
    if (dau == 1 && cuoi == 1) cout << "2\n";
    else if (dau == 0 && cuoi == 0) cout << "1\n";
    else cout << "0\n";
}
void mode2(){
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t;
    if (t == 1) mode1();
    else if (t == 2) mode2();    
    return 0;
}

/*
1
4
0 1 0 1
0 0 0 1
1 0 0 0
0 0 1 0
*/