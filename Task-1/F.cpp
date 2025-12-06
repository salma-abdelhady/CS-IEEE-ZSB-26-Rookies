#include <bits/stdc++.h>
using namespace std;

#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

void solve(){
    int n, m; cin >> n >> m;

    vector<pii>forb;
    vi node_count(n+1,0);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        forb.push_back({u,v});
        node_count[u]++;
        node_count[v]++;
    }

    int center = 1;
    for(int i = 2; i <= n; i++){
        if(node_count[i] < node_count[center]){
            center = i;
        }
    }

    vector<pii> edges;

    for(int i = 1; i <= n; i++){
        if(i != center){
            bool can = true;
            for(int j = 0; j < m; j++){
                int u = forb[j].first;
                int v = forb[j].second;
                if((u == i && v == center) || (v == i && u == center)){
                    can = false;
                    break;
                }
            }
            if(can){
                edges.push_back({i,center});
            }
        }
    }

    cout << edges.size() << endl;
    for(int i = 0; i < edges.size(); i++){
        cout << edges[i].first << " "<< edges[i].second << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
}
