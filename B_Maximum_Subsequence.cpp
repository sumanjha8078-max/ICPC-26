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

ll n, m;
map<ll,ll> mp1, mp2;
ll s1;
ll arr[37];

void func1(ll i, ll sum, ll s){
    if(i == s){
        mp1[sum % m]++;
        return;
    }
    func1(i+1, sum + arr[i], s);
    func1(i+1, sum, s);
}

void func2(ll i, ll sum, ll s){
    if(i == s){
        mp2[sum % m]++;
        return;
    }
    func2(i+1, sum + arr[i], s);
    func2(i+1, sum, s);
}

void solve(){ 
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    s1 = n/2;
    func1(0, 0, s1);
    func2(s1, 0, n);
    ll ans = 0;
    for(const auto& p : mp1){
        ll val = p.first;
        auto it = mp2.lower_bound(m - val);
        it--;
        ans = max(ans, it->first + val);
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