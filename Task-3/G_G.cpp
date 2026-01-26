#include <bits/stdc++.h>

using namespace std;

#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("joseph.in", "r", stdin); freopen("joseph.out", "w", stdout); }
const int mod = 1000000007;

string s, t;
int s_size, t_size;
vector<vi>dp;


int rec(int i, int j){
    if(i == s_size || j == t_size) return 0;

    int &ret = dp[i][j];

    if(ret != -1) return ret;

    int res = INT_MIN;

    if(s[i] == t[j]) res = max(res,rec(i+1,j+1) + 1);
    else{
        res = max(res, rec(i, j+1));
        res = max(res, rec(i+1, j));
    }
    
    return ret = res;
}


void print(int i, int j){
    if(i == s_size || j == t_size) return;

    int ret = dp[i][j];

    if(s[i] == t[j]){
        if(ret == rec(i+1,j+1)+1){
            cout << s[i];
            print(i+1,j+1);
            return;
        }
    }

    else{
        if(ret == rec(i,j+1)){
            print(i,j+1);
            return;
        }
        if(ret == rec(i+1,j)){
            print(i+1,j);
            return;
        }
    }
    return;
}

void solve(){
    cin >> s >> t;
    s_size = s.size();
    t_size = t.size();

    dp.assign(3001,vi(3001,-1));

    rec(0,0);
    print(0,0);
}

int32_t main()
{
    FastIO();
    //UseFile();
    solve();
    return 0;
}
