#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

int n, m, k;
vector<vector<char>> maze;
vector<pii> leaf_nodes;
vector<vector<bool>> visited;

void dfs(int x, int y){
    visited[x][y] = true;

    leaf_nodes.push_back({x,y});

    // up
    if(x > 0 && maze[x-1][y] == '.' && !visited[x-1][y]){
        dfs(x-1,y);
    }

    // down
    if(x < n-1 && maze[x+1][y] == '.' && !visited[x+1][y]){
        dfs(x+1,y);
    }

    // left
    if(y > 0 && maze[x][y-1] == '.' && !visited[x][y-1]){
        dfs(x,y-1);
    }

    // right
    if(y < m-1 && maze[x][y+1] == '.' && !visited[x][y+1]){
        dfs(x,y+1);
    }
}

void solve(){
    cin >> n >> m >> k;

    maze.resize(n);
    for(int i = 0; i < n; i++){
        maze[i].resize(m);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    visited.resize(n);
    for(int i = 0; i < n; i++){
        visited[i].resize(m);
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }

    int x = -1 , y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == '.'){
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }

    dfs(x,y);

    for(int i = leaf_nodes.size()-1; i >= 0 && k > 0; i--, k--){
        maze[leaf_nodes[i].first][leaf_nodes[i].second] = 'X';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
}
