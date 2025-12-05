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

bool iscycle(int st, int from, vector<vector<int>> &lst, vector<bool> &visited){
    visited[st] = true;
    for(auto i : lst[st]){
        if(!visited[i]){
            if(iscycle(i, st, lst, visited)) return true;
        }
        else if(i != from) return true;
    }
    return false;
}

bool is_tree(int n, vector<vector<int>> &lst){
    vector<bool>visited(n+1, false);

    if(iscycle(1, -1, lst, visited)) return false;

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            return false;
    }
    return true;
}
void solve(){
    int n, m; cin >> n >> m;

    if(m != n - 1){
        cout << "NO";
        return;
    }

    vector<vector<int>>adjlist(n+1);
    for(int i = 0;i < m; i++){
        int u, v; cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    if(is_tree(n,adjlist)) cout << "YES";
    else cout << "NO";
}

int32_t main(){
    FastIO();
    solve();
}
