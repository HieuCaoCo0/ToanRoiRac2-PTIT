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
    int t, n, a[105][105];
    cin >> t >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (t == 1){
        int deg_in[105] = {0}, deg_out[105] = {0};
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] != 0 && a[i][j] != 10000){
                    deg_in[j]++;
                    deg_out[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << deg_in[i] << " " << deg_out[i] << "\n";
    }
    else if (t == 2){
        vector<Canh> ds;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] != 0 && a[i][j] != 10000){
                    ds.push_back(Canh(i, j, a[i][j]));
                }
            }
        }
        cout << n << " " << ds.size() << "\n";
        for (auto i : ds)
            cout << i.u << " " << i.v << " " << i.ts << "\n";
    }
    return 0;
}