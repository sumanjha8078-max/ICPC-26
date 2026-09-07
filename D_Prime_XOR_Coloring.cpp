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

void solve(){ 
    ll n; cin >> n;
    if(n <= 6){
        cout << (n)/2 + 1 << "\n";
        for(int i = 0 ; i < n ; i++){
            if(i == 0) cout << 1 << " ";
            else cout << (i+1)/2 + 1 << " ";
        }
        cout << "\n";
        return;
    }
    cout << 4 << "\n";
    for(int i = 1 ; i <= n ; i++){
        if(i % 4 == 0) cout << 1 << " ";
        else cout << i % 4 + 1 << " ";
    }
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