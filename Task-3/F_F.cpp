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
const int MOD = 1000000007;
const int sz = 2e5+10;
const double PI = 3.14159265358979323846;

int n;
vi a, b , c;

vector<vi> dp;

int rec(int i, int ch){
    if(i == n) return 0;

    int &ret = dp[i][ch];

    if(ret != -1) return ret;

    if(ch == 1){
        ret = max(b[i] + rec(i+1, 2), c[i] + rec(i+1, 3));
    }

    else if(ch == 2){
        ret = max(a[i] + rec(i+1, 1), c[i] + rec(i+1, 3));
    }

    else if(ch == 3){
        ret = max(b[i] + rec(i+1, 2), a[i] + rec(i+1, 1));
    }

    else{
        ret = max({b[i] + rec(i+1, 2), a[i] + rec(i+1, 1), c[i] + rec(i+1,3)});
    }

    return ret;

}

void solve(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);


    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    dp.assign(n+1, vi(4,-1));

    int ans = rec(0,0);

    cout << ans << endl;
}


int32_t main(){
    FastIO();
    solve();
    return 0;
}
