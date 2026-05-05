#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, V, E, n;
    vector<int> Ke[105];
    cin >> t;
    cin >> V;
        cin.ignore();
        for (int i = 1; i <= V; i++){
            int k, u;
            cin >> k;
            for (int j = 0; j < k; j++){
                cin >> u;
                Ke[i].push_back(u);
            }
        }
    if (t == 1){
        for (int i = 1; i <= V; i++) cout << Ke[i].size() << " ";
        cout << "\n";
    }
    else if (t == 2){
        int mt[105][105] = {0};
        for (int i = 1; i <= V; i++){
            for (int j : Ke[i]) mt[i][j] = 1;
        }
        cout << V << "\n";
        for (int i = 1; i <= V; i++){
            for (int j = 1; j <= V; j++){
                cout << mt[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}