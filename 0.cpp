#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n, s, t, a[101][101], truoc[101];
vector<int> d(101,inf);
void bellman_ford(){
	d[s]=0;
	for(int k=1;k<=n-1;k++){
		for(int v=1;v<=n;v++){
			if(v!=s){
				for(int u=1;u<=n;u++){
					if(a[u][v]!=10000&&d[u]!=inf&&d[u]+a[u][v]<d[v]){
						d[v]=d[u]+a[u][v];
						truoc[v]=u;
					}
				}
			}
		}
	}
}
void path(){
	for(int v=1;v<=n;v++){
		if(v!=s){
			for(int u=1;u<=n;u++){
				if(a[u][v]!=10000&&d[u]!=inf&&d[u]+a[u][v]<d[v]){
					cout << -1;
					return;
				}
			}
		}
	}
	if(d[t]==inf) cout << 0;
	else{
		vector<int> v;
		cout << d[t] << endl;
		while(t!=s){
			v.push_back(t);
			t=truoc[t];
		}
		v.push_back(s);
		for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
	}
}
int main(){
	freopen("BN.INP","r",stdin);
	freopen("BN.OUT","w",stdout);
	cin >> n >> s >> t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	bellman_ford();
	path();
}