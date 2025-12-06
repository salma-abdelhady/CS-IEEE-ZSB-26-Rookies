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

int n, m;
vector<string> mp;
vector<vector<bool>> visited;

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
            visited[i][j] = false;
        }
    }

    cout << ConnectedComponentsCnt() << endl;
}

int32_t main(){
    FastIO();
    solve();
}
