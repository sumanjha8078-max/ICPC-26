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

void bfs(vector<vector<ll>>& adj, vector<ll>& vis, ll node){
    vis[node] = 1;
    queue<ll> q;
    q.push(node);
    while(!q.empty()){
        ll use = q.front();
        q.pop();
        for(const ll& t : adj[use]){
            if(!vis[t]){
                if(vis[use] == 1) vis[t] = 2;
                else vis[t] = 1;
                q.push(t);
            }
        }
    }
}

void solve(){ 
    ll n; cin >> n;
    vector<vector<ll>> adj(n+1);
    set<pair<ll,ll>> st;
    for(int i = 1 ; i < n ; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        st.insert({u, v});
        st.insert({v, u});
    }
    vector<ll> vis(n+1);
    bfs(adj, vis, 1);
    vector<ll> u1, v1;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == 1) u1.push_back(i);
        else v1.push_back(i);
    }
    if(u1.size() > v1.size()) swap(u1, v1);
    if(u1.size() == 1){
        vector<ll> ans1;
        vector<ll> fans1(n+1);
        ans1.push_back(u1[0]);
        for(const ll& t : v1) ans1.push_back(t);
        for(int i = 0 ; i < n ; i++){
            fans1[ans1[i]] = 2*(i+1);
        }
        for(int i = 1 ; i <= n ; i++){
            if(fans1[i] == 4) cout << 3 << " ";
            else cout << fans1[i] << " ";
        }
        cout << "\n";
        return;
    }
    ll x, y;
    for(int i = 0 ; i < u1.size() ; i++){
        for(int j = 0 ; j < v1.size() ; j++){
            if(st.find({u1[i], v1[j]}) == st.end()){
                x = u1[i], y = v1[j];
                break;
            }
        }
    }
    vector<ll> ans;
    for(int i = 0 ; i < u1.size() ; i++){
        if(u1[i] != x) ans.push_back(u1[i]);
    }
    ans.push_back(x);
    ans.push_back(y);
    for(int i = 0 ; i < v1.size() ; i++){
        if(v1[i] != y) ans.push_back(v1[i]);
    }
    vector<ll> fans(n+1);
    for(int i = 0 ; i < ans.size() ; i++){
        fans[ans[i]] = 2*(i+1);
    }
    for(int i = 1 ; i <= n ; i++) cout << fans[i] << " ";
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