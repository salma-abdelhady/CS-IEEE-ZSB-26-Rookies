#include <bits/stdc++.h>

using namespace std;

#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
#define dpp(arr,val) memset(arr,val,sizeof(arr))
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
void UseFile(){freopen("divsnums.in", "r", stdin);}
const int mod = 1000000007;
//const int sz = 1e5+10;
const double PI = 3.14159265358979323846;

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> adj_list(n + 1);

    while(m--){
        int v,u; cin >> v >> u;
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        cout << adj_list[i].size() << endl;
    }

}

int32_t main(){
    FastIO();
    solve();
}
