#include <bits/stdc++.h>

using namespace std;

//#define int    long long
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

int n, m;
vector<string> mp;
vector<vector<int>> visited;

void dfs(int x, int y){
    visited[x][y] = true;

    // up
    if(x > 0 && mp[x-1][y] == '.' && !visited[x-1][y])
        dfs(x-1,y);

    // down
    if(x < n-1 && mp[x+1][y] == '.' && !visited[x+1][y])
        dfs(x+1,y);

    // left
    if(y > 0 && mp[x][y-1] == '.' && !visited[x][y-1])
        dfs(x,y-1);

    // right
    if(y < m-1 && mp[x][y+1] == '.' && !visited[x][y+1])
        dfs(x,y+1);
}

int ConnectedComponentsCnt() {
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.' && !visited[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }

    return cnt;
}

void solve(){
    cin >> n >> m;

    mp.resize(n);
    for(int i = 0; i < n; i++){
        cin >> mp[i];
    }

    visited.resize(n);
    for(int i = 0; i < n; i++){
        visited[i].resize(m);
        for(int j = 0; j < m; j++){
            visited[i][j] = 0;
        }
    }

    cout << ConnectedComponentsCnt() << endl;
}

int32_t main(){
    FastIO();
    solve();
}
