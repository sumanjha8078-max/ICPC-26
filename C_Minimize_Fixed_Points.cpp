/*
    "The Last Dance"
    
*/

#define ll long long
#define mod (1000000007)

#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(){ 
    ll n; cin >> n;
    vector<ll> v(n+1); for(int i = 0 ; i <= n ; i++) v[i] = i;
    map<ll,ll> mp;
    for(int i = 2 ; i <= n ; i++) mp[i] = i;
    for(int i = 2 ; i <= n ; i++){
        if(v[i] != i) continue;
        ll val = v[i];
        if(val*2 <= n){
            mp[val] = mp[val*2];
            mp[val*2] = i;
            swap(v[i], v[mp[val]]);
        }
        else{
            for(ll j = 2 ; j <= sqrt(val) ; j++){
                if(val % j == 0){
                    mp[val] = mp[j];
                    mp[j] = i;
                    swap(v[i], v[mp[val]]);
                    break;
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++) cout << v[i] << " ";
    cout << "\n";
}

int main(){
    fast_io();
    ll t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}