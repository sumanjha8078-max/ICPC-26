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

ll func(vector<ll>& a, vector<ll>& b, ll mid){
    ll res = 0;
    for(const ll& t : a){
        res += max(0LL, mid - t);
    }
    for(const ll& t : b){
        res += max(0LL, t - mid);
    }
    return res;
}

void solve(){ 
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];
    ll mini = *min_element(a.begin(), a.end());
    ll maxi = *max_element(b.begin(), b.end());
    if(mini >= maxi){
        cout << 0 << "\n";
        return;
    }
    ll start = mini, end = maxi;
    ll ans = min(func(a, b, start), func(a, b, end));
    while(end - start > 2){
        ll use = (end - start)/3;
        ll mid1 = start + use, mid2 = end - use;
        ll fm1 = func(a, b, mid1), fm2 = func(a, b, mid2);
        if(fm1 > fm2){
            ans = min(fm2,ans);
            start = mid1;
        }
        else if(fm2 > fm1){
            ans = min(fm1, ans);
            end = mid2;
        }
        else{
            ans = min(min(fm1, fm2), ans);
            start = mid1;
            end = mid2;
        }
    }
    ans = min(min(ans, func(a, b, start+1)), min(func(a, b, start), func(a, b, end)));
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