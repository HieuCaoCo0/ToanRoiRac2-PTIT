#include <bits/stdc++.h>
using namespace std;
int a[1000][1000], d[1000], trc[1000];
bool chuaXet[1000];
int n, s, t;
int main(){
    // nhap gia tri
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++) cin >> a[i][j];
    }
    // khoi tao
    memset(chuaXet, 1, sizeof(chuaXet));
    for (int i = 1; i <= n; i++){
        d[i] = 10000;
        trc[i] = s; // truoc tca ca dinh la s
    }
    d[s] = 0;

    int k = 1;
    while (k <= n-1){
        k++;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (d[i] > d[j] + a[j][i]){
                    d[i] = d[j] + a[j][i];
                    trc[j] = i;
                }
            }
        }
        bool checkChuTrinhAm = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (d[i] > d[j] + a[j][i]){
                    checkChuTrinhAm = 1;
                }
            }
        }
        if (checkChuTrinhAm){
            cout << "Chu trinh am\n";
            return 0;
        }
    }
    
    if (d[t] == 10000) cout << "Khong co duong di\n";
    else{
        vector<int> path;
        int curr = t;
        while (curr != 0){
            path.push_back(curr);
            curr = trc[curr];
        }
        reverse(path.begin(), path.end());
        for (int i : path) cout << i << " ";
    }
    return 0;
}