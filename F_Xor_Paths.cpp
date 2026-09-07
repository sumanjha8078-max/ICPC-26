/*
    "It is now or never!"
    
*/

#define ll long long
#define mod (1000000007)

#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

map<ll,ll> use[21][21];
ll a[21][21];
ll ans = 0, s1, s2;
ll n, m, k;

void func1(ll x, ll y, ll count, ll z){
    z ^= a[x][y];
    if(count == s1){
        use[x][y][z]++;
        return;
    }
    ll x1 = x + 1, y1 = y+1;
    if(x1 < n) func1(x1, y, count+1, z);
    if(y1 < m) func1(x, y1, count+1, z);
}

void func2(ll x, ll y, ll count, ll z){
    if(count == s2){
        if(use[x][y].count(k^z)){
            ans += use[x][y][k^z];
        }
        return;
    }
    z ^= a[x][y];
    if(x - 1 >= 0) func2(x-1, y, count+1, z);
    if(y - 1 >= 0) func2(x, y-1, count+1, z);
}

void solve(){ 
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++) cin >> a[i][j];
    }
    s1 = (n + m - 2)/2;
    s2 = (n + m - 2) - s1;
    func1(0, 0, 0, 0);
    func2(n-1, m-1, 0, 0);
    cout << ans << "\n";
}

int main(){
    fast_io();
    ll t = 1; // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}