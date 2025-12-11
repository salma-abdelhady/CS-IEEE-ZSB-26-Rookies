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

const int N = 1005;
int n, m, Spath = 0; char s[N][N]; vector<pair<int,int>>adj[N];
string ans = "NO\n";

struct node{
    int x, y, cost;
    node(int X, int Y, int C):x(X), y(Y), cost(C){}
};

bool valid(int x, int y){
    return x>=0&&y>=0&&x<n&&y<m&&s[x][y]=='.'||s[x][y]== 'B';
}

void bfs(int startX, int startY, int endX, int endY){
    queue<node> q;
    q.push(node(startX, startY, 0));

    while(!q.empty()){
        node p = q.front();
        q.pop();

        if(p.x == endX && p.y == endY){
            ans = "YES\n";
            Spath = p.cost;
            return;
        }

        if(valid(p.x, p.y-1)) q.push(node(p.x, p.y-1,p.cost+1)), s[p.x][p.y-1] = 'L'; // 0,-1
        if(valid(p.x, p.y+1)) q.push(node(p.x, p.y+1,p.cost+1)), s[p.x][p.y+1] = 'R'; // 0,+1
        if(valid(p.x-1, p.y)) q.push(node(p.x-1, p.y,p.cost+1)), s[p.x-1][p.y] = 'U'; // -1,0
        if(valid(p.x+1, p.y)) q.push(node(p.x+1, p.y,p.cost+1)), s[p.x+1][p.y] = 'D'; // 1,0
    }
}
void solve(){
    cin >> n >> m;
    int startX, startY, endX, endY;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
            if(s[i][j] == 'A'){
                startX = i, startY = j;
            }
            else if(s[i][j] == 'B'){
                endX = i, endY = j;
            }
        }
    }

    bfs(startX, startY, endX, endY);
    cout << ans;
    if(ans == "YES\n"){
        cout << Spath << endl;
        int i = endX, j = endY;
        string path = "";
        while(i!=startX || j != startY){
            path += s[i][j];
            if(s[i][j] == 'L') j++;
            else if(s[i][j] == 'R') j--;
            else if(s[i][j] == 'U') i++;
            else if(s[i][j] == 'D') i--;
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
}
int32_t main(){
    FastIO();
    solve();
}
