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

void func(vector<ll>& v, vector<ll>& use){
    ll n = v.size();
    for(ll i = 0 ; i < (1LL << n) ; i++){
        ll sum = 0;
        for(ll j = 0 ; j <= n ; j++){
            if((1LL << j) & i) sum += v[j];
        }
        use.push_back(sum);
    }
}

void solve(){ 
    ll n, k; cin >> n >> k;
    vector<ll> v(n); for(int i = 0 ; i < n ; i++) cin >> v[i];
    vector<ll> u1, u2;
    vector<ll> a, b;
    for(int i = 0 ; i < n ; i++){
        if(i < (n+1)/2) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    func(a, u1);
    func(b, u2);
    sort(u1.begin(), u1.end());
    sort(u2.begin(), u2.end());
    ll ans = 0;
    for(const ll& t : u1){
        ll l = lower_bound(u2.begin(), u2.end(), k-t) - u2.begin();
        ll r = upper_bound(u2.begin(), u2.end(), k-t) - u2.begin();
        ans += (r - l);
    }
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